#include "clubhub/event.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace clubhub
{

    namespace
    {
        // Days since 1970-01-01, using the proleptic Gregorian calendar.
        long long daysFromCivil(int year, unsigned month, unsigned day)
        {
            year -= month <= 2;
            const int era = (year >= 0 ? year : year - 399) / 400;
            const unsigned yearOfEra = static_cast<unsigned>(year - era * 400);
            const unsigned dayOfYear =
                (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;
            const unsigned dayOfEra = yearOfEra * 365 + yearOfEra / 4 -
                                      yearOfEra / 100 + dayOfYear;
            return static_cast<long long>(era) * 146097 + dayOfEra - 719468;
        }

        void civilFromDays(long long days, int &year, unsigned &month,
                           unsigned &day)
        {
            days += 719468;
            const long long era = (days >= 0 ? days : days - 146096) / 146097;
            const unsigned dayOfEra =
                static_cast<unsigned>(days - era * 146097);
            const unsigned yearOfEra =
                (dayOfEra - dayOfEra / 1460 + dayOfEra / 36524 -
                 dayOfEra / 146096) /
                365;
            year = static_cast<int>(yearOfEra) + static_cast<int>(era) * 400;
            const unsigned dayOfYear =
                dayOfEra - (365 * yearOfEra + yearOfEra / 4 - yearOfEra / 100);
            const unsigned monthPart = (5 * dayOfYear + 2) / 153;
            day = dayOfYear - (153 * monthPart + 2) / 5 + 1;
            month = monthPart + (monthPart < 10 ? 3 : -9);
            year += month <= 2;
        }
    }

    Event::Event(std::string id, std::string title, TimePoint start,
                 std::string location, int capacity)
        : id_{std::move(id)}, title_{std::move(title)}, start_{start},
          location_{std::move(location)}, capacity_{capacity}
    {
        if (id_.empty())
        {
            throw std::invalid_argument{"id cannot be empty"};
        }
        if (title_.empty())
        {
            throw std::invalid_argument{"title cannot be empty"};
        }
        if (capacity_ <= 0)
        {
            throw std::invalid_argument{"capacity must be positive"};
        }
    }

    TimePoint parseTimePoint(const std::string &text)
    {
        using namespace std::chrono;
        std::istringstream in{text};
        int y{}, mo{}, d{}, h{}, mi{};
        char dash1{}, dash2{}, colon{};
        in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi;

        if (!in || dash1 != '-' || dash2 != '-' || colon != ':')
        {
            throw std::invalid_argument{"bad date-time '" + text + "'"};
        }

        char extra{};
        if (in >> extra)
        {
            throw std::invalid_argument{"bad date-time '" + text + "'"};
        }

        if (mo < 1 || mo > 12 || d < 1 || h < 0 || h > 23 || mi < 0 ||
            mi > 59)
        {
            throw std::invalid_argument{"bad date-time '" + text + "'"};
        }

        const auto nextMonth = mo == 12 ? 1 : mo + 1;
        const auto nextMonthYear = mo == 12 ? y + 1 : y;
        const auto daysInMonth =
            daysFromCivil(nextMonthYear, static_cast<unsigned>(nextMonth), 1) -
            daysFromCivil(y, static_cast<unsigned>(mo), 1);
        if (d > static_cast<int>(daysInMonth))
        {
            throw std::invalid_argument{"bad date-time '" + text + "'"};
        }

        const auto totalMinutes =
            daysFromCivil(y, static_cast<unsigned>(mo), static_cast<unsigned>(d)) *
                1440LL +
            h * 60LL + mi;
        return TimePoint{minutes{totalMinutes}};
    }

    std::string formatTimePoint(TimePoint t)
    {
        const auto totalMinutes = t.time_since_epoch().count();
        const auto days = totalMinutes >= 0
                              ? totalMinutes / 1440
                              : (totalMinutes - 1439) / 1440;
        const auto minutesOfDay = totalMinutes - days * 1440;
        int year{};
        unsigned month{}, day{};
        civilFromDays(days, year, month, day);
        std::ostringstream out;
        out << std::setfill('0') << year << '-' << std::setw(2) << month << '-'
            << std::setw(2) << day << ' ' << std::setw(2)
            << minutesOfDay / 60 << ':' << std::setw(2) << minutesOfDay % 60;
        return out.str();
    }

}