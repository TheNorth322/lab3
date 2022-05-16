#include "menu.h"
#include "cstdlib"

int main() {
  Menu menu = Menu();
  menu.listen();

  return EXIT_SUCCESS;
}
