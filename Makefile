CC = gcc
EXECS = i2c-write

.PHONY: all clean

all: $(EXECS)

clean:
	rm $(EXECS)

%: %.c
	$(CC) $^ -o $@
