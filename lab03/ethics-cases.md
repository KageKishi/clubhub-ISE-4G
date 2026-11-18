# Ethics case analyses · ITC Club Hub
Version 1.1 · 2026-11-18 · Leads: A = Keo Vimeanrathbosba, B = Sreu Visal · Reviewers: Song Vansak, Lor Hengleap

## Scenario A: “Just a small report”

| Step | Analysis |
|------|----------|
| 1 Facts | **Known:** The Robotics Club leader wants an identifiable list of students who attended other clubs’ events, to recruit them. The leader says the report would be leader-only and the clubs office “won’t mind.” The inventory limits club leaders and organisers to attendance for their own events; it lists capacity planning and activity audits as purposes. **Find out:** Has the clubs office, as data controller, approved any cross-club use? Were students told about recruitment use? What non-identifying result would meet the request? |
| 2 Stakeholders and harms | Students may be profiled or contacted based on attendance they expected to remain within another club’s event, lose control over their data, or feel pressured to join. Other clubs may lose trust or face unfair recruitment. The requesting leader could receive data without authority. The clubs office and team could lose student trust and fail their privacy commitments. |
| 3 Codes, law, policy | IEEE-CS/ACM SE Code 3.12 requires respect for privacy; 3.13 limits data use to accurate data obtained ethically and lawfully and used as authorized. ACM 1.6 requires respect for privacy, including purpose limits. GDPR Article 5(1)(b) is purpose limitation and 5(1)(c) is data minimisation; these are course design references. [SE Code](https://www.computer.org/education/code-of-ethics) · [ACM Code](https://acm.org/binaries/content/assets/about/acm-code-of-ethics-and-professional-conduct.pdf) · [GDPR Article 5](https://eur-lex.europa.eu/legal-content/EN/TXT/?uri=CELEX%3A32016R0679) |
| 4 Options | (a) Build the identifiable cross-club report as requested. (b) Decline it and keep leaders’ individual attendance access to their own club events. (c) Ask the clubs office to review a cross-club aggregate for planning that cannot identify students; do not use it for targeted recruitment. (d) Explore a separate, voluntary recruitment opt-in with a clear notice and withdrawal path, only after controller approval. |
| 5 Tests | **(a)** Harm: high profiling and unwanted contact; rights: fails purpose and authorization checks; fairness: gives one club an advantage using others’ event data; publicity: students and the office could reasonably see it as covert tracking. **(b)** Harm: low privacy harm, though the leader loses one recruitment channel; rights: preserves the current purpose and access boundary; fairness: treats clubs consistently; publicity: the decision is easy to explain. **(c)** Harm: low if small groups cannot be singled out; rights: proceed only after controller confirms a compatible purpose; fairness: disclose aggregate limits so large clubs are not misrepresented; publicity: explain the review and aggregation openly. **(d)** Harm: lower but consent pressure remains possible; rights: pass only with a separate, optional, revocable choice; fairness: offer the same choice to every student and club; publicity: disclose the exact data and audience. |
| 6 Decision and action | Reject option (a). Keep identifiable attendance limited to the student, authorised event team for its own event, and the clubs office for its stated duties. Offer option (b) now and ask the clubs office whether it wants to assess option (c). Do not promise or build a recruitment report before that review. |
| 7 Reflection | A “leaders-only” screen does not make a new data purpose appropriate. Authorization must be enforced where the report query runs, not left to a user interface or a requester’s relationship with the office. |

**Message draft to the Robotics Club leader (not sent; 75 words):**

Thanks for the recruitment idea. Our current attendance rules let club leaders see attendance for their own events, and use attendance for capacity planning. A list of students at other clubs’ events would use their individual records for a new purpose without confirmed approval or notice. We can’t build that report as requested. I can ask the clubs office to review a non-identifying aggregate alternative, or discuss a separate opt-in feature with the Product Owner.

**Preventive change:** Enforce club scope in the report service: a club leader can query individual attendance only for that club’s events. Any approved cross-club report is aggregate-only and must not identify students. **Issue:** draft A below; issue number pending publication.

### GitHub issue draft A

**Title:** Restrict club-leader attendance reports to their own events
**Label:** `ethics`
**Status:** Draft; add the repository label and approve publication before filing.

**Body:**

Club leaders should only see individual attendance for events managed by their own club. A cross-club recruitment list would expose students’ attendance history outside the current purpose and access rules.

**Proposed change:** Enforce club and event scope in the service layer. Do not expose individual cross-club attendance to club leaders. Any cross-club report approved by the clubs office must be aggregate-only and must not single out students.

**Acceptance criteria:**
- A leader can retrieve attendance for an authorised event in their own club.
- A leader cannot retrieve another club’s attendee list, including by calling the service directly.
- Tests cover both allowed and denied access paths.
- Any approved office-level aggregate contains no student identifiers and cannot identify a small group.

## Scenario B: “Don’t mention it in the demo”

| Step | Analysis |
|------|----------|
| 1 Facts | **Known:** A developer found that cancellations inside the 24-hour window are accepted and the monthly report counts cancelled registrations as attendance. The Sprint 1 review is in two days. The Scrum Master asks the team to hide both defects and fix them in Sprint 2. **Find out:** Is the exact 24-hour boundary inclusive or exclusive? Does the report currently count only check-ins or all registrations? Which demo item can be dropped if the fixes need more time? |
| 2 Stakeholders and harms | Students may see incorrect attendance or be unable to rely on the cancellation rule. Club leaders and the clubs office may plan using false totals. The client may make decisions from a misleading demo. The developer and team face pressure to conceal a known defect, damaging trust and making later correction harder. |
| 3 Codes, law, policy | IEEE-CS/ACM SE Code 1.03 calls for software to meet specifications and pass appropriate tests; 3.08 calls for adequate testing; 6.08 assigns responsibility for detecting, correcting and reporting errors; 6.12 says to raise significant code violations with the people involved. ACM 1.3 requires honest disclosure of material problems and 2.5 calls for thorough impact evaluation. GDPR Article 5(1)(d) is accuracy and 5(1)(a) is fairness and transparency; these are course design references. [SE Code](https://www.computer.org/education/code-of-ethics) · [ACM Code](https://acm.org/binaries/content/assets/about/acm-code-of-ethics-and-professional-conduct.pdf) · [GDPR Article 5](https://eur-lex.europa.eu/legal-content/EN/TXT/?uri=CELEX%3A32016R0679) |
| 4 Options | (a) Stay silent, demo both features as if correct, and defer fixes to Sprint 2. (b) Postpone the whole review until both defects are fixed. (c) Demo on schedule, disclose both defects in a “known issues” section, avoid presenting affected figures as reliable, and give a fix date. (d) Fix both within two days and drop another demo item, but only if the regression tests pass before the review; otherwise use option (c). |
| 5 Tests | **(a)** Harm: high because users may rely on false rules and counts; rights: fails accuracy and honest disclosure; fairness: students and clubs receive misleading treatment; publicity: the client would feel deceived on discovery. **(b)** Harm: prevents reliance but delays useful feedback; rights: honest; fairness: neutral if all features are postponed; publicity: defensible, though it hides the team’s actual progress. **(c)** Harm: residual risk, reduced by labelling affected output and not using it for decisions; rights: passes through disclosure and correction plan; fairness: all reviewers get the same warning; publicity: honest and explainable. **(d)** Harm: lowest if both fixes and tests are complete; rights: passes when verified; fairness: preserve equal rules and accurate reporting; publicity: explain the scope change and tested fix. If tests are not green, revert to (c). |
| 6 Decision and action | Do not conceal the defects. Sreu raises them with Song immediately; Song and the Product Owner put them on the review agenda. Attempt option (d): enforce the 24-hour cutoff, count only checked-in registrations as attendance, and run regression tests. If either fix is unverified by the review, use option (c), state the known issues and fix date, and do not present the affected report as accurate. |
| 7 Reflection | The time pressure exposed missing regression tests and a review process without a clear known-issues section. Accurate status reporting protects the client’s ability to judge the product and helps the team choose work based on evidence. |

**Message draft to Song Vansak and Keo Vimeanrathbosba (not sent; 88 words):**

Hi Song and Keo — I found two Sprint 1 defects: the system accepts cancellations inside the 24-hour cutoff, and the monthly report counts cancelled registrations as attendance. Both can mislead students and the clubs office. I recommend regression tests and fixes before the review only if they pass by then, dropping a lower-priority demo item if needed. Otherwise, let’s demo with a clear known-issues note and fix date. Please put both defects on the review agenda; I won’t describe the report as accurate until it is corrected.

**Preventive change:** Add regression tests for the cancellation cutoff and monthly attendance aggregation. Confirm the exact behavior at precisely 24 hours with the Product Owner; count only checked-in records as attendance. **Issue:** draft B below; issue number pending publication.

### GitHub issue draft B

**Title:** Enforce the 24-hour cancellation cutoff and exclude cancelled registrations from attendance
**Label:** `ethics`
**Status:** Draft; add the repository label and approve publication before filing.

**Body:**

Two defects can mislead students and the clubs office: cancellation requests inside the 24-hour window are accepted, and cancelled registrations are counted as attendance in the monthly report.

**Proposed change:** Enforce the cancellation cutoff in the registration service and ensure attendance aggregates count only checked-in registrations. Confirm with the Product Owner whether cancellation is allowed at exactly 24 hours before fixing the boundary behavior.

**Acceptance criteria:**
- Regression tests show cancellations outside the cutoff are accepted and requests inside it are rejected.
- The exact 24-hour boundary follows the Product Owner’s confirmed rule and has a test.
- Cancelled and merely registered records are excluded from attendance totals; checked-in records are counted.
- Monthly report tests cover cancellation, registration and check-in states.
