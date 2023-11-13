CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS=StreamEditor

build: $(TARGETS)

StreamEditor: main.c algorithms.c basic_functions.c
	$(CC) $(CFLAGS) main.c algorithms.c basic_functions.c -o StreamEditor

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
