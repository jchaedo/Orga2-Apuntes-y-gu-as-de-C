CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = tirando_un_dado_varias_veces

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(TARGET)

.PHONY: all clean
