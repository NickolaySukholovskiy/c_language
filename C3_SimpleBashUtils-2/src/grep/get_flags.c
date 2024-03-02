
#include "get_flags.h"

char **add_str_to_mas(char **mas, char *str, int size) {
  int str_size = (int)strlen(str);
  char **new_mas = calloc(size + 1, sizeof(char *));

  for (int i = 0; i < size - 1; i++) {
    new_mas[i] = calloc((int)strlen(mas[i]) + 1, sizeof(char));
    for (int j = 0; j < (int)strlen(mas[i]); j++) {
      new_mas[i][j] = mas[i][j];
    }
  }

  new_mas[size - 1] = calloc(str_size + 1, sizeof(char));
  for (int i = 0; i < str_size; i++) {
    new_mas[size - 1][i] = str[i];
  }

  for (int i = 0; i < size - 1; i++) {
    free(mas[i]);
  }
  free(mas);

  return new_mas;
}

void s21_strcat(char *str1, char *str2) {
  int size_1 = (int)strlen(str1);
  int size_2 = (int)strlen(str2);
  int j = 0;

  for (int i = size_1; i < size_1 + size_2; i++) {
    str1[i] = str2[j];
    j++;
  }
}

char *fill_mas_e(char *str, char *str_to_add) {
  char *buf = NULL;
  int size_1;
  int size_2 = (int)strlen(str_to_add);
  if (str == NULL) {
    size_1 = 0;
  } else {
    size_1 = (int)strlen(str);
  }

  if (size_1 != 0) {
    buf = calloc(size_1 + size_2 + 3, sizeof(char));
    s21_strcat(buf, str);
    s21_strcat(buf, "|");
  } else {
    buf = calloc(size_1 + size_2 + 2, sizeof(char));
  }

  s21_strcat(buf, str_to_add);

  free(str);

  str = calloc((int)strlen(buf) + 2, sizeof(char));

  for (int i = 0; i < size_1 + size_2 + 2; i++) {
    str[i] = buf[i];
  }

  free(buf);
  return str;
}

char *delete_endline(char *str) {
  int flag_end = 0;
  char *new_str = NULL;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == '\n' && (int)strlen(str) != 1) {
      flag_end = 1;
    }
  }
  if (flag_end == 1) {
    int size = (int)strlen(str) - 1;
    new_str = calloc(size + 1, sizeof(char));
    for (int i = 0; i < size; i++) {
      new_str[i] = str[i];
    }
    free(str);
  } else {
    new_str = str;
  }
  return new_str;
}

void get_info_from_mas_f(struct flags *grep_flags, FILE *fp) {
  char *str_from_file;
  int size;
  while ((str_from_file = get_str_from_file(fp, &size)) != NULL) {
    str_from_file = delete_endline(str_from_file);
    grep_flags->mas_e = fill_mas_e(grep_flags->mas_e, str_from_file);
    free(str_from_file);
  }
  if (grep_flags->mas_e != NULL) {
    grep_flags->e = 1;
  }
}

void get_flags(int argc, char *argv[], struct flags *grep_flags) {
  int counter = 1;
  const struct option long_options[] = {{NULL, 0, NULL, 0}};
  int opt;
  const char *short_options = "e:ivclnhsf:o";
  int option_index = -1;
  while ((opt = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    counter++;
    switch (opt) {
      case 'e':
        grep_flags->e = 1;
        grep_flags->mas_e = fill_mas_e(grep_flags->mas_e, optarg);
        break;

      case 'i':
        grep_flags->i = 1;
        break;

      case 'v':
        grep_flags->v = 1;
        break;

      case 'c':
        grep_flags->c = 1;
        break;

      case 'l':
        grep_flags->l = 1;
        break;

      case 'n':
        grep_flags->n = 1;
        break;

      case 'h':
        grep_flags->h = 1;
        break;

      case 's':
        grep_flags->s = 1;
        break;

      case 'f':
        grep_flags->f = 1;
        FILE *fp;
        if ((fp = fopen(optarg, "r")) != 0) {
          get_info_from_mas_f(grep_flags, fp);
          fclose(fp);
        }
        grep_flags->size_f += 1;
        grep_flags->mas_f =
            add_str_to_mas(grep_flags->mas_f, optarg, grep_flags->size_f);
        break;

      case 'o':
        grep_flags->o = 1;
        break;

      case '?':
      default: {
        break;
      };
    }
  }
  if (grep_flags->e == 0 && optind < argc) {
    grep_flags->e = 1;
    grep_flags->mas_e = fill_mas_e(grep_flags->mas_e, argv[optind]);
    optind++;
  }
  if (argc - optind > 1) {
    grep_flags->my_flag = 1;
  }
}

void null_flags(struct flags *grep_flags) {
  grep_flags->e = 0;
  grep_flags->mas_e = NULL;

  grep_flags->f = 0;
  grep_flags->mas_f = NULL;
  grep_flags->size_f = 0;

  grep_flags->my_flag = 0;

  grep_flags->i = 0;
  grep_flags->v = 0;
  grep_flags->c = 0;
  grep_flags->l = 0;
  grep_flags->n = 0;
  grep_flags->h = 0;
  grep_flags->s = 0;
  grep_flags->o = 0;
}

void free_struct(struct flags *grep_flags) {
  if (grep_flags->mas_e != NULL) {
    free(grep_flags->mas_e);
  }

  if (grep_flags->size_f != 0) {
    for (int i = 0; i < grep_flags->size_f; i++) {
      free(grep_flags->mas_f[i]);
    }
    free(grep_flags->mas_f);
  }
}

void change_flags(struct flags *grep_flags) {
  if (grep_flags->v == 1) {
    grep_flags->o = 0;
  }
  if (grep_flags->c == 1) {
    grep_flags->o = 0;
  }
  if (grep_flags->l == 1) {
    grep_flags->n = 0;
  }
  if (grep_flags->h == 1) {
    grep_flags->my_flag = 0;
  }
  if (grep_flags->c == 1) {
    grep_flags->n = 0;
  }
}

void change_special_symbols(struct flags *grep_flags) {
  if (grep_flags->mas_e != NULL) {
    for (int i = 0; i < (int)strlen(grep_flags->mas_e); i++) {
      if (grep_flags->mas_e[i] == '$') {
        grep_flags->mas_e[i] = '\n';
      }
    }
  }
}
