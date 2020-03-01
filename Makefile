.PHONY: clean

CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -Os -fdata-sections -ffunction-sections
LDFLAGS := -Wl,-gc-sections


OBJECTS := main.o board.o token.o player.o game.o board_displayer.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o main $(OBJECTS)

clean:
	@rm -rf main $(OBJECTS) > /dev/null 2>&1
