#ifndef GET_FLAGS_H
#define GET_FLAGS_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int e;  // ищет в файлах данную строку +
  char *mas_e;

  int i;  // приводит строки к одному регистру +
  int v;  // выводит все строки, где нет искомой строки +
  int c;  // выводит число строк, где строка встретилась +
  int l;  // выводит названия файлов, где встретилась строка +
  int n;  // нумерует строки при выводе +
  int h;  // не выводить название файла, если ищем совпадение в многих файлах +
  int s;  // не выводить сообщение об ошибке, если файла не существует +
  int my_flag;  // флаг показывает, что совпадения ищем в нескольких файлах

  int f;  // берёт файл, где производит поиск в других файлах по строкам +
  char **mas_f;
  int size_f;

  int o;  // если находит совпадение, то выводит только строку поиска
          // если флаг v, то обнуляем o
          // если фдаг c, то обнуляем o
};

void get_flags(int argc, char *argv[], struct flags *grep_flags);
void null_flags(struct flags *grep_flags);
void free_struct(struct flags *grep_flags);
void change_flags(struct flags *grep_flags);
void change_special_symbols(struct flags *grep_flags);

void get_files_open_them(int argc, char *argv[], struct flags *grep_flags);
char *get_str_from_file(FILE *fp, int *size);

#endif
