CC = gcc -Wall -Werror -Wextra -std=c11
SRC = $(wildcard back/s21_*.c)
OBJ = $(patsubst %.c, %.o, ${SRC})
LFLAGS = -lcheck -lpthread 
GCF = -ftest-coverage -fprofile-arcs --coverage

SRC_FRONT_DIR = 3dviewer
SRC_BACK_DIR = ./
QT_PROJECT_NAME = 3dViewer
QT_PROJECT_FOLDER = ./$(SRC_FRONT_DIR)
QT_PRO = $(QT_PROJECT_NAME).pro
QT_MAKEFILE = $(QT_PROJECT_NAME)_Makefile
QT_BUILD_FOLDER = build
QT_APP_FOLDER = ../App
DIST_FOLDER_NAME = 3DVIEWER_V1
TAR_DIR = $(QT_PROJECT_NAME)_Archive

OS_NAME = $(shell uname -s)

ifeq ($(OS_MAME), Linux)
	LFLAGS += -lrt -lsubunit -lm
endif

clean:
	rm -rf *.o  && rm -rf *.gcno
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test.out && rm -rf ./gcov_report
	rm -rf ./report/
	rm -rf test_output/
	rm -rf *.a && rm -rf *.o
	rm -rf html && rm -rf latex && rm -rf documentations
# rm -rf ../App
	
all: install test gcov_report

install: generate_make
	@echo "Building application..."
#                                      -f choose Makefile to build -s silent
	cd ./$(QT_BUILD_FOLDER) && make -s -f $(QT_MAKEFILE)
	@echo "Application builded."
	@echo  "Moving application to folder \"$(QT_APP_FOLDER)\"..." -n
	mkdir -p ./$(QT_APP_FOLDER)
ifeq ($(OS_NAME), Linux) 
	mv build/$(QT_PROJECT_NAME) ../App 
endif 
ifeq ($(OS_NAME), Darwin)
	mv build/$(QT_PROJECT_NAME).app ../App 
endif
	@echo "Done."
	@echo "Deleting build folder..."
	rm -rf $(QT_BUILD_FOLDER)
	@echo "Done."
	@echo "Installation complete!"

generate_make:
	qmake $(QT_PROJECT_FOLDER)/$(QT_PRO) -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)
	rm -rf .qmake.stash

uninstall:
	@echo "Uninstalling application..."
	rm -rf $(QT_APP_FOLDER)
	@echo "Done"


dist:
	rm -Rf $(TAR_DIR)
	mkdir $(TAR_DIR)
	mkdir $(TAR_DIR)/src
	cp -R  3dviewer $(TAR_DIR)/src
	cp -R  gifLib $(TAR_DIR)/src
	cp -R  Doxyconf Makefile parser_v2.c parser_v2.h unit_tests.c $(TAR_DIR)/src
	tar cvzf $(TAR_DIR).tgz $(TAR_DIR)
	mv $(TAR_DIR).tgz ..
	rm -Rf $(TAR_DIR)

dvi:
	doxygen Doxyconf
	open documentations/html/index.html

libs.o:
	$(CC) -c ${SRC}
	mv s21_*.o back/

libs.a: libs.o
	ar rcs libs.a ${OBJ} 
	ranlib libs.a
	# rm *.o
	
style:
	clang-format -style=Google -n 3dviewer/*.cpp *.c *.h 3dviewer/*.h


test: 
	$(CC) -o test.out unit_tests.c parser_v2.c ${LFLAGS}
	./test.out

gcov_report: test
	$(CC) $(GCF) unit_tests.c parser_v2.c -o gcov_report $(LFLAGS) 
	./gcov_report
	lcov -t "test.out" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html 
