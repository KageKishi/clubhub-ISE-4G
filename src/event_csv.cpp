// src/event_csv.cpp
#include "clubhub/event_csv.hpp"

#include <sstream>
#include <stdexcept>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    std::getline(in, line);  // skip the header
    while (std::getline(in, line)) {
        ++lineNo;
        // TODO: strip a trailing '\r' (files edited on Windows)
        // TODO: split the line at ',' into fields; expect exactly 5
        // TODO: build an Event (parseTimePoint for the start, an int for
        //       the capacity) and add it to result.events; on
        //       std::invalid_argument add {lineNo, e.what()} to result.errors
    }
    return result;
}

} // namespace clubhub

