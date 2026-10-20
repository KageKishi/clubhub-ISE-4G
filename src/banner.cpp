#include "clubhub/banner.hpp"

#include <string>

#ifndef CLUBHUB_VERSION
#define CLUBHUB_VERSION "unknown"
#endif

namespace clubhub {

std::string banner()
{
    constexpr char rule[] = "========================================";

    return std::string{rule} + '\n' +
           "ITC Club Hub v" + CLUBHUB_VERSION + '\n' +
           "Team: " + kTeamName + '\n' +
           rule + '\n';
}

}  // namespace clubhub