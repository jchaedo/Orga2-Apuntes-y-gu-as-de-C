CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = monstruo_evolution

all: $(TARGET)

SRCS = monstruo_evolution.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET) *.d

.PHONY: all clean