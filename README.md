#Raspberry Pi PCF8574 Demo

Writes a byte out to a PCF8574 chip on the I2C bus. This uses pure Linux C with no library dependencies.

#--WARNING--
This program uses hardcoded addresses on bus `/dev/i2c-1`. There's nothing on this port on my raspberry pi, but you shouldn't run this on your own computer unless you're sure that you're writing to the right chip. Use `i2cdetect` from the `i2c-tools` package to check for devices.

