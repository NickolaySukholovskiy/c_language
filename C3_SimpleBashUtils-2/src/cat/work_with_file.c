#include "work_with_file.h"

void get_str_with_number(int row_number, char mas[]) {
  int size_of_digit = 0;
  int buf_digit = row_number;

  while (buf_digit > 0) {
    buf_digit /= 10;
    size_of_digit++;
  }

  for (int i = 5; i > -1; i--) {
    if (size_of_digit > 0) {
      mas[i] = row_number % 10 + '0';
      row_number /= 10;
    } else {
      mas[i] = ' ';
    }
    size_of_digit--;
  }
  mas[6] = '\t';
}

void read_and_apply_flags(FILE* fp, int flags[]) {
  char symbol;
  char last = '\n';
  char mas_num[7];
  int str_number = 0;
  symbol = fgetc(fp);
  while (symbol != EOF) {
    if (flags[0] == 1) {
      if (last == '\n' && symbol != '\n') {
        str_number++;
        get_str_with_number(str_number, mas_num);
        for (int i = 0; i < 7; i++) {
          printf("%c", mas_num[i]);
        }
      } else if (last == '\n' && symbol == '\n') {
        if (flags[1] == 1) {
          for (int i = 0; i < 6; i++) {
            printf(" ");
          }
          printf("\t");
        }
      }
    }

    if (flags[2] == 1) {
      if (last == '\n') {
        str_number++;
        get_str_with_number(str_number, mas_num);
        for (int i = 0; i < 7; i++) {
          printf("%c", mas_num[i]);
        }
      } else if (last == '\n' && symbol == '\n') {
        if (flags[1] == 1) {
          for (int i = 0; i < 6; i++) {
            printf(" ");
          }
          printf("\t");
        }
      }
    }

    if (flags[1] == 1) {
      if (symbol == '\n') {
        printf("$");
      }
    }

    if (flags[3] == 1) {
      if (symbol == '\t') {
        printf("^");
        symbol = 'I';
      }
    }

    if (flags[5] == 1) {
      if ((symbol >= 0 && symbol < 9) || (symbol > 10 && symbol < 32)) {
        printf("^");
        symbol += 64;
      }
      if (symbol == 127) {
        printf("^");
        symbol = '?';
      }
    }

    printf("%c", symbol);

    if (flags[4] == 1) {
      if (last == '\n' && symbol == '\n') {
        while (last == '\n' && symbol == '\n') {
          last = symbol;
          symbol = fgetc(fp);
        }
      } else {
        last = symbol;
        symbol = fgetc(fp);
      }
    } else {
      last = symbol;
      symbol = fgetc(fp);
    }
  }
}

void check_files(int argc, char* argv[], int flags[]) {
  //    int counter = 0;
  for (int i = 1; i < argc; i++) {
    //        if (counter != 0) {
    //            printf("\n");
    //        }
    if (argv[i][0] != '-') {
      FILE* fp = fopen(argv[i], "r");

      if (fp != NULL) {
        read_and_apply_flags(fp, flags);
        fclose(fp);
      } else {
        printf("cat: %s: No such file or directory", argv[i]);
      }

      //            counter++;
    }
  }
}
