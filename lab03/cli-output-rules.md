# CLI output rules · ITC Club Hub
Version 0.1 · 2026-11-18 · Authors: Keo Vimeanrathbosba, Song Vansak, Lor Hengleap, Sreu Visal

These rules keep the Club Hub command-line interface understandable with colour disabled, keyboard-only input and assistive technology.

## 1. Never communicate status by colour alone

Bad:
```text
E-017  Git Workshop      (green background means registered)
```

Good:
```text
E-017  Git Workshop      [REGISTERED]
```

## 2. Honour `NO_COLOR` and `--no-color`

Bad:
```text
$ NO_COLOR=1 clubhub events
\x1b[32mE-017 [REGISTERED]\x1b[0m
```

Good:
```text
$ NO_COLOR=1 clubhub events
E-017 [REGISTERED]
$ clubhub --no-color events
E-017 [REGISTERED]
```

When the `NO_COLOR` environment variable exists or `--no-color` is supplied, omit ANSI colour codes from all output.

## 3. Keep the status word when colour is enabled

Bad:
```text
E-017  Git Workshop      \x1b[31m●\x1b[0m
```

Good:
```text
E-017  Git Workshop      \x1b[31m[CANCELLED]\x1b[0m
```

## 4. Explain errors and give a next step

Bad:
```text
ERR_CAP
```

Good:
```text
Error: cannot register for E-017: the event is full (40 of 40 seats).
Next step: clubhub waitlist E-017
```

## 5. Return a non-zero exit code when a command fails

Bad:
```text
$ clubhub register E-017
Error: cannot register: the event is full.
$ echo %ERRORLEVEL%
0
```

Good:
```text
$ clubhub register E-017
Error: cannot register: the event is full.
Next step: clubhub waitlist E-017
$ echo %ERRORLEVEL%
1
```

## 6. State the expected format in every prompt

Bad:
```text
Enter date:
```

Good:
```text
Enter event date and time (YYYY-MM-DD HH:MM, 24-hour time; example 2026-10-14 17:30):
```

## 7. Use unambiguous dates and times

Bad:
```text
Event starts 10/11/26 at 5:30.
```

Good:
```text
Event starts 2026-10-14 17:30 (local time).
```
