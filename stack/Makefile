
CC = gcc
FILES = cdecl.c stack.c
OBJECT_FILES = cdecl.o stack.o
OUTPUT = cdecl
CFLAGS = -c -ggdb -std=c99 -Wall -Werror
LDFLAGS = -lm

all: $(OUTPUT)

$(OUTPUT): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $(OUTPUT)

cdecl.o: cdecl.c
	$(CC) $(CFLAGS) cdecl.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

