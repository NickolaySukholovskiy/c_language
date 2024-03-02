
#include "s21_string.h"

void go_to_symbol(char **ptr);

void get_p_flag(char **ptr, flags *sscan, int *return_result) {
  unsigned long long int result = 0;
  int flag = 0;

  if (**ptr == '0' && (*(*ptr + 1) == 'x' || *(*ptr + 1) == 'X')) {
    *ptr += 2;
    for (int i = 0; i < 9; i++) {
      flag++;
      if (**ptr >= '0' && **ptr <= '9') {
        result *= 16;
        result += **ptr - '0';
      } else if (**ptr == 'A' || **ptr == 'a') {
        result *= 16;
        result += 10;
      } else if (**ptr == 'B' || **ptr == 'b') {
        result *= 16;
        result += 11;
      } else if (**ptr == 'C' || **ptr == 'c') {
        result *= 16;
        result += 12;
      } else if (**ptr == 'D' || **ptr == 'd') {
        result *= 16;
        result += 13;
      } else if (**ptr == 'E' || **ptr == 'e') {
        result *= 16;
        result += 14;
      } else if (**ptr == 'F' || **ptr == 'f') {
        result *= 16;
        result += 15;
      } else {
        flag = 1;
        break;
      }
      (*ptr)++;
    }
  } else {
    flag = 1;
  }

  if (flag == 1) {
    sscan->fail = 1;
  } else {
    *return_result += 1;
    sscan->adress = calloc(1, sizeof(unsigned long long int));
    *(unsigned long long int *)sscan->adress = result;
  }
}

void get_o_flag(char **ptr, flags *sscan, int *return_result) {
  unsigned long long int result = 0;
  int flag = 0;

  while (1) {
    flag++;
    if (**ptr >= '0' && **ptr <= '8') {
      result *= 8;
      result += **ptr - '0';
    } else {
      break;
    }
    (*ptr)++;
  }

  if (flag == 1) {
    sscan->fail = 1;
  } else {
    *return_result += 1;
    sscan->adress = calloc(1, sizeof(unsigned long long int));
    *(unsigned long long int *)sscan->adress = result;
  }
}

void get_x_flag(char **ptr, flags *sscan, int *return_result) {
  unsigned long long int result = 0;
  int flag = 0;

  while (1) {
    flag++;
    if (**ptr >= '0' && **ptr <= '9') {
      result *= 16;
      result += **ptr - '0';
    } else if (**ptr == 'A' || **ptr == 'a') {
      result *= 16;
      result += 10;
    } else if (**ptr == 'B' || **ptr == 'b') {
      result *= 16;
      result += 11;
    } else if (**ptr == 'C' || **ptr == 'c') {
      result *= 16;
      result += 12;
    } else if (**ptr == 'D' || **ptr == 'd') {
      result *= 16;
      result += 13;
    } else if (**ptr == 'E' || **ptr == 'e') {
      result *= 16;
      result += 14;
    } else if (**ptr == 'F' || **ptr == 'f') {
      result *= 16;
      result += 15;
    } else {
      break;
    }
    (*ptr)++;
  }

  if (flag == 1) {
    sscan->fail = 1;
  } else {
    *return_result += 1;
    sscan->adress = calloc(1, sizeof(unsigned long long int));
    *(unsigned long long int *)sscan->adress = result;
  }
}

void get_u_flag(char **ptr, flags *sscan, int *return_result) {
  long long int result = 0;
  int sign = 1;
  if (**ptr == '-' || **ptr == '+') {
    sign = **ptr == '-' ? -1 : 1;
    *ptr += 1;
    printf("%c\n", **ptr);
  }

  if (!(**ptr >= '0' && **ptr <= '9')) {
    sscan->fail = 1;
    *ptr -= 1;
  } else {
    while (**ptr >= '0' && **ptr <= '9') {
      result = result * 10 + **ptr - '0';
      *ptr += 1;
    }
  }

  if (sscan->star != 1 && !sscan->fail) {
    result *= sign;
    sscan->adress = calloc(1, sizeof(unsigned long long int));
    *(unsigned long long int *)sscan->adress = (unsigned long long int)result;
    *return_result += 1;
  }
}

void get_f_flag(char **ptr, flags *sscan, int *return_result) {
  long double result = 0;
  int sign = 1;

  if (**ptr == '-' || **ptr == '+') {
    if (*(*ptr + 1) >= '0' && *(*ptr + 1) <= '9') {
      sign = (**ptr == '-') ? -1 : 1;
      *ptr += 1;
    } else {
      sscan->fail = 1;
    }
  }

  if (**ptr >= '0' && **ptr <= '9') {
    while (**ptr >= '0' && **ptr <= '9') {
      result *= 10;
      result += **ptr - '0';
      *ptr += 1;
    }

    if (**ptr == '.') {
      if (*(*ptr + 1) >= '0' && *(*ptr + 1) <= '9') {
        *ptr += 1;
        long double scale = 1;
        while (**ptr >= '0' && **ptr <= '9') {
          scale /= 10;
          result += (**ptr - '0') * scale;
          *ptr += 1;
        }
      }
    }
  } else {
    sscan->fail = 1;
  }

  if (**ptr == 'e' && (*(*ptr + 1) == '-' || *(*ptr + 1) == '-') &&
      (*(*ptr + 2) >= '0' && *(*ptr + 2) <= '9')) {
    int buf_sign = (*(*ptr + 1) == '-') ? -1 : 1;
    *ptr += 2;
    int degree = 0;
    while (**ptr >= '0' && **ptr <= '9') {
      degree *= 10;
      degree += **ptr - '0';
      *ptr += 1;
    }

    if (buf_sign == -1) {
      result /= pow(10, degree);
    } else {
      result *= pow(10, degree);
    }
  }

  if (sscan->star != 1 && !sscan->fail) {
    *return_result += 1;
    if (sscan->length == LONG_INT) {
      sscan->adress = calloc(1, sizeof(double));
      *(double *)sscan->adress = (double)result * sign;
    } else if (sscan->length == LONG_DOUBLE) {
      sscan->adress = calloc(1, sizeof(long double));
      *(long double *)sscan->adress = result * sign;
    } else {
      sscan->adress = calloc(1, sizeof(float));
      *(float *)sscan->adress = (float)result * sign;
    }
  }
}

void get_s_flag(char **ptr, flags *sscan, int *return_result) {
  char buf_mas[4096] = {'\0'};
  int i = 0;

  while (**ptr != ' ' && **ptr != '\t' && **ptr != '\n' && **ptr != '\0') {
    buf_mas[i] = **ptr;
    *ptr += 1;
    i++;
  }
  buf_mas[i] = '\0';

  if (sscan->star != 1 && buf_mas[0] != '\0') {  // && buf_mas[0] != '\0'
    sscan->adress = calloc(i + 1, sizeof(char));
    s21_strcpy((char *)sscan->adress, (const char *)buf_mas);
    *return_result += 1;
  } else {
    sscan->fail = 1;
  }
}

long long int mod_atoi(char **ptr) {
  long long int result = 0;

  while (**ptr >= '0' && **ptr <= '9') {
    result *= 10;
    result += **ptr - '0';
    *ptr += 1;
  }

  return result;
}

void get_d_flag(char **ptr, flags *sscan, int *return_result) {
  long long int result = 0;
  int sign = 1;
  int flag = 0;

  if (**ptr == '-' || **ptr == '+') {
    sign = (**ptr == '-') ? -1 : 1;
    if (*(*ptr + 1) >= '0' && *(*ptr + 1) <= '9') {
      *ptr += 1;
    } else {
      sscan->fail = 1;
      flag = 1;
    }
  }

  if (!flag) {
    result = mod_atoi(ptr);
    result *= sign;

    if (sscan->star != 1) {
      if (sscan->length == SHORT_INT) {
        sscan->adress = calloc(1, sizeof(short int));
        *(short int *)sscan->adress = (short int)result;
      } else if (sscan->length == LONG_INT) {
        sscan->adress = calloc(1, sizeof(long int));
        *(long int *)sscan->adress = (long int)result;
      } else if (sscan->length == LONG_LONG_INT) {
        sscan->adress = calloc(1, sizeof(long long int));
        *(long long int *)sscan->adress = (long long int)result;
      } else {
        sscan->adress = calloc(1, sizeof(int));
        *(int *)sscan->adress = (int)result;  // SEGA
      }
    }
  }

  if (sscan->star != 1 && !flag && !sscan->fail) {
    *return_result += 1;
  }
}

void get_c_flag(char **ptr, flags *sscan, int *return_result) {
  char buf = **ptr;

  if (sscan->width > 0) {
    for (int i = 0; i < sscan->width; i++) {
      *ptr += 1;
    }
  } else {
    *ptr += 1;
  }

  if (sscan->star != 1) {
    sscan->adress = calloc(1, sizeof(char));
    *(char *)sscan->adress = buf;
    *return_result += 1;
  }
}

void get_value_from_format(char **str, flags *scan_format, int *return_result) {
  //    printf("sym = %c\n", scan_format -> specificator);
  if (scan_format->specificator == 'c') {
    //        printf("symbol = %c\n", **str);
    get_c_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'd') {
    go_to_symbol(str);
    get_d_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'f' ||
             scan_format->specificator == 'e' ||
             scan_format->specificator == 'E' ||
             scan_format->specificator == 'g' ||
             scan_format->specificator == 'G') {
    go_to_symbol(str);
    get_f_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 's') {
    go_to_symbol(str);
    get_s_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'u') {
    go_to_symbol(str);
    get_u_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'x' ||
             scan_format->specificator == 'X') {
    go_to_symbol(str);
    get_x_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'o') {
    go_to_symbol(str);
    get_o_flag(str, scan_format, return_result);
  } else if (scan_format->specificator == 'p') {
    go_to_symbol(str);
    get_p_flag(str, scan_format, return_result);
  }
}

void flag_length_parser(char **ptr, flags *sscan) {
  if (**ptr == 'h') {
    sscan->length = SHORT_INT;
    *ptr += 1;
  } else if (**ptr == 'l') {
    if (*(*ptr + 1) == 'l') {
      sscan->length = LONG_LONG_INT;
      *ptr += 1;
    }
    sscan->length = LONG_INT;
    *ptr += 1;
  } else if (**ptr == 'L') {
    sscan->length = LONG_DOUBLE;
    *ptr += 1;
  }
}

int is_digit(char symbol) {
  int return_value = 0;

  if (symbol >= '0' && symbol <= '9') {
    return_value = 1;
  }

  return return_value;
}

void flag_width_parser(char **ptr, flags *sscan) {
  if (is_digit(**ptr)) {
    //        printf("digit\n");
    char buf_mas[4096] = {'\0'};

    for (int i = 0; is_digit(**ptr); i++) {
      buf_mas[i] = **ptr;
      *ptr += 1;
    }

    sscan->width = atoi(buf_mas);
  }
}

void flag_star_parser(char **ptr, flags *sscan) {
  if (**ptr == '*') {
    sscan->star = 1;
    *ptr += 1;
  } else if (**ptr == ' ') {
    *ptr += 1;
  } else if (**ptr == '+') {
    *ptr += 1;
  } else if (**ptr == '-') {
    *ptr += 1;
  }
}

int is_space(char *ptr) {
  int return_result = 0;

  if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
    return_result = 1;
  }

  return return_result;
}

void go_to_symbol(char **ptr) {
  while (is_space(*ptr) && **ptr != '\0') {
    *ptr += 1;
  }
}

void null_struct(flags *struct_to_null) {
  struct_to_null->specificator = '0';
  struct_to_null->width = 0;
  struct_to_null->length = 0;
  struct_to_null->star = 0;
  struct_to_null->fail = 0;
  struct_to_null->percent_flag = 0;
  struct_to_null->adress = NULL;
}

void write_value(void *ptr, flags sscan) {
  if (sscan.specificator == 'd') {
    if (sscan.length == SHORT_INT) {
      *(short int *)ptr = *(short int *)sscan.adress;
    } else if (sscan.length == LONG_INT) {
      *(long int *)ptr = *(long int *)sscan.adress;
    } else if (sscan.length == LONG_LONG_INT) {
      *(long long int *)ptr = *(long long int *)sscan.adress;
    } else {
      *(int *)ptr = *(int *)sscan.adress;
    }
  } else if (sscan.specificator == 'c') {
    *(char *)ptr = *(char *)sscan.adress;
  } else if (sscan.specificator == 'f' || sscan.specificator == 'e' ||
             sscan.specificator == 'E' || sscan.specificator == 'g' ||
             sscan.specificator == 'G') {
    if (sscan.length == LONG_INT) {
      *(double *)ptr = *(double *)sscan.adress;
    } else if (sscan.length == LONG_DOUBLE) {
      *(long double *)ptr = *(long double *)sscan.adress;
    } else {
      *(float *)ptr = *(float *)sscan.adress;
    }
  } else if (sscan.specificator == 's') {
    s21_strcpy((char *)ptr, (char *)sscan.adress);
  } else if (sscan.specificator == 'x' || sscan.specificator == 'X' ||
             sscan.specificator == 'o' || sscan.specificator == 'u') {
    if (sscan.length == SHORT_INT) {
      *(unsigned short int *)ptr = *(unsigned short int *)sscan.adress;
    } else if (sscan.length == LONG_INT) {
      *(unsigned long int *)ptr = *(unsigned long int *)sscan.adress;
    } else if (sscan.length == LONG_LONG_INT) {
      *(unsigned long long int *)ptr = *(unsigned long long int *)sscan.adress;
    } else {
      *(unsigned int *)ptr = *(unsigned int *)sscan.adress;
    }
  } else if (sscan.specificator == 'p') {
    *(void **)ptr = *(void **)sscan.adress;
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  int result = 0;

  va_list factor;
  va_start(factor, format);

  flags scan_format;
  null_struct(&scan_format);

  while (*str != '\0' && *format != '\0' && !scan_format.fail) {
    if (is_space((char *)format) && *(format + 1) != '\0') {
      go_to_symbol((char **)&format);
      go_to_symbol((char **)&str);
    }
    if (*format != '%') {
      if (*format == *str) {
        str++;
        format++;
      } else {
        break;
      }
    } else {
      format++;
      if (*format == '%') {
        if (*str == '%') {
          format++;
          str++;
          scan_format.percent_flag = 1;
        } else {
          break;
        }
      }
    }
    if (!scan_format.percent_flag) {
      flag_star_parser((char **)&format, &scan_format);
      flag_width_parser((char **)&format, &scan_format);
      flag_length_parser((char **)&format, &scan_format);
      scan_format.specificator = *format;
      format++;
      if (*str == '\0' && scan_format.specificator != '0') {
        break;
      }
      if (scan_format.star == 0) {
        get_value_from_format((char **)&str, &scan_format, &result);
        if (!scan_format.fail) {
          write_value(va_arg(factor, void *), scan_format);
          if (scan_format.fail != 1) {
            free(scan_format.adress);
          }
        }
        null_struct(&scan_format);
      }
    }
    scan_format.percent_flag = 0;
  }

  return result;
}
