CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = i++_vs_++i

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean
