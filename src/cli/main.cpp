// src/cli/main.cpp: the only place that talks to the user
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "clubhub/event.hpp"
#include "clubhub/event_csv.hpp"

namespace {

int listEvents(const std::string& path) {
    std::ifstream file{path};
    if (!file) {
        std::cerr << "error: cannot open " << path << '\n';
        return 2;
    }
    auto [events, errors] = clubhub::loadEventsCsv(file);
    // TODO: sort events by start time (std::ranges::sort, projection
    //       &clubhub::Event::start)
    // TODO: print a header line and one aligned row per event
    //       (std::left, std::setw; formatTimePoint for the start)
    // TODO: print "<n> event(s)", then every error to std::cerr as
    //       <path>:<line>: skipped: <message>
    return errors.empty() ? 0 : 1;
}

void printUsage() {
    std::cerr << "usage: clubhub list-events [events.csv]\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }
    const std::string command{argv[1]};
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "data/events.csv");
    }
    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}