CC = gcc # Standar C Compiler

CFLAGS = -Wall -Wextra # Compiler Flags for more precision

LIBS = -ltermbox # TermBox Library

FILES = src/*.c

all : #make in the terminal to execute this
	$(CC) $(CFLAGS) $(FILES) -o Ares $(LIBS)

clean : #make clean to remove binaries
	rm -f Ares

