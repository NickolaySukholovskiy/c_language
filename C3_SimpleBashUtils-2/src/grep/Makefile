CC = gcc

FLAGS = -g -Wall -Werror -Wextra #-fsanitize=address

all: s21_grep

s21_grep: grep_main.o grep_file.o get_flags.o
	$(CC) $(FLAGS) grep_main.o grep_file.o get_flags.o -o s21_grep
	rm *.o

grep_main.o:
	$(CC) $(FLAGS) -c grep_main.c
	
grep_file.o:
	$(CC) $(FLAGS) -c grep_file.c

get_flags.o:
	$(CC) $(FLAGS) -c get_flags.c

clean:
	rm -f s21_grep

rebuild:
	make clean
	make all
