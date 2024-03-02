#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *str_copy = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_copy[i] = (str[i] - 'A') + 'a';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

void *s21_to_upper(const char *str) {
  char *str_copy = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_copy[i] = (str[i] - 'a') + 'A';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}

// simple strcpy
// char *s21_strcpy(char *dest, const char *src) {
//  int i = 0;
//  while (src[i] != '\0') {
//    dest[i] = src[i];
//    i++;
//  }
//  dest[i] = '\0';
//  return dest;
//}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if (src && str && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    new_str = (char *)malloc((src_len + str_len + 1) * sizeof(char));
    if (new_str) {
      s21_size_t n = 0;
      for (s21_size_t i = 0; i < start_index; i++) {
        new_str[n++] = src[i];
      }
      for (s21_size_t i = 0; i < str_len; i++) {
        new_str[n++] = str[i];
      }
      for (s21_size_t i = start_index; i <= src_len; i++) {
        new_str[n++] = src[i];
      }
    }
  }
  return new_str;
}

// trim-----------------------------

int s21_isspace(char a) {
  return a == ' ' || a == '\t' || a == '\n' || a == '\0';
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    char *begin_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*begin_str && s21_strchr(trim_chars, *begin_str)) {
      begin_str++;
    }
    while (end_str != begin_str && s21_strchr(trim_chars, *(end_str - 1))) {
      end_str--;
    }
    trim_str = (char *)calloc((end_str - begin_str + 1), sizeof(char));
    s21_strncpy(trim_str, begin_str, end_str - begin_str);
    *(trim_str + (end_str - begin_str)) = '\0';
  } else if (src != S21_NULL && trim_chars == S21_NULL) {
    char *begin_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*begin_str && s21_isspace(*begin_str)) {
      begin_str++;
    }
    while (end_str != begin_str && s21_isspace(*(end_str - 1))) {
      end_str--;
    }
    trim_str = (char *)calloc((end_str - begin_str + 1), sizeof(char));
    s21_strncpy(trim_str, begin_str, end_str - begin_str);
    *(trim_str + (end_str - begin_str)) = '\0';
  }
  return (void *)trim_str;
}
