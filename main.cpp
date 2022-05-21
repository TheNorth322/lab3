#include "cstdlib"
#include "menu.h"

int main() {
  Menu menu = Menu();
  menu.listen();

  return EXIT_SUCCESS;
}
