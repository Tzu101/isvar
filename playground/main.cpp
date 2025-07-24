#include <iostream>

#include <isvar.h>

struct test {
  int x;

  int getX() const { return x; }
};

int main() {
  std::variant<int, test> var = test{42};

  is (var, int) {
    std::cout << "Variant holds an int: " << var << std::endl;
  }
  is (var, test) {
    std::cout << "Variant holds a test: " << var.getX() << std::endl;
  }

#ifdef ISVAR_VERBOSE_NAMING
  std::cout << "Verbose naming is enabled." << std::endl;
#else
  std::cout << "Verbose naming is disabled." << std::endl;
#endif

  return 0;
}