# Communication overhead · clubhub-ITC-4G (v1.0, 2026--)

## Paths

| Model                 | People n | Paths n(n-1)/2    | Minutes/week | Hours/week |
| --------------------- | -------- | ----------------- | ------------ | ---------- |
| (a) everyone + client | 6        | 6(6-1)/2=15       | 15x10 = 150  | 2.5        |
| (b) client via PO     | 6        | 5(5-1)/2 + 1 = 11 | 11x10 = 110  | 1.83       |

Assumption: 10 minutes per path per week, because each communication path requires time to exchange updates, clarify requirements, and resolve misunderstandings.
Team capacity: 5 members × 2 h = 10 h/week. 
-> model (a) costs 2.5 / 10 x 100 = 25% of weekly team capacity.
→ model (b) costs 1.83 / 10 × 100 = 18.3% of weekly team capacity.

## Our paths (model b)
```mermaid
flowchart LR
    KeoVimeanrathbosba --- Client
    KeoVimeanrathbosba --- SongVansak
    KeoVimeanrathbosba --- LorHengleap
    KeoVimeanrathbosba --- SreuVisal
    SreuVisal --- SongVansak
    SreuVisal --- LorHengleap
    SongVansak --- LorHengleap
```
## Two practices

1. 10-minute stand-up, three times a week. Each member briefly reports progress, blockers, and their next task. Bosba collects client-related questions and shares the answers with the team. This replaces scattered status updates with three short meetings, costing approximately 0.5 h/week in scheduled meeting time. We will keep updates brief and move detailed discussions to GitHub Issues.
2. 
3. GitHub Issues as the single source of truth. We record requirements, decisions, bugs, and task owners in GitHub Issues instead of repeatedly explaining the same information in private messages. This reduces the assumed cost per path from 10 to 6 minutes per week. Model (b) then costs 11 × 6 = 66 minutes, or 1.1 h/week. This saves approximately 0.73 h/week compared with the original model.

## A sixth member in week 11

With six team members and the client communicating only through the PO:

Path n(n-1)/2 = 6(6-1)/2 + 1 = 16

The overhead rises from 11 to 16 paths, an increase of 5/11 × 100 ≈ 45.5%. At 10 minutes per path, that is 160 minutes or 2.67 h/week.

Decision: We would not accept the sixth member in week 11 unless the additional person has a clearly defined role that provides enough benefit to justify the onboarding and coordination costs, consistent with Brooks's law.

## Reflection: the essential difficulty we expect first
Reflection

The essential difficulty that our team is most likely to encounter first is changeability in ITC Club Hub. As we navigate ITC Club Hub, it is completely expected of us to get confused especially with the rapid transformation demands from the client. For demonstration, the rules for importing club data may initially require only a club name and capacity. However, the client may want to add other fields such as category, meeting schedules and so on. These abrupt requests of change can affect the CSV format, validation rules, C++ classes, and tests. 

For the next four weeks, our team will be on guard and prepared with the rapid request of changes from the client by recording issues that lie in GitHub, while making sure we have the confirmations made by the Product Owner and the client. We will also work on our collaboration skills within our team ensuring that we communicate well from Product Owner to Scrum Masters to Developers. The quality of our work will improve as anticipated as we learn to work together.

# Signed Members Statement

- Song Vansak (Scrum Master): I will organize the short team check-in, focusing more on communication, progress, GitHub issues.
- Lor Hengleap (Developer 1): I expect to find more bugs than planned especially when integrating , so i will test each feature before adding to the system.
- Sreu Visal (Developer 2): I will test my code regularly, read error messages carefully, and fix problems as soon as they appear.
- Keo Vimeanrathbosba (Product Owner): I will be checking in with the client to make sure we can give them what they ask for and what they really want and work well with my team.