# ADR-001 · Application Types for ITC Club Hub

Version 1.0 · 2026-11-03 · Status: Proposing · Decider: Keo Vimeanrathbosba (Product Owner)

## Context

ITC Club Hub supports about 40 clubs and serves three groups with different devices and connectivity. Students browse and register for events on phones; organisers check students in at venues where Wi-Fi can be weak or overloaded; administrators approve clubs and review monthly activity on desktop PCs. The system must work for Android and iPhone users, keep check-in moving during busy events, and provide accurate reports. The course implements the domain logic in a C++ core with a CLI; the web and mobile interfaces are modelled rather than built this semester.

## User groups

| Group | Device | Where | Connectivity | How often | Must never fail |
|---|---|---|---|---|---|
| Students | Android or iPhone | Around campus and elsewhere | Usually mobile data; connection quality can vary | A few times a week | Finding events and seeing a truthful registration status; a student must not be registered twice or exceed event capacity. |
| Organisers | One or two phones | At the door of a room or hall | Wi-Fi may be weak or overloaded, especially during check-in | At events, including busy arrival periods | Recording each arrival without blocking on the network, and later resolving whether the check-in was accepted. |
| Administrators | Desktop PCs | Student affairs office | Office internet connection | Club approvals and monthly activity reports | Approving only eligible clubs and producing an accurate monthly report. |

## Options

**A. Native mobile apps:** separate Android and iOS apps for students and organisers, plus a web interface for administrators.

**B. PWA + responsive web:** one installable Progressive Web App (PWA) for students and organisers, with an offline check-in queue; the same responsive web app provides administrator screens on desktop.

**C. Responsive web app only:** one website for all three groups, used in a browser, with no installable offline check-in feature.

**D. Cross-platform mobile app + web admin:** one cross-platform app for students and organisers, plus a separate responsive web interface for administrators.

## Weighted comparison

Scores are from 1 (poor) to 5 (strong). Weighted points are score × criterion weight. Higher totals are better.

| Criterion (weight) | Why this weight | A. Native apps | B. PWA + web | C. Responsive web only | D. Cross-platform + web |
|---|---|---:|---:|---:|---:|
| Cost for our team in one semester (3) | High weight: the team must deliver the core and models within one semester. | 1 × 3 = 3 | 5 × 3 = 15 | 5 × 3 = 15 | 3 × 3 = 9 |
| Reach (3) | High weight: students use both Android and iPhone, while administrators use desktops. | 4 × 3 = 12 | 4 × 3 = 12 | 5 × 3 = 15 | 4 × 3 = 12 |
| Offline check-in at the door (3) | High weight: venue Wi-Fi may fail during a busy event, so organisers must keep recording arrivals. | 5 × 3 = 15 | 4 × 3 = 12 | 1 × 3 = 3 | 4 × 3 = 12 |
| Reminders (2) | Useful for students, but e-mail can provide a fallback if push reminders are unavailable. | 5 × 2 = 10 | 3 × 2 = 6 | 2 × 2 = 4 | 4 × 2 = 8 |
| Administrator approvals and monthly reports (2) | Administrators are a small group, but need accurate desktop views and reports. | 4 × 2 = 8 | 4 × 2 = 8 | 5 × 2 = 10 | 5 × 2 = 10 |
| **Total** |  | **3 + 12 + 15 + 10 + 8 = 48** | **15 + 12 + 12 + 6 + 8 = 53** | **15 + 15 + 3 + 4 + 10 = 47** | **9 + 12 + 12 + 8 + 10 = 51** |

## Deal-breaker check

**Deal-breaker:** organiser check-in must keep working when venue Wi-Fi is unavailable. Option B meets this by storing scans in a local PWA queue and synchronising them when the connection returns. The organiser sees that a scan was saved locally; the server later confirms or rejects it. The PWA must prevent duplicate uploads and show any rejected check-ins clearly. Option C, as scored, has no offline queue and fails this deal-breaker. If offline check-in cannot be implemented and reviewed, the team must revisit the choice before calling the ADR accepted.

## Decision

Choose **Option B: a PWA for students and organisers, with responsive administrator screens in the same web application**. In this course, the implemented C++ core will be called directly by the CLI. In a future deployed product, a server-side HTTP API would call the same C++ core and connect the web/PWA front ends to it.

## Consequences

### Positive

- One web codebase can serve phone and desktop users, which fits the team's one-semester scope.
- Organisers can queue check-ins locally during a network outage and sync them later.
- Students can access the service from Android and iPhone browsers without maintaining two separate native apps.

### Negative

- Offline check-ins need conflict handling, duplicate protection, and clear feedback when the server rejects a record.
- Browser support for installation and push notifications varies; some users may need to install the PWA, and e-mail remains the reminder fallback.
- A PWA still needs network access for current event lists, registration changes, and administrator reports.

## Rejected options

- **A. Native Android and iOS apps:** rejected because two mobile codebases plus the administrator web interface are too much to build and maintain in one semester.
- **C. Responsive web app only:** rejected because the selected option has no offline check-in queue and fails the venue connectivity deal-breaker.
- **D. Cross-platform mobile app + web admin:** rejected because it requires a separate mobile app and web interface, adding work without a clear advantage over one PWA and responsive web app.

## Review and decision log

The Product Owner will present this ADR to the teaching assistant or instructor for review. After that review, update the status here to **Accepted** with the acceptance date and add a corresponding entry to `lab01/decisions.md`.
