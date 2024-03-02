#ifndef S21_STRINGS_H
#define S21_STRINGS_H

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define BUFF_SIZE 4096
#define S21_NULL (void *)0
typedef unsigned long s21_size_t;

typedef struct format_struct {
  int minus;
  int plus;
  int space;
  char length;
  int width;
  int zero;
  int prec;
  int isprec;
  char spec;
  int hash;
} format_t;

// #ifndef __APPLE__
// #define SIZE 106
// #define U_ERR "Unknown error:"
// #elif __linux__
// #define SIZE 133
// #define U_ERR "Unknown error"
// #endif

typedef struct {
  char specificator;
  int width;
  int length;
  int star;
  void *adress;
  int flag_space;
  int fail;
  int percent_flag;
} flags;

enum {
  SHORT_INT = 1,
  LONG_INT,  // также double для f
  LONG_LONG_INT,
  LONG_DOUBLE
};

void *s21_memchr(const void *str, int c, size_t n);             // tests +
int s21_memcmp(const void *str1, const void *str2, size_t n);   // tests +
void *s21_memcpy(void *dest, const void *src, size_t n);        // tests +
void *s21_memset(void *str, int c, size_t n);                   // test +
char *s21_strncat(char *dest, const char *src, size_t n);       // tests +
char *s21_strchr(const char *str, int c);                       // tests +
int s21_strncmp(const char *str1, const char *str2, size_t n);  // tests +
char *s21_strncpy(char *dest, const char *src, size_t n);       // tests +
size_t s21_strcspn(const char *str1, const char *str2);         // tests +
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);                          // tests +
char *s21_strpbrk(const char *str1, const char *str2);       // tests +
char *s21_strrchr(const char *str, int c);                   // tests +
char *s21_strstr(const char *haystack, const char *needle);  // tests +
char *s21_strtok(char *str, const char *delim);

size_t s21_strspn(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);

int s21_sscanf(const char *str, const char *format, ...);

// функции sprintf
int s21_sprintf(char *buf, const char *format, ...);
void s21_copy_to_buf(char *buf, const char *string, va_list p_args);
void s21_format_processing(const char *format, int *i, char *buf,
                           va_list p_args);
void s21_format_and_buff(int *i, char *buf, va_list p_args,
                         format_t format_data);
void s21_c_to_buf(const char c, format_t format_data, char *buf, int *i);
void s21_d_to_buf(int64_t d, format_t format_data, char *buf, int *i, int base);
void s21_format_flag(char *temp, format_t format_data, char *buf, int *i,
                     int mode);
void s21_f_to_buf(long double f, format_t params, char *buf, int *i);
char *s21_strcat(char *destination, const char *source);
void s21_s_to_buf(va_list p_args, format_t params, char *buf, int *i);
void s21_lc_to_buf(wchar_t c1, format_t params, char *buf, int *i);
void s21_u_to_buf(uint64_t d, format_t params, char *buf, int *i, int base);
void s21_gG_to_buf(long double f, format_t params, char *buf, int *i);
void s21_remove_trailing_zeroes(char *buf, int *i);
void s21_prepend_mantiss(char *buf, int pow, char sign, int *i);
void s21_uppcase(char *str);
void s21_parse_man(format_t params, char *buf, long double val, int *i);
void s21_o_to_buf(format_t params, char *buf, int64_t val, int *i);
void s21_xX_to_buf(format_t params, char *buf, int64_t val, int *i);
int s21_check_zeroes(char *buf);
void s21_p_to_buf(format_t params, char *buf, int64_t val, int *i);

// функции из 5 задания
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int find_ind(const char *src, const char *trim_chars, int index);

#endif
