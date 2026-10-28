#include "clubhub/event.hpp"

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace clubhub {

Event::Event(std::string id, std::string title, TimePoint start,
             std::string location, int capacity)
    : id_{std::move(id)}, title_{std::move(title)}, start_{start},
      location_{std::move(location)}, capacity_{capacity} {
    // TODO: throw std::invalid_argument when id_ or title_ is empty
    // TODO: throw std::invalid_argument when capacity_ <= 0
}

TimePoint parseTimePoint(const std::string& text) {
    using namespace std::chrono;
    std::istringstream in{text};
    int y{}, mo{}, d{}, h{}, mi{};
    char dash1{}, dash2{}, colon{};
    in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi;
    const year_month_day date{year{y}, month{static_cast<unsigned>(mo)},
                              day{static_cast<unsigned>(d)}};
    // TODO: throw std::invalid_argument{"bad date-time '" + text + "'"}
    //       unless the stream is good, the separators are '-', '-', ':',
    //       nothing follows, date.ok(), 0 <= h <= 23 and 0 <= mi <= 59
    return sys_days{date} + hours{h} + minutes{mi};
}

// Given: TimePoint -> "2026-10-14 14:00"
std::string formatTimePoint(TimePoint t) {
    using namespace std::chrono;
    const auto midnight = floor<days>(t);
    const year_month_day date{midnight};
    const hh_mm_ss time{t - midnight};
    std::ostringstream out;
    out << std::setfill('0') << static_cast<int>(date.year()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
        << std::setw(2) << time.hours().count() << ':'
        << std::setw(2) << time.minutes().count();
    return out.str();
}

} // namespace clubhub