CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = monstruo_t

all: $(TARGET)

SRCS = monstruo_t.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET) *.d

.PHONY: all clean