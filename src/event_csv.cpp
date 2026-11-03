#include "clubhub/event_csv.hpp"
#include <sstream>
#include <stdexcept>
#include <vector>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    
    if (!std::getline(in, line)) {
        return result; // Empty stream or only header missing
    }

    while (std::getline(in, line)) {
        ++lineNo;
        // Strip trailing '\r' if present (Windows line endings)
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        std::istringstream lineStream{line};
        std::string field;
        std::vector<std::string> fields;
        while (std::getline(lineStream, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() != 5) {
            result.errors.push_back({lineNo, "expected 5 fields, got " + std::to_string(fields.size())});
            continue;
        }

        try {
            int capacity = std::stoi(fields[4]);
            TimePoint start = parseTimePoint(fields[2]);
            result.events.emplace_back(fields[0], fields[1], start, fields[3], capacity);
        } catch (const std::exception& e) {
            result.errors.push_back({lineNo, e.what()});
        }
    }
    return result;
}

} // namespace clubhub