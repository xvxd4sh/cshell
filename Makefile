EXECUTABLE= w4118_sh
CFLAGS=-DUNIX -lreadline -lcurses
DEBUG=-g

all: shell

shell: shell.c parse.c
	gcc $(CFLAGS) $(DEBUG) shell.c parse.c -o shell
	gcc -g -o $(EXECUTABLE) shell.c -Wall -W

clean:
	rm $(EXECUTABLE)
	rm -f shell *~ 

test:

.PHONY: valgrind
valgrind: shell
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

.PHONY: lint
lint: shell.c
	checkpatch --no-tree --terse --file shell.c
	checkpatch --no-tree --terse --file shell.h

.PHONY: lint-verbose
lint-verbose: shell.c
	checkpatch --no-tree --file shell.c
checkpatch --no-tree --file shell.h
