CC = gcc
EXECS = i2c-write i2c-read

.PHONY: all clean

all: $(EXECS)

clean:
	rm $(EXECS)

%: %.c
	$(CC) $^ -o $@
