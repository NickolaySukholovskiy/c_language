#include "work_with_file.h"
#include "work_with_flags.h"

int main(int argc, char* argv[]) {
  int massive_of_flags[] = {0, 0, 0, 0, 0, 0};
  get_massive_with_flags(argc, argv, massive_of_flags);

  check_files(argc, argv, massive_of_flags);
  return 0;
}
