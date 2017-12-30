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
  int ret, fd;
  char *filename = "/dev/i2c-1";
  char  i2c_addr = 0x38;

  fd = open(filename, O_RDWR);
  check(fd, "file open");

  // set the slave address to write to
  ret = ioctl(fd, I2C_SLAVE, i2c_addr);
  check(ret, "ioctl");

	char buf[] = {0};

  read( fd, 
        buf, 
        sizeof(buf) );

  printf("%d\n", (int) *buf); // print out the data (cast as int so we see decimal)

  ret = close(fd);
  check(ret, "file close");
}

void check(int ret, char const *msg) {
  if(ret < 0) {
    perror(msg);
    exit(EXIT_FAILURE);
  }
}
