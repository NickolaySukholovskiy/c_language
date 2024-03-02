
#include <check.h>
#include <string.h>

#include "s21_string.h"

#define str11 ""
#define str21 "str"
#define str31 "490u34902u4"
#define str41 "\t"
#define str51 "\n"
#define str61 NULL

#define str_11 "s"
#define str_21 "snakes from salivana"
#define str_31 "n"
#define str_41 "snana no najsdnsfsnnnnasdnan"
#define str_51 "a"

START_TEST(test_default) {
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %c", c);
  sprintf(assert, "Count: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default2) {
  char result[20];
  char assert[20];
  char c = 'b';
  s21_sprintf(result, "Count: %c", c);
  sprintf(assert, "Count: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default3) {
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %5c", c);
  int b = sprintf(assert, "Count: %5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default4) {
  char result[20];
  char assert[20];
  char c = 'b';
  int a = s21_sprintf(result, "Count: %-5c", c);
  int b = sprintf(assert, "Count: %-5c", c);
  ck_assert_str_eq(result, assert);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default5) {
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %lc", c);
  sprintf(assert, "Count: %lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default6) {
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %-3c", c);
  sprintf(assert, "Count: %-3c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default7) {  // need to fix '*'
  char result[20];
  char assert[20];
  char c = 'a';
  s21_sprintf(result, "Count: %*c", 4, c);
  sprintf(assert, "Count: %*c", 4, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default8) {
//   char result[20];
//   char assert[20];
//   long long d = 5717984;
//   s21_sprintf(result, "Count: %Li 1", d);
//   sprintf(assert, "Count: %Li 1", d);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default10) {
  char result[20];
  char assert[20];
  int d = 57;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default9) {
  char result[20];
  char assert[20];
  int d = 190;
  s21_sprintf(result, "Count: %5d", d);
  sprintf(assert, "Count: %5d", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default_multy) {
//   char result[20];
//   char assert[20];
//   s21_sprintf(result, "Count: %d%d%d%d", -4, 8, 15, 16);
//   sprintf(assert, "Count: %d%d%d%d", -4, 8, 15, 16);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_format_d) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1d", 69);
  sprintf(assert, "Count: %1.1d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_no_args) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Hello, world!");
  sprintf(assert, "Hello, world!");
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_flag_minus) {  // TO FIX
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %-5d", 69);
  sprintf(assert, "Count: %-5d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_default) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c", c);
  sprintf(assert, "Char: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_multy) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c%c%c", c, c, c);
  sprintf(assert, "Char: %c%c%c", c, c, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default11) {
  char result[20];
  char assert[20];
  int d = 571212;
  s21_sprintf(result, "Count: %.5d abc", d);
  sprintf(assert, "Count: %.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default12) {
  char result[20];
  char assert[20];
  int d = 5312112;
  s21_sprintf(result, "Count: %-.5d abc", d);
  sprintf(assert, "Count: %-.5d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default13) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default14) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default15) {
  char result[20];
  char assert[20];
  int d = 1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default16) {
  char result[20];
  char assert[20];
  int d = -1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default17) {
  char result[20];
  char assert[20];
  int d = -0;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default18) {
  char result[40];
  char assert[40];
  int d = 2147483647;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default19) {
  char result[40];
  char assert[40];
  int d = -2147483648;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default20) {
  char result[40];
  char assert[40];
  long int d = 214748364912;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default21) {
  char result[40];
  char assert[40];
  long int d = -9223372036854775807;
  s21_sprintf(result, "Count: % ld abc", d);
  sprintf(assert, "Count: % ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default22) {
  char result[40];
  char assert[40];
  long int d = 9223372036854775807;
  s21_sprintf(result, "Count: %ld abc", d);
  sprintf(assert, "Count: %ld abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default23) {
  char result[40];
  char assert[40];
  short int d = 32767;
  s21_sprintf(result, "Count: %hd abc", d);
  sprintf(assert, "Count: %hd abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default24) {
//   char result[40];
//   char assert[40];
//   short int d = 32770;
//   s21_sprintf(result, "Count: %hd end", d);
//   sprintf(assert, "Count: %hd end", d);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default25) {
  char result[40];
  char assert[40];
  int d = 327710;
  s21_sprintf(result, "Count: %11.10d end", d);
  sprintf(assert, "Count: %11.10d end", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default26) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i 1", i);
  sprintf(assert, "Count: %i 1", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default27) {
  char result[20];
  char assert[20];
  int i = 57;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default28) {
  char result[20];
  char assert[20];
  int i = 190;
  s21_sprintf(result, "Count: %5i", i);
  sprintf(assert, "Count: %5i", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default29) {
//   char result[20];
//   char assert[20];
//   s21_sprintf(result, "Count: %i%i%i%i", -4, 8, 15, 16);
//   sprintf(assert, "Count: %i%i%i%i", -4, 8, 15, 16);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default30) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1i", 69);
  sprintf(assert, "Count: %1.1i", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default31) {
  char result[20];
  char assert[20];
  int i = 571212;
  s21_sprintf(result, "Count: %.5i abc", i);
  sprintf(assert, "Count: %.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default32) {
  char result[20];
  char assert[20];
  int i = 5312112;
  s21_sprintf(result, "Count: %-.5i abc", i);
  sprintf(assert, "Count: %-.5i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default33) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default34) {
  char result[20];
  char assert[20];
  int i = 0;
  s21_sprintf(result, "Count: %i abc", i);
  sprintf(assert, "Count: %i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default35) {
  char result[20];
  char assert[20];
  int i = 1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default36) {
  char result[20];
  char assert[20];
  int i = -1;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default37) {
  char result[20];
  char assert[20];
  int i = -0;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default38) {
  char result[40];
  char assert[40];
  int i = 2147483647;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default39) {
  char result[40];
  char assert[40];
  int i = -2147483648;
  s21_sprintf(result, "Count: % i abc", i);
  sprintf(assert, "Count: % i abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default40) {
  char result[40];
  char assert[40];
  long int i = 214748364912;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default41) {
  char result[40];
  char assert[40];
  long int i = -9223372036854775807;
  s21_sprintf(result, "Count: % li abc", i);
  sprintf(assert, "Count: % li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default42) {
  char result[40];
  char assert[40];
  long int i = 9223372036854775807;
  s21_sprintf(result, "Count: %li abc", i);
  sprintf(assert, "Count: %li abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default43) {
  char result[40];
  char assert[40];
  short int i = 32767;
  s21_sprintf(result, "Count: %hi abc", i);
  sprintf(assert, "Count: %hi abc", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

// START_TEST(test_default44) {
//   char result[40];
//   char assert[40];
//   short int i = 32770;
//   s21_sprintf(result, "Count: %hi end", i);
//   sprintf(assert, "Count: %hi end", i);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_default45) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %5.10i end", i);
  sprintf(assert, "Count: %5.10i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default46) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %-+10.5i end", i);
  sprintf(assert, "Count: %-+10.5i end", i);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default47) {
  char result[40];
  char assert[40];
  int i = 327710;
  s21_sprintf(result, "Count: %+10.5i end", i + 1);
  sprintf(assert, "Count: %+10.5i end", i + 1);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default48) {
  char result[40];
  char assert[40];
  float f = -14.537;
  s21_sprintf(result, "Count: %.6f end", f);
  sprintf(assert, "Count: %.6f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default49) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "Count: %2.2f end", f);
  sprintf(assert, "Count: %2.2f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default50) {
  char result[40];
  char assert[40];
  float f = 1.0010021;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default51) {
  char result[40];
  char assert[40];
  float f = 0;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default52) {
  char result[40];
  char assert[40];
  float f = 0.;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default53) {
  char result[40];
  char assert[40];
  float f = -123.321;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default54) {
  char result[40];
  char assert[40];
  float f = 1.1234;
  s21_sprintf(result, "Count: %.*f end", 3, f);
  sprintf(assert, "Count: %.*f end", 3, f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default55) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %f end", f);
  sprintf(assert, "Count: %f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default56) {
  char result[40];
  char assert[40];
  float f = -.0000001;
  s21_sprintf(result, "Count: %10f end", f);
  sprintf(assert, "Count: %10f end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default57) {
  char result[40];
  char assert[40];
  double f = -.0000001;
  s21_sprintf(result, "Count: %3.5lf end", f);
  sprintf(assert, "Count: %3.5lf end", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(float_many) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *format = "% .0f %.lf %Lf %f %lf %Lf";
//   float val = 0;
//   double val1 = 0;
//   long double val2 = 3515315.153151;
//   float val3 = 5.5;
//   double val4 = 9851.51351;
//   long double val5 = 95919539159.53151351131;
//   ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4,
//   val5),
//                    sprintf(str2, format, val, val1, val2, val3, val4, val5));
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_many_float) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//
//   ck_assert_int_eq(
//       s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
//       sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_default58) {
  char result[40];
  char assert[40];
  float f = 14.537;
  s21_sprintf(result, "%+0.2f", f);
  sprintf(assert, "%+0.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default59) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %s abc", s);
  sprintf(assert, "Count: %s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default60) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "Count: %.3s abc", s);
  sprintf(assert, "Count: %.3s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default61) {
  char result[40];
  char assert[40];
  char *s = "none";
  s21_sprintf(result, "%.6s", s);
  sprintf(assert, "%.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default62) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%5.6s", s);
  sprintf(assert, "%5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default63) {
  char result[40];
  char assert[40];
  char *s = "stroka s probelom";
  s21_sprintf(result, "%-5.6s", s);
  sprintf(assert, "%-5.6s", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default64) {
  char result[40];
  char assert[40];
  wchar_t s[] = L"wide chars: ";
  s21_sprintf(result, "%-5.6ls", s);
  sprintf(assert, "%-5.6ls", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  s21_sprintf(str1, format, val), sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(string_many) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//
//   char *format = "%s%s%s%s";
//   char *val = "ADibsy8 ndASN) dun8AWn dA 9sDNsa NAID saDYBU DSnaJ Sd";
//   char *s1 = "";
//   char *s2 = "87418347813748913749871389480913";
//   char *s3 = "HAHAABOBASUCKER";
//   ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
//                    sprintf(str2, format, val, s1, s2, s3));
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "DASdw D sadw ASD"),
                   sprintf(str2, "%s", "DASdw D sadw ASD"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_many_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//
//   ck_assert_int_eq(
//       s21_sprintf(str1, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"),
//       sprintf(str2, "%s%s%s%s%s", "DASdw", " ", "sadw", " ", "ASD"));
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(wstr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %ls";
  wchar_t w[] = L"à";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wstr1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %5.12ls";
  wchar_t w[] = L"àààààà";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wstr2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %120hs ABOBA";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wstr3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wstr4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wchr2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %43lc 123";
  wchar_t w = L'B';
  // int a = s21_sprintf(str1, format, w);
  // int b =sprintf(str2, format, w);
  s21_sprintf(str1, format, w);
  sprintf(str2, format, w);
  // ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'1';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "wchar: %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
START_TEST(minus_wchr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %-5lc";
  unsigned long w = L'~';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_default65) {
  char result[20];
  char assert[20];
  unsigned int u = 571212;
  s21_sprintf(result, "Count: %.5u abc", u);
  sprintf(assert, "Count: %.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default66) {
  char result[20];
  char assert[20];
  unsigned int u = 5312112;
  s21_sprintf(result, "Count: %-.5u abc", u);
  sprintf(assert, "Count: %-.5u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default67) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default68) {
  char result[20];
  char assert[20];
  unsigned int u = 0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default69) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default70) {
  char result[20];
  char assert[20];
  unsigned int u = 1;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default71) {
  char result[20];
  char assert[20];
  unsigned int u = -0;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default72) {
  char result[40];
  char assert[40];
  unsigned int u = 2147483647;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default73) {
  char result[40];
  char assert[40];
  unsigned int u = -2147483648;
  s21_sprintf(result, "Count: %u abc", u);
  sprintf(assert, "Count: %u abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default74) {
  char result[40];
  char assert[40];
  unsigned long int u = 214748364912;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default75) {
  char result[40];
  char assert[40];
  unsigned long int u = -9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default76) {
  char result[40];
  char assert[40];
  unsigned long int u = 9223372036854775807;
  s21_sprintf(result, "Count: %lu abc", u);
  sprintf(assert, "Count: %lu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default77) {
  char result[40];
  char assert[40];
  unsigned short int u = 32767;
  s21_sprintf(result, "Count: %hu abc", u);
  sprintf(assert, "Count: %hu abc", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default78) {
  char result[40];
  char assert[40];
  unsigned short int u = 32770;
  s21_sprintf(result, "Count: %hu end", u);
  sprintf(assert, "Count: %hu end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default79) {
  char result[40];
  char assert[40];
  unsigned int u = 327710;
  s21_sprintf(result, "Count: %11.10u end", u);
  sprintf(assert, "Count: %11.10u end", u);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default80) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default81) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default82) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.1;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default83) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.55555;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default84) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.4;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default85) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 5;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default86) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default87) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default88) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default89) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default90) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default91) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default92) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG";
  long double hex = 0.000005;
  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_default93) {
//   char str1[BUFF_SIZE] = {'\0'};
//   char str2[BUFF_SIZE] = {'\0'};
//   char format[] = "%LG %g %G %Lg %.5g";
//   long double hex = 0.000005;
//   double hex1 = 41.1341;
//   double hex2 = 848.9000;
//   long double hex3 = 0.0843;
//   double hex4 = 0.0005;
//   double hex5 = 0.8481481;
//   s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5);
//   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5);
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
//
// START_TEST(test_default94) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *format = "%.17Le";
//   long double val = 15.35;
//   s21_sprintf(str1, format, val);
//   sprintf(str2, format, val);
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(test_default95) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default96) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default97) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default98) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default99) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default100) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%015E";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default101) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(test_default102) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *format = "% .0e %.le %Le %e %le %Le";
//   float val = 0;
//   double val1 = 0;
//   long double val2 = 3515315.153151;
//   float val3 = 5.5;
//   double val4 = 0.094913941;
//   long double val5 = 95919539159.53151351131;
//   s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
//   sprintf(str2, format, val, val1, val2, val3, val4, val5);
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(test_default103) {
//   char str1[BUFF_SIZE] = {'\0'};
//   char str2[BUFF_SIZE] = {'\0'};
//   char *format = "%.17LE";
//   long double val = 4134121;
//   s21_sprintf(str1, format, val);
//   sprintf(str2, format, val);
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(test_default104) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default105) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default106) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default107) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default108) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default109) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default110) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default111) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default112) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default113) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_default114) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//
//   char *format = "%lo, %o, %ho, %.5o, %5.o";
//   long int val = 949149114140;
//   ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
//                    sprintf(str2, format, val, (unsigned)14,
//                            (unsigned short)1441, (unsigned)14414,
//                            (unsigned)9681));
//
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_default115) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default116) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = -57175;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default117) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#- 10o";
  int val = -573375;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default118) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default119) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default120) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default121) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x %x %X %#x %#X %5.5x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val, val, val, val, val, val);
  sprintf(str2, format, val, val, val, val, val, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default122) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default123) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default124) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default125) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default126) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default127) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default128) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default129) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default130) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default131) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  s21_sprintf(str1, format, format);
  sprintf(str2, format, format);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default132) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = "(nil)";
  s21_sprintf(str1, format, ptr);
  sprintf(str2, format, ptr);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_default133) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "How many chars written before n %n";
  s21_sprintf(str1, format, &ret);
  sprintf(str2, format, &ret);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default134) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  s21_sprintf(str1, "%d%n", 123, &n1);
  sprintf(str2, "%d%n", 123, &n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_default135) {
  char result[512];
  char assert[512];
  char *d = "2147";
  s21_sprintf(result, "%101s", d);
  sprintf(assert, "%101s", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default136) {
  char result[512];
  char assert[512];
  char c = 'z';
  s21_sprintf(result, "Count: %12lc", c);
  sprintf(assert, "Count: %12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default137) {
  char result[20] = {'\0'};
  char assert[20] = {'\0'};
  char c = 'z';
  s21_sprintf(result, "Count: %-12lc", c);
  sprintf(assert, "Count: %-12lc", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default138) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "wchar: %lc";
  wchar_t w = L'A';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_percent) {
  char c[20];
  char d[20];
  int n = 100;
  s21_sprintf(c, "%% %d", n);
  sprintf(d, "%% %d", n);
  ck_assert_str_eq(c, d);
}
END_TEST

// START_TEST(sprintf_d) {
//   char c[128];
//   char d[128];
////  long int n = 9223372036854775807;
////  long int n2 = 9176543210987654321;
////  s21_sprintf(c, "%d %d %d %hd %hd %ld %ld %10ld", 7, 77, 777, 32767, 16396,
/// n, /              n2, n2); /  sprintf(d, "%d %d %d %hd %hd %ld %ld %10ld",
/// 7, 77, 777, 32767, 16396, n, n2, /          n2); /  ck_assert_str_eq(c, d);
//
//  s21_sprintf(c, "%-10d %10d %10d %*d %2d", 21, 14, 6, 10, 7, 84);
//  sprintf(d, "%-10d %10d %10d %*d %2d", 21, 14, 6, 10, 7, 84);
//  ck_assert_str_eq(c, d);
//
//  s21_sprintf(c,
//              "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d
//              %.0d", 10, 4, 55, 42, 21, 10, 4, 55, -21, 987, 21, -42);
//  sprintf(d, "%.*d %3.10d %.d %-+.5d %-+10.5d %.10d %.10d %2.2d %.d % d %.0d",
//          10, 4, 55, 42, 21, 10, 4, 55, -21, 987, 21, -42);
//  ck_assert_str_eq(c, d);
//}
// END_TEST

// START_TEST(sprintf_c) {
//   char c[60];
//   char d[60];
//   s21_sprintf(c, "%c %10c %-10c", '!', 'a', 'b');
//   sprintf(d, "%c %10c %-10c", '!', 'a', 'b');
//   ck_assert_str_eq(c, d);
//
//   s21_sprintf(c, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
//   sprintf(d, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
//   ck_assert_str_eq(c, d);
// }
// END_TEST

START_TEST(sprintf_s) {
  char c[60];
  char d[60];
  s21_sprintf(c, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
              "hello", "hello", "hello", "hello");
  sprintf(d, "%s %10s %-10s %-3s %.s %.3s %.10s", "hello", "hello", "hello",
          "hello", "hello", "hello", "hello");
  ck_assert_str_eq(c, d);

  s21_sprintf(c, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
              L"hello", L"hello", L"hello", L"hello", L"hello");
  sprintf(d, "%ls %10ls %-10ls %-3ls %.ls %.3ls %.10ls", L"hello", L"hello",
          L"hello", L"hello", L"hello", L"hello", L"hello");
  ck_assert_str_eq(c, d);
}
END_TEST

START_TEST(test_default139) {
  char result[40];
  char assert[40];
  char *s = NULL;
  s21_sprintf(result, "Count: %s abc", s);
  sprintf(assert, "Count: %s abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default140) {
  char result[40];
  char assert[40];
  wchar_t *s = NULL;
  s21_sprintf(result, "Count: %ls abc", s);
  sprintf(assert, "Count: %ls abc", s);
  ck_assert_str_eq(result, assert);
}
END_TEST

// №5 c# funcs

START_TEST(to_upper_test) {
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);

  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);

  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(to_lower_test) {
  char destination[] = "HERE W0 ARE123\0";
  char *test01 = s21_to_lower(destination);
  ck_assert_str_eq(test01, "here w0 are123");
  free(test01);

  char destination2[] = "HERE W0 ARE\n\0";
  char *test02 = s21_to_lower(destination2);
  ck_assert_str_eq(test02, "here w0 are\n");
  free(test02);

  char destination3[] = "A\n\0";
  char *test03 = s21_to_lower(destination3);
  ck_assert_str_eq(test03, "a\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_lower(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_lower(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_lower(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_lower(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "School-21 test";
  char *s2 = "insert ";
  char *s3 = "amogus";
  char *s4 = "is";
  char *s5 = "shrek";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "Sch ool-21 test");
  ck_assert_str_eq(res2, "shrekamogus");
  ck_assert_str_eq(res3, "shrekamogus");
  ck_assert_str_eq(res4, "shrekis");
  ck_assert_str_eq(res5, "inseSchool-21 testrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = NULL;
  char s3[] = "";
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = NULL;
  char *s3 = NULL;
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char src[] = "abCdfgdsabBCba";
  char charsToTrim[] = "abC";
  char *res1 = s21_trim(src, charsToTrim);
  char res2[] = "dfgdsabB";
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *s21_sprintf_csharp_funcs_suite(void) {
  Suite *s;
  TCase *tc_sprintf, *tc_csharp_funcs;

  s = suite_create("s21_sprintf_csharp_funcs suite");

  tc_sprintf = tcase_create("s21_sprintf case");
  tc_csharp_funcs = tcase_create("s21_csharp_funcs case");

  tcase_add_test(tc_sprintf, test_default);
  tcase_add_test(tc_sprintf, test_default2);
  tcase_add_test(tc_sprintf, test_default3);
  tcase_add_test(tc_sprintf, test_default4);
  tcase_add_test(tc_sprintf, test_default5);
  tcase_add_test(tc_sprintf, test_default6);
  tcase_add_test(tc_sprintf, test_default7);
  //  tcase_add_test(tc_sprintf, test_default8);
  tcase_add_test(tc_sprintf, test_default9);
  tcase_add_test(tc_sprintf, test_default10);
  tcase_add_test(tc_sprintf, test_default11);
  tcase_add_test(tc_sprintf, test_default12);
  tcase_add_test(tc_sprintf, test_default13);
  tcase_add_test(tc_sprintf, test_default14);
  tcase_add_test(tc_sprintf, test_default15);
  tcase_add_test(tc_sprintf, test_default16);
  tcase_add_test(tc_sprintf, test_default17);
  tcase_add_test(tc_sprintf, test_default18);
  tcase_add_test(tc_sprintf, test_default19);
  tcase_add_test(tc_sprintf, test_default20);
  tcase_add_test(tc_sprintf, test_default21);
  tcase_add_test(tc_sprintf, test_default22);
  tcase_add_test(tc_sprintf, test_default23);
  //  tcase_add_test(tc_sprintf, test_default24);
  tcase_add_test(tc_sprintf, test_default25);
  tcase_add_test(tc_sprintf, test_default26);
  tcase_add_test(tc_sprintf, test_default27);
  tcase_add_test(tc_sprintf, test_default28);
  //  tcase_add_test(tc_sprintf, test_default29);
  tcase_add_test(tc_sprintf, test_default30);
  tcase_add_test(tc_sprintf, test_default31);
  tcase_add_test(tc_sprintf, test_default32);
  tcase_add_test(tc_sprintf, test_default33);
  tcase_add_test(tc_sprintf, test_default34);
  tcase_add_test(tc_sprintf, test_default35);
  tcase_add_test(tc_sprintf, test_default36);
  tcase_add_test(tc_sprintf, test_default37);
  tcase_add_test(tc_sprintf, test_default38);
  tcase_add_test(tc_sprintf, test_default39);
  tcase_add_test(tc_sprintf, test_default40);
  tcase_add_test(tc_sprintf, test_default41);
  tcase_add_test(tc_sprintf, test_default42);
  tcase_add_test(tc_sprintf, test_default43);
  //  tcase_add_test(tc_sprintf, test_default44);
  tcase_add_test(tc_sprintf, test_default45);
  tcase_add_test(tc_sprintf, test_default46);
  tcase_add_test(tc_sprintf, test_default47);
  tcase_add_test(tc_sprintf, test_default48);
  tcase_add_test(tc_sprintf, test_default49);
  tcase_add_test(tc_sprintf, test_default50);
  tcase_add_test(tc_sprintf, test_default51);
  tcase_add_test(tc_sprintf, test_default52);
  tcase_add_test(tc_sprintf, test_default53);
  tcase_add_test(tc_sprintf, test_default54);
  tcase_add_test(tc_sprintf, test_default55);
  tcase_add_test(tc_sprintf, test_default56);
  tcase_add_test(tc_sprintf, test_default57);
  tcase_add_test(tc_sprintf, test_default58);
  tcase_add_test(tc_sprintf, test_default59);
  tcase_add_test(tc_sprintf, test_default60);
  tcase_add_test(tc_sprintf, test_default61);
  tcase_add_test(tc_sprintf, test_default62);
  tcase_add_test(tc_sprintf, test_default63);
  tcase_add_test(tc_sprintf, test_default64);
  tcase_add_test(tc_sprintf, test_default65);
  tcase_add_test(tc_sprintf, test_default66);
  tcase_add_test(tc_sprintf, test_default67);
  tcase_add_test(tc_sprintf, test_default68);
  tcase_add_test(tc_sprintf, test_default69);
  tcase_add_test(tc_sprintf, test_default70);
  tcase_add_test(tc_sprintf, test_default71);
  tcase_add_test(tc_sprintf, test_default72);
  tcase_add_test(tc_sprintf, test_default73);
  tcase_add_test(tc_sprintf, test_default74);
  tcase_add_test(tc_sprintf, test_default75);
  tcase_add_test(tc_sprintf, test_default76);
  tcase_add_test(tc_sprintf, test_default77);
  tcase_add_test(tc_sprintf, test_default78);
  tcase_add_test(tc_sprintf, test_default79);
  tcase_add_test(tc_sprintf, test_default80);
  tcase_add_test(tc_sprintf, test_default81);
  tcase_add_test(tc_sprintf, test_default82);
  tcase_add_test(tc_sprintf, test_default83);
  tcase_add_test(tc_sprintf, test_default84);
  tcase_add_test(tc_sprintf, test_default85);
  tcase_add_test(tc_sprintf, test_default86);
  tcase_add_test(tc_sprintf, test_default87);
  tcase_add_test(tc_sprintf, test_default88);
  tcase_add_test(tc_sprintf, test_default89);
  tcase_add_test(tc_sprintf, test_default90);
  tcase_add_test(tc_sprintf, test_default91);
  tcase_add_test(tc_sprintf, test_default92);
  //  tcase_add_test(tc_sprintf, test_default93);
  //  tcase_add_test(tc_sprintf, test_default94);
  tcase_add_test(tc_sprintf, test_default95);
  tcase_add_test(tc_sprintf, test_default96);
  tcase_add_test(tc_sprintf, test_default97);
  tcase_add_test(tc_sprintf, test_default98);
  tcase_add_test(tc_sprintf, test_default99);
  tcase_add_test(tc_sprintf, test_default100);
  tcase_add_test(tc_sprintf, test_default101);
  //  tcase_add_test(tc_sprintf, test_default102);
  //  tcase_add_test(tc_sprintf, test_default103);
  tcase_add_test(tc_sprintf, test_default104);
  tcase_add_test(tc_sprintf, test_default105);
  tcase_add_test(tc_sprintf, test_default106);
  tcase_add_test(tc_sprintf, test_default107);
  tcase_add_test(tc_sprintf, test_default108);
  tcase_add_test(tc_sprintf, test_default109);
  tcase_add_test(tc_sprintf, test_default110);
  tcase_add_test(tc_sprintf, test_default111);
  tcase_add_test(tc_sprintf, test_default112);
  tcase_add_test(tc_sprintf, test_default113);
  //  tcase_add_test(tc_sprintf, test_default114);
  tcase_add_test(tc_sprintf, test_default115);
  tcase_add_test(tc_sprintf, test_default116);
  tcase_add_test(tc_sprintf, test_default117);
  tcase_add_test(tc_sprintf, test_default118);
  tcase_add_test(tc_sprintf, test_default119);
  tcase_add_test(tc_sprintf, test_default120);
  tcase_add_test(tc_sprintf, test_default121);
  tcase_add_test(tc_sprintf, test_default122);
  tcase_add_test(tc_sprintf, test_default123);
  tcase_add_test(tc_sprintf, test_default124);
  tcase_add_test(tc_sprintf, test_default125);
  tcase_add_test(tc_sprintf, test_default126);
  tcase_add_test(tc_sprintf, test_default127);
  tcase_add_test(tc_sprintf, test_default128);
  tcase_add_test(tc_sprintf, test_default129);
  tcase_add_test(tc_sprintf, test_default130);
  tcase_add_test(tc_sprintf, test_default131);
  tcase_add_test(tc_sprintf, test_default132);
  tcase_add_test(tc_sprintf, test_default133);
  tcase_add_test(tc_sprintf, test_default134);
  tcase_add_test(tc_sprintf, test_default135);
  tcase_add_test(tc_sprintf, test_default136);
  tcase_add_test(tc_sprintf, test_default137);
  tcase_add_test(tc_sprintf, test_default138);
  tcase_add_test(tc_sprintf, test_default139);
  tcase_add_test(tc_sprintf, test_default140);
  tcase_add_test(tc_sprintf, string);
  tcase_add_test(tc_sprintf, string_precision);
  tcase_add_test(tc_sprintf, string_width);
  tcase_add_test(tc_sprintf, string_flags);
  tcase_add_test(tc_sprintf, string_long);
  //  tcase_add_test(tc_sprintf, string_many);
  tcase_add_test(tc_sprintf, string_width_huge);
  tcase_add_test(tc_sprintf, test_one_string);
  //  tcase_add_test(tc_sprintf, test_many_string);
  tcase_add_test(tc_sprintf, wstr);
  tcase_add_test(tc_sprintf, wstr1);
  tcase_add_test(tc_sprintf, wstr2);
  tcase_add_test(tc_sprintf, wstr3);
  tcase_add_test(tc_sprintf, wstr4);
  tcase_add_test(tc_sprintf, wchr2);
  tcase_add_test(tc_sprintf, wchr);
  tcase_add_test(tc_sprintf, width_char);
  tcase_add_test(tc_sprintf, minus_wchr);
  tcase_add_test(tc_sprintf, float_precision);
  tcase_add_test(tc_sprintf, float_width);
  tcase_add_test(tc_sprintf, float_precision_zero);
  tcase_add_test(tc_sprintf, float_precision_empty);
  tcase_add_test(tc_sprintf, float_precision_huge);
  tcase_add_test(tc_sprintf, float_precision_huge_negative);
  tcase_add_test(tc_sprintf, float_huge);
  tcase_add_test(tc_sprintf, float_flags);
  //  tcase_add_test(tc_sprintf, float_many);
  tcase_add_test(tc_sprintf, test_one_float);
  //  tcase_add_test(tc_sprintf, test_many_float);
  //  tcase_add_test(tc_sprintf, test_default_multy);
  tcase_add_test(tc_sprintf, test_no_args);
  tcase_add_test(tc_sprintf, test_format_d);
  tcase_add_test(tc_sprintf, test_flag_minus);
  tcase_add_test(tc_sprintf, sprintf_percent);
  //  tcase_add_test(tc_sprintf, sprintf_d);
  //  tcase_add_test(tc_sprintf, sprintf_c);
  tcase_add_test(tc_sprintf, sprintf_s);
  tcase_add_test(tc_sprintf, test_char_default);
  tcase_add_test(tc_sprintf, test_char_multy);

  tcase_add_test(tc_csharp_funcs, to_upper_test);
  tcase_add_test(tc_csharp_funcs, to_lower_test);
  tcase_add_test(tc_csharp_funcs, insert_test);
  tcase_add_test(tc_csharp_funcs, test_trim_1);
  tcase_add_test(tc_csharp_funcs, test_trim_2);
  tcase_add_test(tc_csharp_funcs, test_trim_3);
  tcase_add_test(tc_csharp_funcs, test_trim_4);
  tcase_add_test(tc_csharp_funcs, test_trim_5);
  tcase_add_test(tc_csharp_funcs, test_trim_6);
  tcase_add_test(tc_csharp_funcs, test_trim_7);
  tcase_add_test(tc_csharp_funcs, test_trim_8);
  tcase_add_test(tc_csharp_funcs, test_trim_9);
  tcase_add_test(tc_csharp_funcs, test_trim_10);

  suite_add_tcase(s, tc_sprintf);
  suite_add_tcase(s, tc_csharp_funcs);

  return s;
}

// sscanf + string.h

START_TEST(test_strlen) {
  ck_assert_uint_eq(strlen(str11), s21_strlen(str11));
  ck_assert_uint_eq(strlen(str21), s21_strlen(str21));
  ck_assert_uint_eq(strlen(str31), s21_strlen(str31));
  ck_assert_uint_eq(strlen(str41), s21_strlen(str41));
  ck_assert_uint_eq(strlen(str51), s21_strlen(str51));
  //    ck_assert_uint_eq(strlen(str61), s21_strlen(str61)); // SEGA
}

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strlen");
  tcase_add_test(tc_core, test_strlen);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_memchr) {
  //  ck_assert_ptr_eq(s21_memchr(str_21, 's', 0), memchr(str_21, 's', 0));
  ck_assert_ptr_eq(s21_memchr(str_21, 's', 50), memchr(str_21, 's', 50));
  ck_assert_ptr_eq(s21_memchr(str_41, 'a', 10), memchr(str_41, 'a', 10));
  ck_assert_ptr_eq(s21_memchr(str_41, 's', 10), memchr(str_41, 's', 10));
  ck_assert_ptr_eq(
      s21_memchr(str11, 'q', 10),
      memchr(str11, 'q', 10));  // оригинальная функция сделана криво
  //    ck_assert_float_eq((char*)s21_memchr(NULL, 'n', 10) - str_41,
  //    (char*)memchr(NULL, 'n', 10) - str_41); // SEGA
}

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("memchr");
  tcase_add_test(tc_core, test_memchr);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_memcmp) {
  //    ck_assert_int_eq(s21_memcmp(str11, str11, 4), memcmp(str11, str11, 4));
  ck_assert_int_eq(s21_memcmp(str11, str11, 0), memcmp(str11, str11, 0));
  //    ck_assert_uint_eq(s21_memcmp(str61, str21, 1), memcmp(str61, str21, 1));
  //    // SEGA
  ck_assert_int_eq(s21_memcmp(str11, str21, 1), memcmp(str11, str21, 1));
  ck_assert_int_eq(s21_memcmp(str21, str11, 1), memcmp(str21, str11, 1));
  ck_assert_int_eq(s21_memcmp(str51, str41, 1), memcmp(str51, str41, 1));
  //    ck_assert_int_eq(s21_memcmp(str_41, str_41, 50), memcmp(str_41, str_41,
  //    5000));
  // ck_assert_int_eq(s21_memcmp(str_11, str_41, 50), memcmp(str_11, str_41,
  // 50));
}

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("memcmp");
  tcase_add_test(tc_core, test_memcmp);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_memcpy) {
  char buf_mas_1[7];
  //    char buf_mas_2[3];
  char buf_mas_3[8] = "pds";

  ck_assert_str_eq(s21_memcpy(buf_mas_1, str21, 3),
                   memcpy(buf_mas_1, str21, 3));
  //    ck_assert_str_eq(s21_memcpy(buf_mas_2, str11, 3), memcpy(buf_mas_2,
  //    str11, 3)); ck_assert_str_eq(s21_memcpy(buf_mas_1, str21, 5),
  //    memcpy(buf_mas_1, str21, 5)); ck_assert_str_eq(s21_memcpy(buf_mas_1,
  //    str21, 5), memcpy(buf_mas_1, str21, 5));
  //    ck_assert_str_eq(s21_memcpy(buf_mas_3, str21, 5), memcpy(buf_mas_3,
  //    str21, 5));
  ck_assert_str_eq(s21_memcpy(buf_mas_3, str_31, 1),
                   memcpy(buf_mas_3, str_31, 1));
}

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("memcmp");
  tcase_add_test(tc_core, test_memcpy);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_memset) {
  char buf_mas_1[7];
  char buf_mas_2[3];
  char buf_mas_3[8] = "pds";
  //    char buf_mas_4[] = "";

  ck_assert_str_eq(s21_memset(buf_mas_1, 'd', 3), memset(buf_mas_1, 'd', 3));
  ck_assert_str_eq(s21_memset(buf_mas_2, 1, 2), memset(buf_mas_2, 1, 2));
  ck_assert_str_eq(s21_memset(buf_mas_1, '\0', 5), memset(buf_mas_1, '\0', 5));
  ck_assert_str_eq(s21_memset(buf_mas_1, '?', 4), memset(buf_mas_1, '?', 4));
  ck_assert_str_eq(s21_memset(buf_mas_3, 'p', 4), memset(buf_mas_3, 'p', 4));
  ck_assert_str_eq(s21_memset(buf_mas_3, 0, 1), memset(buf_mas_3, 0, 1));
  ck_assert_str_eq(s21_memset(buf_mas_1, '?', 3), memset(buf_mas_1, '?', 3));
  //    ck_assert_str_eq(s21_memset(buf_mas_4, '?', 1), memset(buf_mas_4, '?',
  //    1));
}

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("memset");
  tcase_add_test(tc_core, test_memset);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strncat) {
  char buf_mas_1[7] = "a";
  char buf_mas_2[3] = "";
  //    char buf_mas_3[8] = "pds";
  char buf_mas_4[] = "";
  //
  //    ck_assert_str_eq(s21_strncat(buf_mas_3, "str", 5), strncat(buf_mas_3,
  //    "str", 5)); // I don't know
  ck_assert_str_eq(s21_strncat(buf_mas_1, "str", 2),
                   strncat(buf_mas_1, "str", 2));
  ck_assert_str_eq(s21_strncat(buf_mas_4, "str", 0),
                   strncat(buf_mas_4, "str", 0));
  //    ck_assert_str_eq(s21_strncat(NULL, "str", 2), strncat(NULL, "str", 2));
  //    // SEGA ck_assert_str_eq(s21_strncat(buf_mas_1, NULL, 2),
  //    strncat(buf_mas_1, NULL, 2)); // SEGA
  //    ck_assert_str_eq(s21_strncat(buf_mas_2, "string", 7), strncat(buf_mas_2,
  //    "string", 7)); // SEGA
  ck_assert_str_eq(s21_strncat(buf_mas_2, "", 2), strncat(buf_mas_2, "", 2));
  ck_assert_str_eq(s21_strncat(buf_mas_1, buf_mas_2, 5),
                   strncat(buf_mas_1, buf_mas_2, 5));
}

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strncat");
  tcase_add_test(tc_core, test_strncat);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strchr) {
  ck_assert_ptr_eq(s21_strchr(str21, 't'), strchr(str21, 't'));
  ck_assert_ptr_eq(s21_strchr(str21, '\0'), strchr(str21, '\0'));
  //    ck_assert_ptr_eq(s21_strchr(NULL, 't'), strchr(NULL, 't')); // SEGA
  //    ck_assert_ptr_eq(s21_strchr(str11, 't'), strchr(str11, 't')); // SEGA
  ck_assert_ptr_eq(s21_strchr(str_31, 't'), strchr(str_31, 't'));
  ck_assert_ptr_eq(s21_strchr(str_41, 'j'), strchr(str_41, 'j'));
  ck_assert_ptr_eq(s21_strchr(str_41, 34), strchr(str_41, 34));
  ck_assert_ptr_eq(s21_strchr(str11, 'j'), strchr(str11, 'j'));
  ck_assert_ptr_eq(s21_strchr(str11, '\0'), strchr(str11, '\0'));
}

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strchr");
  tcase_add_test(tc_core, test_strchr);
  suite_add_tcase(s, tc_core);

  return s;
}

// START_TEST(test_strncmp) {
//   ck_assert_int_eq(s21_strncmp(str11, str21, 5), strncmp(str11, str21, 5));
//   //    ck_assert_int_eq(s21_strncmp(NULL, str21, 5), strncmp(NULL, str21,
//   5));
//   //    // SEGA ck_assert_int_eq(s21_strncmp(str11, NULL, 5), strncmp(str11,
//   //    NULL, 5)); // SEGA
//   ck_assert_int_eq(s21_strncmp(str_11, str_21, 2), strncmp(str_11, str_21,
//   2)); ck_assert_int_eq(s21_strncmp(str_11, str_21, 1), strncmp(str_11,
//   str_21, 1)); ck_assert_int_eq(s21_strncmp(str_11, str_21, 0),
//   strncmp(str_11, str_21, 0)); ck_assert_int_eq(s21_strncmp(str_11, str_21,
//   -2),
//                    strncmp(str_11, str_21, -2));
//   ck_assert_int_eq(s21_strncmp(str11, str11, 2), strncmp(str11, str11, 2));
//   ck_assert_int_eq(s21_strncmp(str_41, str_41, 15),
//                    strncmp(str_41, str_41, 15));
// }

// Suite *strncmp_suite(void) {
//   Suite *s;
//   TCase *tc_core = tcase_create("core");

//   s = suite_create("strncmp");
//   tcase_add_test(tc_core, test_strncmp);
//   suite_add_tcase(s, tc_core);

//   return s;
// }

START_TEST(test_strncpy) {
  //  char buf_mas_1[10] = "";
  char buf_mas_2[10] = "a";

  //  ck_assert_str_eq(s21_strncpy(buf_mas_1, str21, 5),
  //                   strncpy(buf_mas_1, str21, 5));
  //    printf("buf = %s\n", buf_mas_1);
  //  ck_assert_str_eq(s21_strncpy(buf_mas_1, str21, 1),
  //                   strncpy(buf_mas_1, str21, 1));
  //  ck_assert_str_eq(s21_strncpy(buf_mas_2, str11, 5),
  //                   strncpy(buf_mas_2, str11, 5));
  //  ck_assert_str_eq(s21_strncpy(buf_mas_1, str21, 0),
  //                   strncpy(buf_mas_1, str21, 0));
  //    ck_assert_str_eq(s21_strncpy(buf_mas_1, str_41, 10), strncpy(buf_mas_1,
  //    str_41, 10)); ck_assert_str_eq(s21_strncpy(NULL, str_41, 10),
  //    strncpy(NULL, str_41, 10)); // SEGA ck_assert_str_eq(s21_strncpy(NULL,
  //    NULL, 10), strncpy(NULL, NULL, 10)); // SEGA

  ck_assert_str_eq(s21_strncpy(buf_mas_2, "str11", 7),
                   strncpy(buf_mas_2, "str11", 7));
}

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strncpy");
  tcase_add_test(tc_core, test_strncpy);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strcspn) {
  ck_assert_int_eq((int)s21_strcspn("123456789", "789"),
                   (int)strcspn("123456789", "789"));

  ck_assert_int_eq((int)s21_strcspn("asdfwefafads", "789"),
                   (int)strcspn("asdfwefafads", "789"));
}

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strcspn");
  tcase_add_test(tc_core, test_strcspn);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk(str11, str21), strpbrk(str11, str21));
  //    ck_assert_ptr_eq(s21_strpbrk(str31, str21), strpbrk(str31, str21));
  //    ck_assert_ptr_eq(s21_strpbrk(NULL, str21), strpbrk(NULL, str21)); //
  //    SEGA
  ck_assert_ptr_eq(s21_strpbrk(str_21, str_11), strpbrk(str_21, str_11));
  ck_assert_ptr_eq(s21_strpbrk(str_11, str_21), strpbrk(str_11, str_21));
  ck_assert_ptr_eq(s21_strpbrk(str41, str51), strpbrk(str41, str_51));
  ck_assert_ptr_eq(s21_strpbrk(str_21, str_41), strpbrk(str_21, str_41));
  ck_assert_ptr_eq(s21_strpbrk(str_21, str11), strpbrk(str_21, str11));
}

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strpbrk");
  tcase_add_test(tc_core, test_strpbrk);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strrchr) {
  ck_assert_ptr_eq(s21_strrchr(str11, 1), s21_strrchr(str11, 1));
  ck_assert_ptr_eq(s21_strrchr(str21, 'r'), s21_strrchr(str21, 'r'));
  ck_assert_ptr_eq(s21_strrchr(str31, '\0'), s21_strrchr(str31, '\0'));
  //    ck_assert_ptr_eq(s21_strrchr(NULL, '?'), s21_strrchr(NULL, '?')); //
  //    SEGA
  ck_assert_ptr_eq(s21_strrchr(str_41, str_51[0]),
                   s21_strrchr(str_41, str_51[0]));
  ck_assert_ptr_eq(s21_strrchr(str_41, 127), s21_strrchr(str_41, 127));
}

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strrchr");
  tcase_add_test(tc_core, test_strrchr);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strspn) {
  ck_assert_int_eq((int)s21_strspn("123456789", "12"),
                   (int)strspn("123456789", "12"));
}

Suite *strspn_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strspn");
  tcase_add_test(tc_core, test_strspn);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strstr) {
  ck_assert_ptr_eq(s21_strstr(str11, str21), strstr(str11, str21));
  ck_assert_ptr_eq(s21_strstr(str21, str31), strstr(str21, str31));
  ck_assert_ptr_eq(s21_strstr(str_41, str_51), strstr(str_41, str_51));
  ck_assert_ptr_eq(s21_strstr(str_51, str_41), strstr(str_51, str_41));
  ck_assert_ptr_eq(s21_strstr(str_41, "j"), strstr(str_41, "j"));
}

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strstr");
  tcase_add_test(tc_core, test_strstr);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strtok_1) {
  char buf_mas_1[] = "stroka s probelami i tochkoy.";
  char buf_mas_2[] = "stroka s probelami i tochkoy.";
  char *ptr_1 = s21_strtok(buf_mas_1, " .");
  char *ptr_2 = strtok(buf_mas_2, " .");

  ck_assert_str_eq(ptr_1, ptr_2);

  while (ptr_1 != NULL && ptr_2 != NULL) {
    ck_assert_str_eq(ptr_1, ptr_2);
    ptr_1 = s21_strtok(NULL, " .");
    ptr_2 = strtok(NULL, " .");
  }
}

START_TEST(test_strtok_2) {
  char buf_mas_1[] = "str";
  char buf_mas_2[] = "str";
  char *ptr_1 = s21_strtok(buf_mas_1, " .");
  char *ptr_2 = strtok(buf_mas_2, " .");

  ck_assert_str_eq(ptr_1, ptr_2);

  while (ptr_1 != NULL && ptr_2 != NULL) {
    ck_assert_str_eq(ptr_1, ptr_2);
    ptr_1 = s21_strtok(NULL, " .");
    ptr_2 = strtok(NULL, " .");
  }
}

START_TEST(test_strtok_3) {
  char buf_mas_1[] = "";
  char buf_mas_2[] = "";
  char *ptr_1 = s21_strtok(buf_mas_1, " .");
  char *ptr_2 = strtok(buf_mas_2, " .");

  ck_assert_ptr_null(ptr_1);
  ck_assert_ptr_null(ptr_2);
}

// START_TEST(test_strtok_4) {
//   char *ptr_1 = s21_strtok(NULL, " .");
//   char *ptr_2 = strtok(NULL, " .");

//   ck_assert_ptr_null(ptr_1);
//   ck_assert_ptr_null(ptr_2);
// }

Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strtok");
  tcase_add_test(tc_core, test_strtok_1);
  tcase_add_test(tc_core, test_strtok_2);
  tcase_add_test(tc_core, test_strtok_3);
  // tcase_add_test(tc_core, test_strtok_4);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_strerror) {
  ck_assert_str_eq(s21_strerror(1), strerror(1));
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(47), strerror(47));
}

Suite *strerror_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("strerror");
  tcase_add_test(tc_core, test_strerror);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sscanf_parsers_1) {
  int a = 0, a_1 = 0;

  int sscanf_result = s21_sscanf("10", "%*d");
  int sscanf_result_1 = sscanf("10", "%*d");

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
}

START_TEST(test_sscanf_parsers_2) {
  long double a1 = 0, a2 = 0;
  double b1 = 0, b2 = 0;
  float c1 = 0, c2 = 0;

  const char str[] = "5555.555555552*xui*3.345*-0.00000001";
  const char fstr[] = "%f*%*s*%lf*%Lf";

  int res1 = s21_sscanf(str, fstr, &c1, &b1, &a1);
  int res2 = sscanf(str, fstr, &c2, &b2, &a2);

  ck_assert_float_eq(c1, c2);
  ck_assert_double_eq(b1, b2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_sscanf_parsers_3) {
  double a1 = 0, a2 = 0;

  const char str[] = "6e-5";
  const char fstr[] = "%le";

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);

  ck_assert_double_eq_tol(a1, a2, 1e-6);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_sscanf_parsers_4) {
  unsigned short int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  unsigned long int c1 = 0, c2 = 0;
  const char str[] = "653235FD1248-245";
  const char fstr[] = "%ho%x%lu";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_sscanf_all_1) {
  int a = 0, b = 0, a_1 = 0, b_1 = 0;
  float c = 0, c_1 = 0;
  char symbol = 0, symbol_1 = 0;

  int sscanf_result =
      s21_sscanf("10ef k 5.5% 2", "%x%c    %f %% %d", &a, &symbol, &c, &b);
  int sscanf_result_1 = sscanf("10ef k 5.5% 2", "%x%c      %f %% %d", &a_1,
                               &symbol_1, &c_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
  ck_assert_float_eq(c, c_1);
  ck_assert_int_eq(symbol, symbol_1);
}

START_TEST(test_sscanf_all_2) {
  int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("3    2 ", "%d %d", &a, &b);
  int sscanf_result_1 = sscanf("3    2 ", "%d %d", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_all_3) {
  char str_a[50] = "", str_a_1[50] = "";
  char str_b[50] = "", str_b_1[50] = "";

  int sscanf_result = s21_sscanf("klaus%str ", "%s%%%s", str_a, str_b);
  int sscanf_result_1 = sscanf("klaus%str ", "%s%%%s", str_a_1, str_b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_str_eq(str_a, str_a_1);
  ck_assert_str_eq(str_b, str_b_1);
}

START_TEST(test_sscanf_all_4) {
  char str_a[50] = "", str_a_1[50] = "";
  int a = 0, a_1 = 0;

  int sscanf_result = s21_sscanf("123%str ", "%d%%%s", &a, str_a);
  int sscanf_result_1 = sscanf("123%str ", "%d%%%s", &a_1, str_a_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_str_eq(str_a, str_a_1);
}

START_TEST(test_sscanf_all_5) {
  char str_a[50] = "", str_a_1[50] = "";
  char str_b[50] = "", str_b_1[50] = "";
  char symbol = 0, symbol_1 = 0;

  int sscanf_result = s21_sscanf("klaus cool", "%s%c%s", str_a, &symbol, str_b);
  int sscanf_result_1 =
      sscanf("klaus cool", "%s%c%s", str_a_1, &symbol_1, str_b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(symbol, symbol_1);
  ck_assert_str_eq(str_a, str_a_1);
  ck_assert_str_eq(str_b, str_b_1);
}

START_TEST(test_sscanf_all_6) {
  int a = 0, a_1 = 0;
  unsigned int b = 0, b_1 = 0;
  float c = 0, c_1 = 0;

  int sscanf_result = s21_sscanf("0 0 0", "%d%u%f", &a, &b, &c);
  int sscanf_result_1 = sscanf("0 0 0", "%d%u%f", &a_1, &b_1, &c_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_uint_eq(b, b_1);
  ck_assert_float_eq(c, c_1);
}

START_TEST(test_sscanf_d_1) {
  int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10 43", "%d %d", &a, &b);
  int sscanf_result_1 = sscanf("10 43", "%d %d", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_d_2) {
  int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10 -43", "%d%d", &a, &b);
  int sscanf_result_1 = sscanf("10 -43", "%d%d", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_f_1) {
  float a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10.4 43.543", "%f %f", &a, &b);
  int sscanf_result_1 = sscanf("10.4 43.543", "%f %f", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_float_eq(a, a_1);
  ck_assert_float_eq(b, b_1);
}

START_TEST(test_sscanf_f_2) {
  float a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10.4 -43.543", "%f%f", &a, &b);
  int sscanf_result_1 = sscanf("10.4 -43.543", "%f%f", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_float_eq(a, a_1);
  ck_assert_float_eq(b, b_1);
}

START_TEST(test_sscanf_c_1) {
  char a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("k l", "%c%c", &a, &b);
  int sscanf_result_1 = sscanf("k l", "%c%c", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_c_2) {
  char a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("k \nl", "%c   %c", &a, &b);
  int sscanf_result_1 = sscanf("k \nl", "%c    %c", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_s_1) {
  char str[50] = "", str_11a[50] = "";

  int sscanf_result = s21_sscanf("klaus", "%s", str);
  int sscanf_result_1 = sscanf("klaus", "%s", str_11a);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_str_eq(str, str_11a);
}

START_TEST(test_sscanf_s_2) {
  char str_a[50] = "", str_a_1[50] = "";
  char str_b[50] = "", str_b_1[50] = "";

  int sscanf_result = s21_sscanf("klaus ", "%s%s", str_a, str_b);
  int sscanf_result_1 = sscanf("klaus ", "%s%s", str_a_1, str_b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_str_eq(str_a, str_a_1);
  ck_assert_str_eq(str_b, str_b_1);
}

START_TEST(test_sscanf_s_3) {
  char str_a[50] = "", str_a_1[50] = "";
  char str_b[50] = "", str_b_1[50] = "";

  int sscanf_result = s21_sscanf("klaus cool", "%s%s", str_a, str_b);
  int sscanf_result_1 = sscanf("klaus cool", "%s%s", str_a_1, str_b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_str_eq(str_a, str_a_1);
  ck_assert_str_eq(str_b, str_b_1);
}

START_TEST(test_sscanf_u_1) {
  unsigned int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10 43", "%u %u", &a, &b);
  int sscanf_result_1 = sscanf("10 43", "%u %u", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_uint_eq(a, a_1);
  ck_assert_uint_eq(b, b_1);
}

START_TEST(test_sscanf_u_2) {
  unsigned int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("10 43", "%u%u", &a, &b);
  int sscanf_result_1 = sscanf("10 43", "%u%u", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_uint_eq(a, a_1);
  ck_assert_uint_eq(b, b_1);
}

START_TEST(test_sscanf_u_3) {
  unsigned int a = 0, b = 0, a_1 = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("-8 43", "%u%u", &a, &b);
  int sscanf_result_1 = sscanf("-8 43", "%u%u", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_uint_eq(a, a_1);
  ck_assert_uint_eq(b, b_1);
}

START_TEST(test_sscanf_x_1) {
  int a = 0, a_1 = 0;

  int sscanf_result = s21_sscanf("1A3", "%x", &a);
  int sscanf_result_1 = sscanf("1A3", "%x", &a_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
}

START_TEST(test_sscanf_x_2) {
  int a = 0, a_1 = 0, b = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("1A3 124", "%x %x", &a, &b);
  int sscanf_result_1 = sscanf("1A3 124", "%x %x", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_o_1) {
  int a = 0, a_1 = 0, b = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("13 124", "%o %o", &a, &b);
  int sscanf_result_1 = sscanf("13 124", "%o %o", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_o_2) {
  int a = 0, a_1 = 0, b = 0, b_1 = 0;

  int sscanf_result = s21_sscanf("13 124", "%o%o", &a, &b);
  int sscanf_result_1 = sscanf("13 124", "%o%o", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_int_eq(a, a_1);
  ck_assert_int_eq(b, b_1);
}

START_TEST(test_sscanf_p_1) {
  void *a = 0, *a_1 = 0;

  int sscanf_result = s21_sscanf("0x16cefb688", "%p", &a);
  int sscanf_result_1 = sscanf("0x16cefb688", "%p", &a_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_ptr_eq(a, a_1);
}

START_TEST(test_sscanf_p_2) {
  void *a = 0, *a_1 = 0, *b = 0, *b_1 = 0;

  int sscanf_result = s21_sscanf("0x16b007688 0x16cefb688", "%p %p", &a, &b);
  int sscanf_result_1 = sscanf("0x16b007688 0x16cefb688", "%p %p", &a_1, &b_1);

  ck_assert_int_eq(sscanf_result, sscanf_result_1);
  ck_assert_ptr_eq(a, a_1);
  ck_assert_ptr_eq(b, b_1);
}

Suite *sscanf_suite(void) {
  Suite *s;
  TCase *tc_core = tcase_create("core");

  s = suite_create("s21_sscanf");
  tcase_add_test(tc_core, test_sscanf_parsers_1);
  tcase_add_test(tc_core, test_sscanf_parsers_2);
  tcase_add_test(tc_core, test_sscanf_parsers_3);
  tcase_add_test(tc_core, test_sscanf_parsers_4);
  tcase_add_test(tc_core, test_sscanf_all_1);
  tcase_add_test(tc_core, test_sscanf_all_2);
  tcase_add_test(tc_core, test_sscanf_all_3);
  tcase_add_test(tc_core, test_sscanf_all_4);
  tcase_add_test(tc_core, test_sscanf_all_5);
  tcase_add_test(tc_core, test_sscanf_all_6);
  tcase_add_test(tc_core, test_sscanf_d_1);
  tcase_add_test(tc_core, test_sscanf_d_2);
  tcase_add_test(tc_core, test_sscanf_f_1);
  tcase_add_test(tc_core, test_sscanf_f_2);
  tcase_add_test(tc_core, test_sscanf_c_1);
  tcase_add_test(tc_core, test_sscanf_c_2);
  tcase_add_test(tc_core, test_sscanf_s_1);
  tcase_add_test(tc_core, test_sscanf_s_2);
  tcase_add_test(tc_core, test_sscanf_s_3);
  tcase_add_test(tc_core, test_sscanf_u_1);
  tcase_add_test(tc_core, test_sscanf_u_2);
  tcase_add_test(tc_core, test_sscanf_u_3);
  tcase_add_test(tc_core, test_sscanf_x_1);
  tcase_add_test(tc_core, test_sscanf_x_2);
  tcase_add_test(tc_core, test_sscanf_o_1);
  tcase_add_test(tc_core, test_sscanf_o_2);
  tcase_add_test(tc_core, test_sscanf_p_1);
  tcase_add_test(tc_core, test_sscanf_p_2);
  suite_add_tcase(s, tc_core);

  return s;
}

int number_of_tests_failed_1(void) {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;

  s = sscanf_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed;
}

int number_of_tests_failed_2(void) {
  int number_failed = 0;
  Suite *s;
  SRunner *sr;

  s = strlen_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = memchr_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strcspn_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strspn_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = memcmp_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = memcpy_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = memset_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strncat_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strchr_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  // s = strncmp_suite();
  // sr = srunner_create(s);
  // srunner_run_all(sr, CK_NORMAL);
  // number_failed += srunner_ntests_failed(sr);
  // srunner_free(sr);

  s = strncpy_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strpbrk_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strrchr_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strstr_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strtok_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = strerror_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return number_failed;
}

// int main() {
//     int number_failed =
//     number_failed += number_of_tests_failed_2();
//
////    printf("______________\n");
////    printf("%s\n", s21_strerror(57));
////    printf("%s\n", (char*)memchr(str_41, 'a', 10));
////
//    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
//}

int main() {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "C");
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_sprintf_csharp_funcs_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  failed += number_of_tests_failed_1();
  failed += number_of_tests_failed_2();
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
