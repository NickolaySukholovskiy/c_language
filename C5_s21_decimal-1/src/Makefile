CC = gcc -Wall -Werror -Wextra -g -std=c11
SRC= $(wildcard s21_*.c)
OBJ= $(patsubst %.c, %.o, ${SRC})
LFLAGS= -lcheck -lpthread 
GCF= -ftest-coverage -fprofile-arcs --coverage

ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit -lm
endif


all: clean s21_decimal.a gcov_report


rebuild: clean s21_decimal.a

clean:
	rm -rf *.o && rm -rf *.gcno
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf ./report/
	rm -rf test_output/

s21_decimal.o:
	$(CC) -c ${SRC} 

s21_decimal.a: s21_decimal.o
	ar rcs s21_decimal.a ${OBJ} 
	ranlib s21_decimal.a
	rm *.o


test: unit_tests.c s21_decimal.a
	$(CC) -o test $^ ${LFLAGS}
	./test

gcov_report: test
	$(CC) $(GCF) unit_tests.c $(SRC)  $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\

style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c
	rm -f .clang-format

C = gcc  -g -std=c11
SRC= $(wildcard s21_*.c)
OBJ= $(patsubst %.c, %.o, ${SRC})
LFLAGS= -lcheck -lm -lpthread 
GCF= -ftest-coverage -fprofile-arcs --coverage

ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit
endif



all: clean s21_decimal.a 


main: clean
	$(CC) -c main.c
	$(CC) main.o s21_decimal.a -o main.out
	./main.out
	
rebuild: clean s21_decimal.a main

clean:
	rm -rf *.o && rm -rf *.gcno
# rm -rf *.a 
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf ./report/

s21_decimal.o:
	$(CC) -c s21_decimal_1.c -lm

s21_decimal.a: s21_decimal.o
	ar rcs s21_decimal.a s21_decimal_1.o
	ranlib s21_decimal.a
	rm *.o

# test: unit_tests.c s21_decimal.a
# 	$(CC)  -o test $^ ${LFLAGS}
# 	./test

# gcov_report: test
# # $(CC) $(GCF) -c unit_tests.c
# 	$(CC) $(GCF) $(SRC) unit_tests.c $(LFLAGS) -o gcov_report
# 	./gcov_report
# 	lcov -t "test" -o gcov_report.info -c -d .
# 	genhtml -o test_output gcov_report.info
# 	open ./test_output/index.html\

# style:
# 	cp ../materials/linters/.clang-format ./
# 	clang-format -style=Google -i *.c

# add_coverage:
# 	$(eval CC += --coverage)

#  Флаги Димаса раскомитить при тестирование
# CC = gcc
# FLAGS = -Wall -Werror -Wextra -g

# all: s21_decimal

# s21_decimal: s21_decimal.o
# 	$(CC) $(FLAGS) s21_decimal.o -o test_functions
	
# s21_decimal.o: s21_decimal.c
# 	$(CC) $(FLAGS) s21_decimal.c -c
	
# clean:
# 	rm -f *.o
	
# rebuild:
# 	make clean
# 	make all
test: unit_tests.c s21_decimal.a
	$(CC) -o test $^ ${LFLAGS}
	./test

gcov_report: test
# $(CC) $(GCF) -c unit_tests.c
	$(CC) $(GCF) unit_tests.c $(SRC)  $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\

style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c


