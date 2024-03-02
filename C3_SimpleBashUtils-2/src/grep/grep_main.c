
#include "get_flags.h"

int main(int argc, char *argv[]) {
  struct flags grep_flags;
  null_flags(&grep_flags);

  get_flags(argc, argv, &grep_flags);

  if (argc > 2) {
    //        printf("goog\n");
    change_flags(&grep_flags);
    change_special_symbols(&grep_flags);
    get_files_open_them(argc, argv, &grep_flags);
  }

  free_struct(&grep_flags);
}
