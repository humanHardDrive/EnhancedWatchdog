# Enhanced Watchdog
Based on the ATtiny402, this device acts like a watchdog timer with several enhanced modes of operation. The goal is to create an easy to implement device that can easily detect anomalous behavior caused by hardware faults, software bugs, or malicious attack.

## Operating Modes
There are currently supported 4 modes of operation.

### Timed Edge
This mode operates like a classic watchdog timer.

### Limited Timed Edge
Operates like a classic watchdog timer, however there's a limit to how often an edge can be seen.

### Timed Pulse
Requires a leading and trailing edge of certain width every set amount of time to satisfy the timer.

### Limited Timed Pulse
Similar to the above mode, but the pulse can only be generated so often.