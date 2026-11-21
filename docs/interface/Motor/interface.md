# Motor

Uses one wheel's quadrature encoder to calculate its measured speed.

## Data Members

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `counts_per_wheel_rev_` | `uint32_t` | Greater than 0 | Number of encoder counts per full wheel revolution, including the gearbox and the selected decoding mode. |
| `rpm_` | `float` | Signed rpm | Latest measured wheel speed. Positive means forward on either side of the buggy. Initially `0.0`. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `bool update(int32_t delta_counts, float dt_s)` | Calculates wheel speed from the signed change in encoder count over `dt_s` seconds. Positive counts correspond to forward motion. Returns `false` and leaves the previous reading intact if `dt_s` is zero or negative. |
| `float rpm() const` | Returns the latest measured wheel speed in rpm. |

[All class interfaces](../interfaces.md)
