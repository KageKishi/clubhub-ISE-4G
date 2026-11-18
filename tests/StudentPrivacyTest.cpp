// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team Mekong, ITC Club Hub contributors
#include "clubhub/Student.h"

#include <gtest/gtest.h>

#include <stdexcept>

using clubhub::Student;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

TEST(StudentPrivacy, OptionalConsentsStartOff) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_FALSE(s.remindersByEmail());
}

TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("+855 12 345 678");
    EXPECT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "+855 12 345 678");

    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("01234abc56"), std::invalid_argument);
    EXPECT_THROW(s.giveSmsConsent("invalid-phone"), std::invalid_argument);
    EXPECT_THROW(s.giveSmsConsent(""), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(clubhub::maskId("1"), "*");
    EXPECT_EQ(clubhub::maskId("12"), "**");
    EXPECT_EQ(clubhub::maskId("123"), "***");
    EXPECT_EQ(clubhub::maskId(""), "");
    EXPECT_EQ(clubhub::maskId("1234"), "12*4");
    EXPECT_EQ(clubhub::maskId("e20990417"), "e2******7");
}
