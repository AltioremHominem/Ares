CC = gcc # Standar C Compiler

CFLAGS = -Wall -Wextra # Compiler Flags for more precision

LIBS = -ltermbox # TermBox Library

all : #make in the terminal to execute this
	$(CC) $(CFLAGS) src/main.c src/rendering.c src/fileIO.c -o Ares $(LIBS)

clean : #make clean to remove binaries
	rm -f Ares

