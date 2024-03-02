
#include "s21_calc.h"

int s21_connect_number(char *prefix_str, double *result) {
  int output_result = SUCCESS;

  char *postfix_ptr = (char *)calloc(255, sizeof(char));
  char *postfix_str = postfix_ptr;
  char *postfix_to_free = postfix_str;

  output_result = string_parser_to_postfix(&prefix_str, &postfix_ptr);
  if (output_result == SUCCESS) {
    output_result = from_postfix_to_result(&postfix_str, result, 0);
  }

  free(postfix_to_free);

  return output_result;
}
