CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = variables_locales_y_globales

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean
