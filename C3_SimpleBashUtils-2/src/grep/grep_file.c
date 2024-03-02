
#include "get_flags.h"

char *add_symbol_to_str(int size, char symbol, char *str) {
  char *new_str = NULL;

  if (size == 0) {
    new_str = calloc(size + 2, sizeof(char));
  } else {
    new_str = calloc(size + 2, sizeof(char));
    for (int i = 0; i < size; i++) {
      new_str[i] = str[i];
    }
    free(str);
  }

  new_str[size] = symbol;

  return new_str;
}
// функция поимвольно считывает строку и добавляет символы в строку для поиска
char *get_str_from_file(FILE *fp, int *size) {
  *size = 0;
  char symbol;
  char *new_str = NULL;

  while ((symbol = fgetc(fp)) != EOF) {
    new_str = add_symbol_to_str(*size, symbol, new_str);
    *size += 1;
    if (symbol == '\n') {
      break;
    }
  }
  return new_str;
}
// функция вывода строки для уменьшения объёма
void print_str(char *str, int size) {
  for (int i = 0; i < size; i++) {
    printf("%c", str[i]);
  }
  if (str[size - 1] != '\n') {
    printf("\n");
  }
}
// функция, реализующая флаг v
int flag_v(int flag_v, int reg_flag) {
  if (flag_v == 1) {
    if (reg_flag == 0) {
      reg_flag = 1;
    } else {
      reg_flag = 0;
    }
  }
  return reg_flag;
}

int flag_i(int flag_i, char *str_to_find, char *str_from_file) {
  int reg_flags = 0;
  int reg_flag = 0;
  regex_t reg;

  if (flag_i == 1) {
    reg_flags = REG_ICASE;
  } else {
    reg_flags = REG_EXTENDED;
  }
  reg_flag = regcomp(&reg, str_to_find, reg_flags);
  reg_flag = regexec(&reg, str_from_file, 0, 0, 0);
  regfree(&reg);
  return reg_flag;
}

void print_filename(struct flags grep_flags, char *filename) {
  int size = (int)strlen(filename);
  if (grep_flags.my_flag == 1 && grep_flags.c == 0) {
    for (int i = 0; i < size; i++) {
      printf("%c", filename[i]);
    }
    printf(":");
  }
}

void flag_n(struct flags grep_flags, int str_number) {
  if (grep_flags.n == 1) {
    printf("%d:", str_number);
  }
}
// функция выводит результат работы grep'а с флагами
void print_result(struct flags grep_flags, char *str_from_file, int size,
                  char *filename, int str_number) {
  if (grep_flags.c != 1) {
    print_filename(grep_flags, filename);
    flag_n(grep_flags, str_number);
    print_str(str_from_file, size);
  }
}

void flag_c(struct flags grep_flags, int counter_matches, char *filename) {
  if (grep_flags.c == 1) {
    if (grep_flags.my_flag == 1) {
      int size = (int)strlen(filename);
      for (int i = 0; i < size; i++) {
        printf("%c", filename[i]);
      }
      printf(":");
    }
    printf("%d\n", counter_matches);
  }
}

int flag_o(struct flags grep_flags, char *str_to_find, char *str,
           char *filename, int str_number) {
  int flag_l = 0;
  char *s = str;
  regex_t reg;
  size_t nmatch = 1;
  regmatch_t pmatch[1];
  regoff_t off, len;
  int reg_flags = 0;
  if (grep_flags.i == 1) {
    reg_flags = REG_ICASE;
  } else {
    reg_flags = REG_EXTENDED;
  }
  regcomp(&reg, str_to_find, reg_flags);

  for (int i = 0;; i++) {
    if (regexec(&reg, s, nmatch, pmatch, 0)) {
      break;
    }
    off = pmatch[0].rm_so + (s - str);  // rm_so — содержит номер элемента, с
    // которого начинается совпадение
    len =
        pmatch[0].rm_eo - pmatch[0].rm_so;  // rm_eo — содержит номер элемента,
    // которым заканчивается совпадение
    if (grep_flags.l == 1) {
      flag_l = 1;
      break;
    }
    print_filename(grep_flags, filename);
    flag_n(grep_flags, str_number);
    for (int i = off; i - off < len; i++) {
      printf("%c", str[i]);
    }
    printf("\n");
    s += pmatch[0].rm_eo;
  }
  regfree(&reg);
  return flag_l;
}

int apply_flags(FILE *fp, struct flags grep_flags, char *filename) {
  int str_number = 1;
  int flag_l = 0;
  int counter_matches = 0;
  int reg_flag = 0;
  int size;
  char *str_from_file = NULL;
  while ((str_from_file = get_str_from_file(fp, &size)) != NULL &&
         flag_l == 0) {
    if (grep_flags.o == 0) {
      reg_flag = flag_i(grep_flags.i, grep_flags.mas_e, str_from_file);
      reg_flag = flag_v(grep_flags.v, reg_flag);
      if (reg_flag == 0) {
        counter_matches++;
        if (grep_flags.l == 1) {
          flag_l = 1;
          break;
        }
        print_result(grep_flags, str_from_file, size, filename, str_number);
      }
    } else {
      flag_l = flag_o(grep_flags, grep_flags.mas_e, str_from_file, filename,
                      str_number);
    }
    str_number++;
    free(str_from_file);
  }
  flag_c(grep_flags, counter_matches, filename);
  return flag_l;
}

int find_files_to_find_in(char *str_to_check, struct flags *grep_flags) {
  int flag = 0;
  if (strstr(grep_flags->mas_e, str_to_check) != NULL) {
    flag = 1;
  }
  for (int i = 0; i < grep_flags->size_f; i++) {
    if (strcmp(grep_flags->mas_f[i], str_to_check) == 0) {
      flag = 1;
    }
  }
  if (str_to_check[0] == '-') {
    flag = 1;
  }
  return flag;
}

void get_files_open_them(int argc, char *argv[], struct flags *grep_flags) {
  int counter_files = 0;
  for (int i = 1; i < argc; i++) {
    // проверяю, какие из аргументов являются файлами
    int flag = find_files_to_find_in(argv[i], grep_flags);
    if (flag == 0) {
      FILE *fp = fopen(argv[i], "r");
      if (fp == 0) {
        if (grep_flags->s != 1) {
          printf("grep: ");
          for (int j = 0; j < (int)strlen(argv[i]); j++) {
            printf("%c", argv[i][j]);
          }
          printf(": No such file or directory\n");
        }
      } else {
        int flag_l = apply_flags(fp, *grep_flags, argv[i]);
        fclose(fp);
        if (flag_l == 1) {
          print_str(argv[i], (int)strlen(argv[i]));
        }
      }
      counter_files++;
    }
    flag = 0;
  }
}
