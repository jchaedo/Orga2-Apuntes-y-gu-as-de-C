CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = main

all: $(TARGET)

SRCS = p3.c
OBJS = $(SRCS:*.c=.o)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)


.PHONY: all clean
