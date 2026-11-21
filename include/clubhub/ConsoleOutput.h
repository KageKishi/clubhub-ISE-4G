// SPDX-License-Identifier: MIT
// Copyright (c) 2026 clubhub-ISE-4G, ITC Club Hub contributors
#pragma once

#include <string>
#include <string_view>

namespace clubhub {


enum class RegistrationStatus { Registered, Cancelled, CheckedIn, Waitlisted };


std::string_view statusLabel(RegistrationStatus s);


bool colourEnabled(bool noColorFlag);


std::string formatStatus(RegistrationStatus s, bool colour);


std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next);

}  // namespace clubhub
