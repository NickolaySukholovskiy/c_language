
#include "work_with_flags.h"

void get_massive_with_flags(int argc, char* argv[], int mas_of_flags[]) {
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  int opt;
  const char* short_options = "+bentvsET";
  int option_index = -1;

  while ((opt = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        mas_of_flags[0] = 1;  // flag_b
        break;

      case 'e':
        mas_of_flags[1] = 1;  // flag_e
        mas_of_flags[5] = 1;  // flag_v
        break;

      case 'n':
        mas_of_flags[2] = 1;  // flag_n
        break;

      case 't':
        mas_of_flags[3] = 1;  // flag_t
        mas_of_flags[5] = 1;  // flag_v
        break;

      case 's':
        mas_of_flags[4] = 1;  // flag_s
        break;

      case 'v':
        mas_of_flags[5] = 1;  // flag_v
        break;

      case 'E':
        mas_of_flags[1] = 1;  // flag_e
        break;

      case 'T':
        mas_of_flags[3] = 1;  // flag_t
        break;

      case '?':
      default: {
        printf("You inserted the wrong flag: %c, try again\n", opt);
        break;
      };
    }
  }

  if (mas_of_flags[0] == 1 && mas_of_flags[2] == 1) {  // флаг b главнее n
    mas_of_flags[2] = 0;
  }
}
