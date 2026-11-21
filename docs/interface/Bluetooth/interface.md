# Bluetooth

Receives messages from the HM-10 and passes decoded commands to the buggy control logic.

## Data Members

| Member | Data type | Range or value | Description |
| --- | --- | --- | --- |
| `rx_buffer_` | Byte array | Capacity TBC | Stores received bytes while a command is being assembled. |
| `rx_length_` | `size_t` | `0` to the buffer capacity | Number of bytes currently stored. |

## Public Member Functions

| Declaration | Description |
| --- | --- |
| `bool read_command(BluetoothCommand& command)` | Checks for a complete, recognised command without waiting for more bytes. Returns `true` and writes the decoded command when one is available. Otherwise, returns `false` and leaves `command` intact. |

`BluetoothCommand` represents a decoded command. The supported commands and their message format are TBC. The buggy control logic decides how each command affects the operating state.

[All class interfaces](../interfaces.md)
