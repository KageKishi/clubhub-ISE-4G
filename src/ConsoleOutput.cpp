// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team Mekong, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"

#include <cstdlib>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered:
            return "REGISTERED";
        case RegistrationStatus::Cancelled:
            return "CANCELLED";
        case RegistrationStatus::CheckedIn:
            return "CHECKED IN";
        case RegistrationStatus::Waitlisted:
            return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    return !noColorFlag && std::getenv("NO_COLOR") == nullptr;
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    const std::string label = "[" + std::string(statusLabel(s)) + "]";
    if (!colour) {
        return label;
    }

    const char* ansiCode = nullptr;
    switch (s) {
        case RegistrationStatus::Registered:
            ansiCode = "\x1b[32m";
            break;
        case RegistrationStatus::Cancelled:
            ansiCode = "\x1b[31m";
            break;
        case RegistrationStatus::CheckedIn:
            ansiCode = "\x1b[36m";
            break;
        case RegistrationStatus::Waitlisted:
            ansiCode = "\x1b[33m";
            break;
        default:
            return label;
    }

    return std::string(ansiCode) + label + "\x1b[0m";
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    return "Error: " + std::string(what) + ": " + std::string(why) +
           ".\nNext step: " + std::string(next);
}

}  // namespace clubhub
