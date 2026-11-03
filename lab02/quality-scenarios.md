# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-11-03 · Team: clubhub-ISE-4G Reviewed by (Scrum Master): Song Vansak

## QAS-01 · Availability · written by Lor Hengleap
| Part             | Content                                                                                                                                  |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| Source           | external student user / club member                                                                                                      |
| Stimulus         | sudden spike of concurrent traffic during Friday 18:00 club registration opening                                                         |
| Environment      | Friday 18:00, registration peak load, 500 active concurrent users over campus Wi-Fi / mobile data                                        |
| Artifact         | Web Server / API Gateway and Session Manager                                                                                             |
| Response         | system automatically scales resources or gracefully queues requests without crashing; service recovers within 30 seconds if a node fails |
| Response measure | 99.9% uptime during peak hours, allowing a maximum of 43.8 minutes of unscheduled downtime per month; error rate under 1%                |

## QAS-02 · Performance of check-in at the door · written by Lor Hengleap
| Part             | Content                                                                                                                      |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| Source           | club event organizer / door checker                                                                                          |
| Stimulus         | scans student digital membership QR code at the entrance during high-arrival rush                                            |
| Environment      | event entrance, mobile network latency under 150 ms, 200 arrivals entering within 10 minutes                                 |
| Artifact         | CheckInService, Database attendance record table                                                                             |
| Response         | system validates QR code, updates attendance status to "Present", and confirms successful check-in on the organizer's screen |
| Response measure | response time $\le 1.5$ seconds per scan from tap to confirmation UI update                                                  |



## QAS-05 · Modifiability · written by Sreu Visal
| Part             | Content                                                                                                                                             |
| ---------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| Source           | a developer of the team                                                                                                                             |
| Stimulus         | adds the waiting list (a Should feature): a full event puts new registrations in status Waitlisted                                                  |
| Environment      | design time, after Sprint 1, core already tested                                                                                                    |
| Artifact         | RegistrationService, Registration (include/clubhub/)                                                                                                |
| Response         | change made in the core only; the CLI gains one column; existing behaviour unchanged                                                                |
| Response measure | done in $\le 2$ person-days; $\le 4$ files changed under include/ and src/; 0 changes in src/cli/ other than display; all existing tests still pass |

## QAS-06 · Portability · written by Sreu Visal
| Part             | Content                                                                                                                                                          |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Source           | front-end development team                                                                                                                                       |
| Stimulus         | deploys the web application across different target mobile operating systems and modern web browsers                                                             |
| Environment      | production release testing across Google Chrome (Android/Windows), Safari (iOS/macOS), and Firefox                                                               |
| Artifact         | responsive CSS layout framework and client-side JavaScript bundle                                                                                                |
| Response         | UI elements render correctly, touch interactions function without misalignment, and core features operate identically across all targeted platforms              |
| Response measure | 100% layout compatibility verified on iOS Safari (v16+) and Android Chrome (v110+); zero critical rendering bugs reported in automated cross-browser test suites |

## Priorities
| Scenario | Business importance | Technical risk | Protects                       | First?  |
| -------- | ------------------- | -------------- | ------------------------------ | ------- |
| QAS-01   | High                | High           | All users / system reliability | **Yes** |
| QAS-02   | High                | Medium         | Event organizers & attendees   | **Yes** |
| QAS-05   | Medium              | Medium         | Development team               | **No**  |
| QAS-06   | Medium              | Low            | Cross-platform users           | **No**  |