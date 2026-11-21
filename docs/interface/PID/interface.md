# PID

Calculates a control output from an error and the elapsed time. Use separate instances for steering PD and for the left and right wheel PI loops.

## Data Members

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `kp_`, `ki_`, `kd_` | `float` | Set during tuning | Proportional, integral and derivative gains. Set `ki_` to zero for PD and `kd_` to zero for PI. |
| `integral_` | `float` | Signed | Accumulated error over time. Initially `0.0`. |
| `previous_error_` | `float` | Same units as the input error | Error from the previous valid update. |
| `has_previous_error_` | `bool` | `true` or `false` | Whether a previous error is available for the derivative calculation. Initially `false`. |
| `output_min_`, `output_max_` | `float` | `output_min_ <= output_max_` | Lower and upper limits for the controller output. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `float update(float error, float dt_s)` | Calculates the next control output. The caller supplies `dt_s > 0` in seconds. The first update after reset uses a zero derivative term. |
| `void reset()` | Clears the accumulated error and previous-error history. Call before restarting a control loop. |

For steering, use `SensorArray::line_error()` when the line estimate is valid. Interpret the output as a wheel-speed correction in rpm. A positive correction increases the left target and decreases the right target during forward tracking.

For wheel-speed control, use target rpm minus measured rpm. Interpret the output as a signed drive command in `-1.0–+1.0`. The sign determines the direction and the magnitude gives the PWM duty.

[All class interfaces](../interfaces.md)
