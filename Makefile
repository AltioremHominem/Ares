CC = gcc # Standar C Compiler

CFLAGS = -Wall -Wextra # Compiler Flags for more precision

LIBS = -lncurses # Curses Library

all : #make in the terminal to execute this
	$(CC) $(CFLAGS) src/main.c -o builds/Ares $(LIBS)

clean : #make clean to remove binaries
	rm -f builds/Ares

debug : #make debug to debug
