#include <iostream>

#include "../src/ris/ris.h"

int main() {
    std::variant<int, float> var = 42.f;

    is(var, int) {
        std::cout << "Variant holds an int: " << var << std::endl;
    }
    is(var, float) {
        std::cout << "Variant holds an float: " << var << std::endl;
    }

#ifdef RIS_VERBOSE_NAMING
    std::cout << "Verbose naming is enabled." << std::endl;
#else
    std::cout << "Verbose naming is disabled." << std::endl;
#endif

    return 0;
}