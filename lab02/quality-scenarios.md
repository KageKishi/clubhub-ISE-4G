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



## QAS-06 · Portability · written by __

## Priorities
| Scenario | Business importance | Technical risk | Protects                       | First?  |
| -------- | ------------------- | -------------- | ------------------------------ | ------- |
| QAS-01   | High                | High           | All users / system reliability | **Yes** |
| QAS-02   | High                | Medium         | Event organizers & attendees   | **Yes** |