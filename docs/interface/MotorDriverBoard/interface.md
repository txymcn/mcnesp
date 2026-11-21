# MotorDriverBoard

Applies PWM and direction commands to the left and right motors.

## Data Members

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `left_duty_`, `right_duty_` | `float` | `0.0` to `1.0` | PWM duty for each motor. `0.0` commands zero drive and `1.0` commands full duty. Initially `0.0`. |
| `left_direction_`, `right_direction_` | `MotorDirection` | `Forward` or `Reverse` | Requested direction relative to the buggy's direction of travel. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `void set_left_motor(MotorDirection direction, float duty)` | Applies direction and PWM duty to the left motor. The caller supplies a duty in `0.0–1.0`. |
| `void set_right_motor(MotorDirection direction, float duty)` | Applies direction and PWM duty to the right motor. The caller supplies a duty in `0.0–1.0`. |
| `void stop()` | Commands zero drive on both motors by setting both PWM duties to `0.0`. |

[All class interfaces](../interfaces.md)
