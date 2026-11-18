# Retention rules · ITC Club Hub
Version 1.0 · 2026-11-11 · Authors: Keo Vimeanrathbosba, Song Vansak, Lor Hengleap, Sreu Visal

| Field | Trigger | Action | Who or what runs it | How to verify |
|---|---|---|---|---|
| studentId | Student graduates or 1 year after account deactivation | delete | Admin command `clubhub purge --users`, scheduled monthly by system administrator | Query `data/students.csv` for the ID; returns 0 matches and deletion is logged in audit log. |
| name | Student graduates or 1 year after account deletion request | delete | Admin command `clubhub purge --users`, scheduled monthly by system administrator | Search `data/students.csv` for the name; verify no records match. |
| email | Account deletion request or graduation | delete | Admin command `clubhub purge --users`, scheduled monthly by system administrator | Query `data/students.csv` for email; verify no matching rows and delivery queues are empty. |
| phone | SMS consent withdrawal by student, account deletion, or graduation | delete | `Student::withdrawSmsConsent()` immediately; `clubhub purge --sms-consent` monthly for stale records | Verify `Student::phone()` returns `std::nullopt`; verify phone cell in `data/students.csv` is empty. |
| clubMemberships | Student leaves club, student graduates, or club dissolves | delete | `clubhub leave` command immediately; `clubhub purge --memberships` monthly | Inspect `data/memberships.csv`; confirm student ID is removed from target club membership rows. |
| attendance | End of active academic semester audit date | aggregate | Admin batch command `clubhub aggregate-attendance --term <semester>` | Verify individual check-in rows in `data/registrations.csv` are erased, and `data/club-stats.csv` contains only total headcount counts. |
