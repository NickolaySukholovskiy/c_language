
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
GCF= -ftest-coverage -fprofile-arcs --coverage
LFLAGS= -lcheck -lpthread

all: test gcov_report style

main: main.c s21_string.a
	$(CC) $(FLAGS) main.c s21_string.a -o main
	./main

test: s21_string.a test_1.o
	$(CC) $(FLAGS) test_1.o s21_string.a -lcheck -lm -lpthread -o test
	./test

test_1.o: sscanf_test.c s21_string.a
	$(CC) $(FLAGS) -c sscanf_test.c -o test_1.o
	
	

s21_string.a: s21_string.o s21_sscanf.o s21_csharp_funcs.o s21_sprintf.o
	ar -rc s21_string.a s21_string.o s21_sscanf.o s21_csharp_funcs.o s21_sprintf.o
	ranlib s21_string.a

s21_sscanf.o: s21_sscanf.c
	$(CC) $(FLAGS) s21_sscanf.c -c

s21_string.o: s21_string.c
	$(CC) $(FLAGS) s21_string.c -c
	
s21_csharp_funcs.o: s21_csharp_funcs.c
	$(CC) $(FLAGS) s21_csharp_funcs.c -c
	
s21_sprintf.o: s21_sprintf.c
	$(CC) $(FLAGS) s21_sprintf.c -c
	
gcov_report: test s21_string.a
	$(CC) $(GCF) sscanf_test.c s21_csharp_funcs.c s21_string.c s21_sscanf.c s21_sprintf.c s21_string.a $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\
	
style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c *.h
	rm -f .clang-format


clean:
	rm -f *.a
	rm -f *.o
	rm -f test
	rm -f main
	rm -rf *.dSYM
	rm -f *.gcov
	rm -f gcov_report
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.info
	rm -rf test_output
	
rebuild:
	make clean
	make all
