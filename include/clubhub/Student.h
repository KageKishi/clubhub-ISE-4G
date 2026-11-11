// include/clubhub/Student.h
// SPDX-License-Identifier: TODO (Task 3)
#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace clubhub {

// Stores only the fields allowed by lab03/data-inventory.md.
class Student {
public:
    // Throws std::invalid_argument for an empty id or name,
    // or an email without '@'.
    Student(std::string id, std::string name, std::string email);

    const std::string& id() const noexcept { return id_; }
    const std::string& name() const noexcept { return name_; }
    const std::string& email() const noexcept { return email_; }
    const std::optional<std::string>& phone() const noexcept {
        return phone_;
    }
    bool remindersByEmail() const noexcept { return remindByEmail_; }

    // Consent is explicit, separate and can be withdrawn.
    void giveSmsConsent(std::string phone);   // TODO: digits, '+', ' '
    void withdrawSmsConsent() noexcept;       // TODO: erase the number
    void setEmailReminders(bool on) noexcept { remindByEmail_ = on; }

    // Safe for logs: "Student{id=e2******7}", nothing else.
    std::string redacted() const;             // TODO

private:
    std::string id_;
    std::string name_;
    std::string email_;
    std::optional<std::string> phone_;        // only with SMS consent
    bool remindByEmail_ = false;              // opt-in: off by default
    // TODO: add a member ONLY if it has a Keep row in the inventory
};

// "e20990417" -> "e2******7"; 3 characters or fewer -> all '*'
std::string maskId(std::string_view id);      // TODO

}  // namespace clubhub