# SensorArray

Reads six analogue line sensors, calibrates each channel and estimates the position of the white line.

## Data Members

All data members are private. Channels `S0` to `S5` are ordered from left to right when looking in the direction of travel.

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `sensor_count_` | `static constexpr uint8_t` | `6` | Number of sensors. |
| `adc_raw_` | `float[6]` | `0.0` to `1.0` | Latest readings returned by `AnalogIn.read()`, before calibration. |
| `black_ref_` | `float[6]` | `0.0` to `1.0` | ADC reading measured over the black track for each sensor. |
| `white_ref_` | `float[6]` | `0.0` to `1.0` | ADC reading measured over the white line for each sensor. |
| `reflectance_` | `float[6]` | `0.0` to `1.0` | Calibrated readings. `0.0` represents black and `1.0` represents white. |
| `line_valid_` | `bool` | `true` or `false` | Whether the latest scan produced a valid line position. Initially `false`. |
| `line_error_` | `float` | `-1.0` to `+1.0` | The line's position relative to the buggy centre. Negative means left, zero means centred, and positive means right. Valid when `line_valid_` is `true`. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `bool set_calibration(uint8_t index, float black_ref, float white_ref)` | Sets the black and white references for channel `0–5`. Returns `false` if the index is out of range, either reference is outside `0.0–1.0`, or both references are equal. |
| `void update()` | Reads all six sensors, updates the calibrated readings and calculates the latest line position and validity. |
| `bool line_valid() const` | Returns whether the latest scan produced a valid line position. |
| `float line_error() const` | Returns the latest line position error. Check `line_valid()` before using it. |
| `float adc_raw(uint8_t index) const` | Returns the latest uncalibrated ADC reading for channel `0–5`. |
| `float reflectance(uint8_t index) const` | Returns the latest calibrated reading for channel `0–5`. |
| `void reset()` | Clears the latest scan and marks the line position invalid. Keeps the calibration references. |

In the control loop, call `update()` first. If `line_valid()` is `true`, pass `line_error()` to the steering controller. Otherwise, enter line-loss handling.

[All class interfaces](../interfaces.md)
