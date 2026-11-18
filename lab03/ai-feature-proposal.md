# AI feature proposal: "Recommended for you"
Version 0.1 · 2026-11-18 · Authors: <Keo Vimeanrathbosba>

## 1 Problem and non-personalised baseline
The User problem
Students on campus everywhere are facing severe information overload because of the amount of club events, and school events shared daily on the Clubhub portal. Since there is too much information, students tend to overlook or miss the actual important events or opportunities that align with their interest.

The Non-personalised Baseline
Before introducing machine learning or behavioral tracking, we establish a robust, privacy-preserving baseline combining two simple rules:

"Popular This Week": Displays the top 5 most-booked campus-wide events based on total confirmed RSVPs in the current week.

"Events of My Clubs": Displays upcoming events exclusively from clubs where the student is an official registered member.

Why this matters: This baseline solves 60% of the discovery problem (trending campus life and enrolled club updates) instantly, predictably, and transparently without collecting behavioral history or creating personal recommendation profiles. Any proposed AI feature must justify its added complexity over this baseline.
## 2 Data needed
| Field                   | Source          | In inventory? | New purpose / consent? | Minimisation |
| ----------------------- | --------------- | ------------- | ---------------------- | ------------ |
| Event ID / Title / Date | Events Table    | Yes           | No (Core feature)      | None         |
| Club ID / Category      | Club Table      | Yes           | No (Core feature)      | None         |
| User Attendance History | Attendance Logs | Yes           | Yes (repurposing historical check-ins for preference profiling and collaborative filtering. Requires updated privacy policy consent.).    | Restricted to the past 6 months; older historical logs are anonymised or dropped. |
| Student Faculty / Major | Student Profiles| Yes           | Yes (used as a cold-start demographic prior for new users.) | Aggregated to faculty level only (Example, "Engineering" instead of exact degree code).      |
## 3 Bias risks
| Risk | Who is harmed | Mitigation | Fairness check (metric, threshold) |
| ---- | ------------- | ---------- | ---------------------------------- |
| Cold-Start Bias | First-year students, exchange students, and transfers who have no prior attendance logs. | Fall back to a blended cold-start model combining faculty-wide trending events and campus-wide popular events for a student's first 30 days. | Metric: Mean Click-Through Rate (CTR) disparity between students with less than 30 days tenure and returning students.<br>Threshold: Disparity must remain less than 5%. |
| Popularity Feedback Loop (Rich-Get-Richer) | Small, niche, or newly formed clubs whose events get buried beneath large, well-established clubs. | Enforce a mandatory 20% Exploration Quota (1 of the 5 slots) reserved for clubs with fewer than 20 active members. | Metric: Ratio of recommendation share for clubs with fewer than 20 members to their share of total published events.<br>Threshold: Ratio must be at least 0.80 (within 20% of proportional representation). |
| Attendance as a Proxy for Ability, Income, or Schedule | Commuters, working students, students with disabilities, or those unable to afford paid/off-campus events. | Exclude ticket price and attendance frequency volume from ranking weights; allow students to filter by accessibility, free entry, and preferred time windows. | Metric: Distribution of recommended events across free vs. paid tiers and accessible vs. non-accessible venues compared to overall event catalog.<br>Threshold: Free and accessible event recommendation shares must match or exceed their baseline catalog proportions (disparity less than 5%). |
| Departmental & Major Siloing | Students seeking interdisciplinary skills, cultural exchange, or social communities outside their academic faculty. | Apply an interdisciplinary diversity constraint capping same-faculty recommendations at 3 out of 5 slots. | Metric: Percentage of total recommended events originating outside a student's registered faculty.<br>Threshold: Maintained at 20% or higher across all active user feeds. |
## 4 Transparency
### Example: "Why am I seeing this?"

Event: University Photography Workshop

Why am I seeing this?

This event is recommended because:

- You previously attended photography-related club activities.
- You are a member of the Photography Club.
- The workshop is an upcoming event you have not attended before.

We use your club memberships and attendance from the last 12 months to suggest relevant events.

You can change your recommendation preferences or switch off personalised recommendations at any time in your profile settings.

### Ranking Inputs Published by the Clubs Office

The Clubs Office will publish the main ranking factors:

1. Previous attendance.
2. Club membership.
3. Upcoming event availability.
4. Event diversity.
5. Overall event popularity.

These factors explain how the system selects and ranks the five recommended events.
## 5 Opt-out design
### Default Setting: Opt-in (Off by Default)

Personalised recommendations should be off by default because the system uses students' personal attendance history and club membership information.

Students must actively agree before the system creates a personalised recommendation profile.

### Where the Switch Lives

Student Profile → Privacy Settings → Personalised Recommendations

Students can:

- Turn on personalised recommendations.
- Turn off personalised recommendations.
- Continue using non-personalised recommendations.
- View information about how their data is used.

### What Happens When Students Switch It Off?

1. The system immediately stops using attendance history for recommendations.
2. The derived recommendation profile is deleted within 24 hours.
3. Original attendance and club membership records remain in university systems for their normal purposes.
4. The student continues seeing popular events and events from their clubs.
5. The student can opt in again at any time.
### Mermaid Flowchart

```mermaid
flowchart TD
    A["Student Profile: Recommendations Setting"] --> B{"Personalised recommendations enabled?"}

    B -->|"Yes"| C["Use consented club membership and last 12 months of attendance"]
    C --> D["Generate five event recommendations"]
    D --> E["Display recommended events"]
    E --> F["Student can change preference"]

    B -->|"No"| G["Stop using personal attendance data"]
    G --> H["Delete derived profile within 24 hours"]
    H --> I["Display popular events and events from my clubs"]

    F --> J{"Student switches off?"}
    J -->|"Yes"| G
    J -->|"No"| E
```
## 6 Recommendation
Decision: GO WITH CONDITIONS

The "Recommended for You" feature should be developed in Sprint 2, but only after the non-personalised baseline has been available for one month.

### Conditions

1. Opt-in by default: Personalised recommendations must be off by default. Switching off must delete the derived student profile within 24 hours.

2. Limited data collection: Only use attendance from the last 12 months and club memberships. Do not use phone numbers, emails or free-text information.

3. Event diversity: At least 2 of the 5 recommendation slots must show events from clubs the student has never attended.

4. Small club fairness: Clubs with fewer than 20 members must receive at least 80% of their fair share of recommendations compared with their share of eligible events.

5. Transparency: Students must understand why events are recommended and how their data is used.

6. Fairness monitoring: The system must be checked every month. If fairness requirements are not achieved, the recommendation rules must be adjusted.

### Owner of the Fairness Check

The Clubs Office will be responsible for monitoring fairness after release.

The Clubs Office will:

- Review recommendation results every month.
- Check whether small clubs receive fair exposure.
- Monitor opportunities for new students.
- Investigate unfair recommendation patterns.
- Report problems and recommend improvements.

### Final Conclusion

The "Recommended for You" feature can help students discover activities that match their interests. However, personalisation also creates privacy, transparency and fairness risks.

Therefore, the project should receive conditional approval. The university should first establish a non-personalised baseline, obtain student consent, minimise personal data collection and conduct regular fairness checks.

If these conditions are satisfied, the feature can be introduced responsibly while ensuring fair opportunities for all students and clubs.