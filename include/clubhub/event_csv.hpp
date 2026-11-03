// include/clubhub/event_csv.hpp
#pragma once
#include <istream>
#include <string>
#include <vector>

#include "clubhub/event.hpp"

namespace clubhub {

struct CsvError {
    int line;
    std::string message;
};

struct EventLoadResult {
    std::vector<Event> events;
    std::vector<CsvError> errors;
};

// Reads "id,title,start,location,capacity" rows after one header line.
// A bad row goes to errors; the good rows are still returned.
EventLoadResult loadEventsCsv(std::istream& in);

} // namespace clubhub