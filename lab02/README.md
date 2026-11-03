# Lab 02: ITC Club Hub — Architecture & Core Domain Model

This laboratory establishes the architectural blueprint and core C++ domain model for **ITC Club Hub**, separating business logic and data structures from user interfaces and file input/output operations.

---

## 1. System Architecture & Diagrams

### Context Diagram
Shows Club Hub as a single central node surrounded by four human roles and two external systems, detailing data flows.

![Context Diagram](context-diagram.png)

### Three-Tier Architecture Sketch
Breaks down the system into Presentation, Logic, and Data tiers, distinguishing between implemented C++ components and modelled front ends.

![Three-Tier Architecture Sketch](architecture.png)

---

## 2. Lab-02 File Inventory

| File Path                           | Description                                                                              | Main Author              |
| :---------------------------------- | :--------------------------------------------------------------------------------------- | :----------------------- |
| `lab02/app-classification.md`       | Classification and analysis of five everyday applications using chapter vocabulary       | Everyone                 |
| `lab02/app-quadrant.mmd`            | Mermaid quadrant chart charting applications by timing vs. availability demands          | Everyone                 |
| `lab02/adr-001-application-type.md` | Architecture Decision Record selecting the PWA/web hybrid approach via weighted criteria | Product Owner / Everyone |
| `lab02/quality-scenarios.md`        | Six complete quality attribute scenarios (QAS-01 to QAS-06) with prioritized trade-offs  | Scrum Master / Everyone  |
| `lab02/context-diagram.mmd`         | Mermaid source for the system context diagram                                            | Lor Hengleap             |
| `lab02/context-diagram.png`         | Exported image of the system context diagram                                             | Lor Hengleap             |
| `lab02/architecture.mmd`            | Mermaid source for the three-tier architecture sketch                                    | Lor Hengleap             |
| `lab02/architecture.png`            | Exported image of the three-tier architecture sketch                                     | Lor Hengleap             |
| `include/clubhub/event.hpp`         | Core Event class definition, time point types, and parsing declarations                  | Given                    |
| `include/clubhub/event_csv.hpp`     | CSV parser interface structures (`CsvError`, `EventLoadResult`)                          | Given                    |
| `src/event.cpp`                     | Event validation rules and strict ISO/local date-time string parsing/formatting          | Lor Hengleap             |
| `src/event_csv.cpp`                 | Robust line-by-line CSV parser with error recovery and line numbering                    | Lor Hengleap             |
| `src/cli/main.cpp`                  | Thin command-line interface handling sorting, console output, and errors                 | Lor Hengleap             |
| `CMakeLists.txt`                    | Build configuration defining `clubhub_core` library and `clubhub` executable             | Given                    |
| `data/events.csv`                   | Sample event dataset including valid records and intentional error row (`E004`)          | Given                    |
| `lab02/README.md`                   | Laboratory documentation, inventories, reuse logs, and change history                    | Lor Hengleap             |

---

## 3. Inputs Reused from Lab-01

| Reused File             | Commit Hash / Version | Purpose in Lab-02                                                                                                          |
| :---------------------- | :-------------------- | :------------------------------------------------------------------------------------------------------------------------- |
| `lab01/team-charter.md` | `3f8e2a1`             | Defines team collaboration roles, task-sharing, and peer-review workflow guidelines.                                       |
| `lab01/decisions.md`    | `7c4b1d9`             | Provides Architecture Decision Records (ADR-001) specifying web PWA/front-end choices referenced in the presentation tier. |

---

## 4. Change Log

| Date       | Version | Description                                                                                                      | Author   |
| :--------- | :------ | :--------------------------------------------------------------------------------------------------------------- | :------- |
| 2026-11-03 | 1.0     | Initial release: Context diagram, three-tier architecture sketch, C++ event core, CSV loader, and CLI front end. | Everyone |