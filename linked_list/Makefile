
CC = gcc
FILES = helper_functions.c student_list.c helper_functions.h student_list.h
OUTPUT = student_list
CFLAGS = -c -ggdb -std=c99 -Wall -Werror
LDFLAGS = -lm

all: $(OUTPUT)

$(OUTPUT): student_list.o helper_functions.o
	$(CC) student_list.o helper_functions.o -o $(OUTPUT)

student_list.o: student_list.c
	$(CC) $(CFLAGS) student_list.c

helper_functions.o: helper_functions.c
	$(CC) $(CFLAGS) helper_functions.c

