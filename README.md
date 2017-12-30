# Raspberry Pi PCF8574 Demo

Reads or writes a byte out to a PCF8574 chip on the I2C bus. This uses pure Linux C with no library dependencies.

### --WARNING--
This program uses hardcoded addresses on bus `/dev/i2c-1`. There's nothing on this bus on my raspberry pi, but you shouldn't run this on your own computer unless you're sure that you're writing to the right chip. Use `i2cdetect` from the `i2c-tools` package to check for devices.

### Usage
```
pi@raspberrypi:~/rpi-pcf8574 $ ./i2c-write 255 # writes all the pins high
pi@raspberrypi:~/rpi-pcf8574 $ ./i2c-read 
255
pi@raspberrypi:~/rpi-pcf8574 $ ./i2c-write 0 # writes all the pins low
pi@raspberrypi:~/rpi-pcf8574 $ ./i2c-read 
0
```
