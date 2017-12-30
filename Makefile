CC = gcc

i2c: i2c.c
	$(CC) $^ -o $@
