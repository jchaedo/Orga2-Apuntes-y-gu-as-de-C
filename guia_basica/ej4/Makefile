CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = sizeof_stdint

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

sizeof_stdint.o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean