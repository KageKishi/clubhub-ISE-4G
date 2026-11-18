# Accessibility checklist · ITC Club Hub
Target: WCAG 2.2 level AA · Version 0.2 · 2026-11-18 · Authors: Keo Vimeanrathbosba, Song Vansak, Lor Hengleap, Sreu Visal

This is a design checklist for the planned web and mobile interfaces. It is not a claim that an implemented interface has already passed an accessibility audit. The checklist uses all four POUR principles and includes the six WCAG 2.2 success criteria named in the lab.

## WCAG 2.2 success criteria

| SC | Name | Level | Principle | Screen | How we meet it | How we test it |
|----|------|-------|-----------|--------|----------------|----------------|
| 1.1.1 | Non-text Content | A | Perceivable | Event list | Give informative event images text alternatives; mark decorative images as decorative. | Inspect image alternatives with a screen reader and the accessibility tree. |
| 1.3.1 | Info and Relationships | A | Perceivable | Event list and registration form | Use headings for event titles, labels for fields, and programmatic groups for related controls. | Check headings, labels and groups in the accessibility tree. |
| 1.4.3 | Contrast (Minimum) | AA | Perceivable | Both | Use the measured text and link colours below; do not rely on pale text. | Check each foreground/background pair in WebAIM Contrast Checker. |
| 1.4.11 | Non-text Contrast | AA | Perceivable | Registration form | Give input borders, selected controls, and focus indicators at least 3:1 contrast against adjacent colours. | Measure component and focus-indicator colours with WebAIM. |
| 2.1.1 | Keyboard | A | Operable | Both | Make filters, event actions, form fields and submit controls usable by keyboard. | Complete browsing, selection and registration using Tab, Enter, Space and arrow keys. |
| 2.4.7 | Focus Visible | AA | Operable | Both | Show a clear focus outline on every keyboard-operable control. | Tab through both screens and confirm the focused control is always visible. |
| 2.4.11 | Focus Not Obscured (Minimum) | AA | Operable | Registration form | Keep focused fields and buttons from being entirely hidden by sticky headers, footers or dialogs. | Keyboard-test the page at narrow and wide viewport sizes. |
| 2.5.7 | Dragging Movements | AA | Operable | Event list | Provide buttons or a select control for any action that could otherwise require dragging. | Use the action with a single click or tap and no dragging. |
| 2.5.8 | Target Size (Minimum) | AA | Operable | Registration form | Make pointer targets at least 24 by 24 CSS pixels or meet a documented spacing exception; aim for 44 by 44 pixels for touch controls. | Measure controls and spacing in browser developer tools. |
| 3.2.6 | Consistent Help | A | Understandable | Both | Keep repeated help links and contact options in the same relative location. | Compare help placement on the event list and registration form. |
| 3.3.7 | Redundant Entry | A | Understandable | Registration form | Reuse values already entered or available to the student instead of asking for them again in the same process. | Walk through registration and check that no value must be re-entered. |
| 3.3.8 | Accessible Authentication (Minimum) | AA | Understandable | Registration form / sign-in step | If authentication is required, allow paste and password-manager autofill and avoid memory puzzles. | Test sign-in with paste and a password manager; confirm no cognitive test is required. |
| 4.1.2 | Name, Role, Value | A | Robust | Event list | Give each event action an accessible name, role and state, including filter and registration controls. | Inspect each interactive control with the accessibility tree and a screen reader. |

The six WCAG 2.2 additions required by the lab are 2.4.11, 2.5.7, 2.5.8, 3.2.6, 3.3.7 and 3.3.8. Criterion names and levels follow the [W3C WCAG 2.2 Recommendation](https://www.w3.org/TR/WCAG22/).

## Screen design decisions

| Screen | Design decisions | How we test them |
|--------|------------------|------------------|
| Event list | Use a heading for each event and readable date, time and location text; show status words such as “Full” alongside any colour; make filters and registration actions keyboard-operable with visible focus and adequately sized targets. | Navigate by headings and with a keyboard; view in greyscale; inspect target dimensions and focus visibility. |
| Registration form | Associate a visible label and format hint with every field; show an error summary and field-level explanation without colour alone, while preserving entered values; support paste and autofill for authentication and use generously sized, spaced controls. | Check labels and errors with a screen reader; submit invalid and valid examples; test paste/autofill; measure targets and keyboard focus. |

## Contrast measurements

Measured with the [WebAIM Contrast Checker](https://webaim.org/resources/contrastchecker/). WCAG AA needs at least 4.5:1 for normal text and 3:1 for large text and user-interface components.

| Foreground | Background | Ratio | Use and result |
|------------|------------|-------|----------------|
| Navy `#17324D` | White `#FFFFFF` | 13.12:1 | Body text on white; passes normal-text AA and AAA. |
| Navy `#17324D` | Pale blue `#F2F7FB` | 12.17:1 | Body text on event cards; passes normal-text AA and AAA. |
| Blue `#005EA8` | White `#FFFFFF` | 6.63:1 | Links on white and button fill against white; passes normal-text AA. |
| Blue `#005EA8` | Pale blue `#F2F7FB` | 6.14:1 | Links and component edges on pale cards; passes normal-text AA and exceeds the 3:1 component threshold. |
| White `#FFFFFF` | Blue `#005EA8` | 6.63:1 | Button text on blue; passes normal-text AA. |
