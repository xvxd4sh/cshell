EXECUTABLE= shell
CFLAGS=-DUNIX -lreadline -lcurses
DEBUG=-g

all: shell

shell: shell.c parse.c
	gcc $(CFLAGS) $(DEBUG) shell.c parse.c -o shell
	gcc $(CFLAGS) -o $(EXECUTABLE) shell.c -Wall -W

clean:
	rm $(EXECUTABLE)
	rm -f shell *~
