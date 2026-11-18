// src/Student.cpp
// SPDX-License-Identifier: MIT
#include "clubhub/Student.h"

#include <cctype>
#include <stdexcept>

namespace clubhub {

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)),
      name_(std::move(name)),
      email_(std::move(email)),
      phone_(std::nullopt),
      remindByEmail_(false) {
    if (id_.empty()) {
        throw std::invalid_argument("Student ID cannot be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("Student name cannot be empty");
    }
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("Email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    if (phone.empty()) {
        throw std::invalid_argument("Phone number cannot be empty");
    }

    bool hasDigit = false;
    for (char c : phone) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
        } else if (c != '+' && c != ' ') {
            throw std::invalid_argument("Phone number contains invalid characters");
        }
    }

    if (!hasDigit) {
        throw std::invalid_argument("Phone number must contain at least one digit");
    }

    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

std::string maskId(std::string_view id) {
    if (id.size() <= 3) {
        return std::string(id.size(), '*');
    }
    const std::string prefix(id.substr(0, 2));
    const std::string middle(id.size() - 3, '*');
    const std::string suffix(id.substr(id.size() - 1, 1));
    return prefix + middle + suffix;
}

}  // namespace clubhub
