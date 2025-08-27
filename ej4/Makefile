CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = sizeof_stdint

all: $(TARGET)

$(TARGET): sizeof_stdint.o
	$(CC) $(CFLAGS) $^ -o $@

sizeof_stdint.o: sizeof_stdint.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean