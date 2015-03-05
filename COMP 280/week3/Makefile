CC = gcc
CFLAGS = -g -Wall

TARGETS = gdb-test bitwise

all: $(TARGETS)

gdb-test: gdb-test.c 
	$(CC) $(CFLAGS) -o $@ $<

bitwise: bitwise.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) $(TARGETS)
