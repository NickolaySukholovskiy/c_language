
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
LFLAGS = -lcheck -lm -lpthread
GFLAGS = -ftest-coverage -fprofile-arcs --coverage

OBJECT_FILES_C = $(wildcard backend/*.c)

QT_PROJECT_NAME = s21_interface
QT_PROJECT_FOLDER = $(QT_PROJECT_NAME)
QT_PRO = $(QT_PROJECT_NAME).pro
QT_MAKEFILE = $(QT_PROJECT_NAME)_Makefile
QT_BUILD_FOLDER = build
QT_APP_FOLDER = ../app
DIST_FOLDER_NAME = SmartCalc-1.0
SRC_BACK_DIR = back
OS_NAME = $(shell uname -s)

all: test

generate_make:
	qmake $(QT_PROJECT_FOLDER)/$(QT_PRO) -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)
	rm -rf .qmake.stash

install: generate_make
	cd ./$(QT_BUILD_FOLDER) && make -sf $(QT_MAKEFILE)
	mkdir -p ./$(QT_APP_FOLDER)
ifeq ($(OS_NAME), Linux) 
	mv build/$(QT_PROJECT_NAME) $(QT_APP_FOLDER)
endif 
ifeq ($(OS_NAME), Darwin)
	mv build/$(QT_PROJECT_NAME).app $(QT_APP_FOLDER) 
endif
	rm -rf $(QT_BUILD_FOLDER)

uninstall:
	rm -rf $(QT_APP_FOLDER)

main: main.o s21_from_postfix_to_result.o s21_to_postfix.o
	$(CC) $(CFLAGS) main.o s21_from_postfix_to_result.o s21_to_postfix.o -o main
	./main
	
test: test.o s21_to_postfix.o s21_from_postfix_to_result.o s21_connect.o s21_credit_calc.o
	$(CC) $(CFLAGS) test.o s21_to_postfix.o s21_from_postfix_to_result.o s21_connect.o s21_credit_calc.o $(LFLAGS) -o test
	./test



main.o: main.c
	$(CC) $(CFLAGS) main.c -c
	
s21_from_postfix_to_result.o: backend/s21_from_postfix_to_result.c
		$(CC) $(CFLAGS) backend/s21_from_postfix_to_result.c -c
	
s21_to_postfix.o: backend/s21_to_postfix.c 
	$(CC) $(CFLAGS) backend/s21_to_postfix.c -c
	
test.o: test.c
	$(CC) $(CFLAGS) test.c -c

s21_connect.o: backend/s21_connect.c
	$(CC) $(CFLAGS) backend/s21_connect.c -c

s21_credit_calc.o: backend/s21_credit_calc.c
	$(CC) $(CFLAGS) backend/s21_credit_calc.c -c

gcov_report:
	$(CC) $(GFLAGS) test.c $(OBJECT_FILES_C) $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "s21_calc test" -d . -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

dvi:
	doxygen Doxyfile
	open doxy/html/index.html

TAR_DIR = SmartCalc_v1.0_v1.0_Archive

dist:
	rm -Rf $(TAR_DIR)
	mkdir $(TAR_DIR)
	mkdir $(TAR_DIR)/src
	cp backend/* s21_interface/* $(TAR_DIR)/src
	tar cvzf $(TAR_DIR).tgz $(TAR_DIR)
	mv $(TAR_DIR).tgz ..
	rm -Rf $(TAR_DIR)
	
style:
	clang-format -style=Google -n *.c backend/*.c backend/*.h

clean:
	rm -f main
	rm -rf *.dSYM
	rm -f backend/*.o
	rm -f test
	rm -f backend/*.gch
	rm -rf ../$(QT_BUILD_FOLDER)/*
	rm -rf gcov_report
	rm -f *.o
	rm -f *.gcno
	rm -f backend/*.gcno
	rm -f *.gcda
	rm -f *.info
	rm -rf doxy
	rm -f ../*.tgz

rebuild:
	make clean
	make all
