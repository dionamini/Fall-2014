CC=gcc

TARGET=simpleops

all: $(TARGET) 

# generate executable along with intermediate assembly and object code
$(TARGET): $(TARGET).c
	$(CC) -S $(TARGET).c
	$(CC) -c $(TARGET).s
	$(CC) -g -o $(TARGET) $(TARGET).c

# clean up (remove) all files that can be re-built from source files
clean: 
	$(RM) $(TARGET) *.o *.s
