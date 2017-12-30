#include <linux/i2c-dev.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

void check(int ret, char const *msg);

int main(int argc, char *argv[]) {
  int ret;
  int fd;
  char *filename = "/dev/i2c-1";
  char i2c_addr = 0x38;

  fd = open(filename, O_RDWR);
  check(fd, "file open");

  // set the slave address to write to
  ret = ioctl(fd, I2C_SLAVE, i2c_addr);
  check(ret, "ioctl");

  char data[] = {0};
  if(argc > 1)
    data[0] = (char) atoi(argv[1]); 

  /* I'm not including this anymore because i2c-read just gets the byte back, 
   * it doesn't do any flipping. Makes more sense not to invert the bits here 
   * so both are consistent 
   */
  // data[0] = ~(data[0]); // flip bits because LEDS are low-side switched

  write( fd, 
         data, 
         sizeof(data) );

  ret = close(fd);
  check(ret, "file close");
}

void check(int ret, char const *msg) {
  if(ret < 0) {
    perror(msg);
    exit(EXIT_FAILURE);
  }
}
