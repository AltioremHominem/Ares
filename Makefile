CC = gcc # Standar C Compiler

CFLAGS = -Wall -Wextra # Compiler Flags for more precision

LIBS = -ltermbox # TermBox Library

FILES = src/main.c src/rendering.c src/fileIO.c src/modes.c

all : #make in the terminal to execute this
	$(CC) $(CFLAGS) $(FILES) -o Ares $(LIBS)

clean : #make clean to remove binaries
	rm -f Ares

