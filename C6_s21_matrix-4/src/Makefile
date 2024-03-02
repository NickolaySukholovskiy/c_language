
CC = gcc
FLAGS = -Wall -Werror -Wextra -g -std=c11
LFLAGS = -lcheck -lm -lpthread
GFLAGS = -ftest-coverage -fprofile-arcs --coverage

all: s21_matrix.a test

test: s21_matrix.a test.o
	$(CC) $(FLAGS) test.o s21_matrix.a -lcheck -lm -lpthread -o test
	./test

test.o: test.c
	$(CC) $(FLAGS) -c test.c

s21_matrix.a: s21_matrix.o
	ar -rc s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a
	
s21_matrix.o: s21_matrix.c
	$(CC) $(FLAGS) s21_matrix.c -c
	
gcov_report:
	$(CC) $(GFLAGS) test.c s21_matrix.c $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "s21_matrix test" -o s21_matrix.info -c -d .
	genhtml -o report s21_matrix.info
	open ./report/index.html\

style:
	clang-format -style=Google -n *.c *.h
	
main: s21_matrix.a main.c
	$(CC) $(FLAGS) main.c s21_matrix.a -o main
	./main


clean:
	rm -f *.a
	rm -f *.o
	rm -f test
	rm -f *.info
	rm -f gcov_report
	rm -f *.gcda
	rm -f *.gcno
	rm -rf report
	rm -f main
	rm -rf *.dSYM
	
rebuild:
	make clean
	make all
