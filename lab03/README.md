# ISE
# ITC Club Hub · clubhub-ISE-4G (v0.1.0, 10/27/2026)

## Members and roles

| Member              | GitHub              | Role (Sprint 1) | Shared hat       |
| ------------------- | ------------------- | --------------- | ---------------- |
| Keo Vimeanrathbosba | @keovimeanrathbosba | Product Owner   | Business-Analyst |
| Song Vansak         | songvansak19        | Scrum Master    | Organizer        |
| Lor Hengleap        | KageKishi           | Developer       | DevOps           |
| Sreu Visal          | visal-rg            | Developer       | Tester           |

## Task status

| Task                                 | Status   | Deliverables                                                                                                                                                     |
| ------------------------------------ | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1 · Data inventory                   | Complete | Data fields, purposes, access, retention, minimisation decisions and personal-data copy rules.                                                                   |
| 2 · Privacy implementation           | Complete | Privacy notice, consent flow, retention rules, `Student` helper and privacy tests.                                                                               |
| 3 · Licence and notices              | Complete | MIT project licence, SPDX headers and third-party notices.                                                                                                       |
| 4 · Accessibility and console output | Complete | WCAG checklist, CLI output rules, `ConsoleOutput` helper and tests.                                                                                              |
| 5 · Ethics cases and change record   | Complete | Seven-step analyses for both cases, unsent message drafts and two GitHub issue drafts. Posting the issues and publishing the PR remain subject to user approval. |
| Optional · AI recommender challenge  | Complete | The optional challenge was not attempted. The existing proposal file is inventoried below for completeness.                                                      |

## Lab 03 file inventory

| File                               | Task     | Status / purpose                                                                                                                       |
| ---------------------------------- | -------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| `lab03/README.md`                  | 1–5      | This inventory, status, inputs, change log and client questions.                                                                       |
| `lab03/data-inventory.md`          | 1        | Data inventory, minimisation decisions and copy-handling rules.                                                                        |
| `lab03/privacy-notice.md`          | 2        | Student-facing privacy notice.                                                                                                         |
| `lab03/consent-flow.mmd`           | 2        | Consent and phone-field lifecycle flow.                                                                                                |
| `lab03/retention-rules.md`         | 2        | Retention triggers, actions and verification steps.                                                                                    |
| `include/clubhub/Student.h`        | 2        | Student privacy helper interface.                                                                                                      |
| `src/Student.cpp`                  | 2        | Student privacy helper implementation.                                                                                                 |
| `tests/StudentPrivacyTest.cpp`     | 2        | Student privacy tests.                                                                                                                 |
| `lab03/licence-decision.md`        | 3        | Project licence decision.                                                                                                              |
| `LICENSE`                          | 3        | MIT licence text.                                                                                                                      |
| `THIRD_PARTY_NOTICES.md`           | 3        | Third-party dependency and licence notices.                                                                                            |
| `licenses/googletest-LICENSE.txt`  | 3        | GoogleTest licence copy.                                                                                                               |
| `lab03/accessibility-checklist.md` | 4        | WCAG checklist and screen review.                                                                                                      |
| `lab03/cli-output-rules.md`        | 4        | CLI status, error, prompt and date output rules.                                                                                       |
| `include/clubhub/ConsoleOutput.h`  | 4        | Console output helper interface.                                                                                                       |
| `src/ConsoleOutput.cpp`            | 4        | Console output formatting implementation.                                                                                              |
| `tests/ConsoleOutputTest.cpp`      | 4        | Console output tests.                                                                                                                  |
| `CMakeLists.txt`                   | 2, 4     | Build and test wiring for both helpers.                                                                                                |
| `.gitignore`                       | 4        | Ignores build and generated test output.                                                                                               |
| `lab03/ethics-cases.md`            | 5        | Seven-step analyses, unsent messages, preventive changes and issue drafts A and B. Issue numbers are pending approval and publication. |
| `lab03/ai-feature-proposal.md`     | Optional | Existing optional proposal; no recommender challenge work was done.                                                                    |

## Inputs reused
| Input            | File                           | Version / commit |
| ---------------- | ------------------------------ | ---------------- |
| Team charter     | lab01/team-charter.md          | a9d505f          |
| Decision         | lab01/decisions.md             | f337432          |
| Application type | lab02/adr-001-application-type | a5b74f4          |

## Change log

| Date       | Change                                                                                     | Lead / author                                           | Review                    |
| ---------- | ------------------------------------------------------------------------------------------ | ------------------------------------------------------- | ------------------------- |
| 2026-11-18 | Lab 03 Task 5: ethics case analyses, unsent messages, preventive changes and issue drafts. | Scenario A: Keo Vimeanrathbosba; Scenario B: Sreu Visal | Song Vansak; Lor Hengleap |
| 2026-11-18 | Lab 03 Task 4: accessibility review and console output.                                    | Team                                                    | Song Vansak               |
| 2026-11-18 | Lab 03 Task 3: licence, SPDX headers and third-party notices.                              | Lor Hengleap                                            | Team                      |
| 2026-11-18 | Lab 03 Task 2: `Student` helper, privacy notice and retention.                             | Lor Hengleap                                            | Team                      |
| 2026-11-11 | Lab 03 Task 1: data inventory, copy rules and phone lifecycle.                             | Lor Hengleap                                            | Team                      |

## Client questions

- Has the clubs office approved any cross-club attendance use? If it approves a planning aggregate, what minimum group size and access role should apply?
- Is recruitment use permitted only through a separate voluntary opt-in, and what notice and withdrawal process should students receive?
- At exactly 24 hours before an event, is cancellation allowed or inside the cutoff?
- Should monthly attendance totals include only registrations marked `CheckedIn`? Confirm how cancelled, registered and other states should be counted.