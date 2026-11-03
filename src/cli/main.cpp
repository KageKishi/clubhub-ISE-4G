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
    
    // Sort events by start time
    std::ranges::sort(events, {}, [](const clubhub::Event& event) {
        return event.start();
    });
    
    // Print aligned table header
    std::cout << std::left 
              << std::setw(18) << "START" 
              << std::setw(22) << "TITLE" 
              << std::setw(13) << "LOCATION" 
              << "CAPACITY\n";
              
    // Print each event row
    for (const auto& e : events) {
        std::cout << std::left 
                  << std::setw(18) << clubhub::formatTimePoint(e.start()) 
                  << std::setw(22) << e.title() 
                  << std::setw(13) << e.location() 
                  << e.capacity() << '\n';
    }
    
    std::cout << events.size() << " event(s)\n";
    
    // Print errors to std::cerr
    for (const auto& err : errors) {
        std::cerr << path << ":" << err.line << ": skipped: " << err.message << '\n';
    }
    
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