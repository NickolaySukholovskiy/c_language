CC = gcc

FLAGS = -Wall -Werror -Wextra #-fsanitize=address

all: s21_cat

s21_cat: cat_main.o work_with_file.o work_with_flags.o
	$(CC) $(FLAGS) cat_main.o work_with_file.o work_with_flags.o -o s21_cat
	rm *.o

cat_main.o:
	$(CC) $(FLAGS) -c cat_main.c

work_with_file.o:
	$(CC) $(FLAGS) -c work_with_file.c

work_with_flags.o:
	$(CC) $(FLAGS) -c work_with_flags.c

clean:
	rm -f s21_cat

rebuild:
	make clean
	make all
