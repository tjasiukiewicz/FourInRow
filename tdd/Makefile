.PHONY: clean

CFLAGS := -std=c99 -Wall -Wextra -pedantic
CC := gcc

OBJECTS := main.o numtostr.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

clean:
	@rm -rf main $(OBJECTS) > /dev/null 2>&1
