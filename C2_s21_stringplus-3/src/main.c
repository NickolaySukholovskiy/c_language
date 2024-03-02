
#include "s21_string.h"

int main() {
  char a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("k l", "%c%c", &a, &b);
  int sscanf_result_1 = sscanf("k l", "%c%c", &a_1, &b_1);

  printf("%c %c\n", a, b);
  printf("%c %c\n", a_1, b_1);

  printf("%d %d\n", sscanf_result, sscanf_result_1);

  return 0;
}
