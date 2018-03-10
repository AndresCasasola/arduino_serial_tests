# Arduino Serial Tests

- Two examples to implement arduino serial comunication in both directions with a linux pc
The transmitters programs sends a buffer of bytes (char) by serial way, the receiver process it and show the message in terminal.

- These examples uses arduino-serial-library developed by todbot, https://github.com/todbot/arduino-serial

# To prove them you can implement two diferents directions for comunication:

- 1) Arduino -> Linux PC
For this direction you must use the files tx_serial_helloPacket_arduino.c and rx_serial_helloPacket_linux.c.
In this way arduino will behave as a transmitter and the pc like a receptor.

- 2) Linux PC -> Arduino
For this direction you must use the files rx_serial_helloPacket_arduino.c and tx_serial_helloPacket_linux.c.
In this way arduino will behave as a transmitter and the pc like a receptor.
