// SPDX-License-Identifier: MIT
// Copyright (c) 2026 clubhub-ISE-4G, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <gtest/gtest.h>

#include <cstdlib>
#include <optional>
#include <string>

#if defined(_WIN32)
#include <stdlib.h>
#endif

namespace {

class ScopedNoColorEnvironment {
public:
    ScopedNoColorEnvironment() {
        if (const char* value = std::getenv("NO_COLOR")) {
            previous_ = value;
        }
        clear();
    }

    ~ScopedNoColorEnvironment() {
        if (previous_) {
            set(previous_->c_str());
        } else {
            clear();
        }
    }

    void enable() { set("1"); }

private:
    static void set(const char* value) {
#if defined(_WIN32)
        _putenv_s("NO_COLOR", value);
#else
        setenv("NO_COLOR", value, 1);
#endif
    }

    static void clear() {
#if defined(_WIN32)
        _putenv_s("NO_COLOR", "");
#else
        unsetenv("NO_COLOR");
#endif
    }

    std::optional<std::string> previous_;
};

}  // namespace

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(clubhub::formatStatus(clubhub::RegistrationStatus::Cancelled,
                                    false),
              "[CANCELLED]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheStatusWord) {
    const std::string formatted = clubhub::formatStatus(
        clubhub::RegistrationStatus::Cancelled, true);

    EXPECT_NE(formatted.find("[CANCELLED]"), std::string::npos);
    EXPECT_NE(formatted.find("\x1b[31m"), std::string::npos);
    EXPECT_NE(formatted.find("\x1b[0m"), std::string::npos);
}

TEST(ConsoleOutput, UnknownStatusUsesReadableFallback) {
    const auto unknown = static_cast<clubhub::RegistrationStatus>(255);
    EXPECT_EQ(clubhub::statusLabel(unknown), "UNKNOWN");
    EXPECT_EQ(clubhub::formatStatus(unknown, true), "[UNKNOWN]");
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    EXPECT_EQ(clubhub::formatError("cannot register for E-017",
                                   "the event is full (40 of 40 seats)",
                                   "clubhub waitlist E-017"),
              "Error: cannot register for E-017: the event is full (40 of 40 "
              "seats).\nNext step: clubhub waitlist E-017");
}

TEST(ConsoleOutput, ColourCanBeDisabledByFlagOrEnvironment) {
    ScopedNoColorEnvironment noColor;
    EXPECT_TRUE(clubhub::colourEnabled(false));
    EXPECT_FALSE(clubhub::colourEnabled(true));
    EXPECT_EQ(clubhub::formatStatus(clubhub::RegistrationStatus::Cancelled,
                                    clubhub::colourEnabled(true)),
              "[CANCELLED]");

    noColor.enable();
    EXPECT_FALSE(clubhub::colourEnabled(false));
    EXPECT_EQ(clubhub::formatStatus(clubhub::RegistrationStatus::Cancelled,
                                    clubhub::colourEnabled(false)),
              "[CANCELLED]");
}
