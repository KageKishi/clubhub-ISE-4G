// tests/StudentPrivacyTest.cpp
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

TEST(StudentPrivacy, OptionalConsentsStartOff) { /* TODO */ }
TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) { /* TODO */ }

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) { /* TODO */ }
TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) { /* TODO */ }