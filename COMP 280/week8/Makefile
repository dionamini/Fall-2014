CC = gcc
CFLAGS = -Wall -g

TARGETS = twoDarray fileio commandlineargs

all: $(TARGETS)

twoDarray: twoDarray.c
	$(CC) $(CFLAGS) -o $@ $<

fileio: fileio.c
	$(CC) $(CFLAGS) -o $@ $<

commandlineargs: commandlineargs.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(TARGETS)
