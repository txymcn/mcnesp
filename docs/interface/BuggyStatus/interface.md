# BuggyStatus

Stores the buggy's current operating state. The main control loop decides when the state changes.

## Data Members

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `state_` | `BuggyState` | `Idle`, `Running` or `LineLost` | Current operating state. Initially `Idle`. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `BuggyState state() const` | Returns the current operating state. |
| `void set_state(BuggyState state)` | Records the state selected by the main control loop. |

`Idle` means the buggy is waiting. `Running` means normal line following is active. `LineLost` means the buggy has entered its line-loss response. The conditions for entering and leaving `LineLost` are TBC.

[All class interfaces](../interfaces.md)
