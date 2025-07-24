# isvar

C++ pattern matching for std::variant.

## Usage

Simply include _isvar.h_ in your file.

```c++
#include <iostream>

#include <isvar.h>

using MyVariant = std::variant<int, float, char>;

int main() {
    MyVariant my_var = 42;

    is (my_var, int) {
        std::cout << "The new my_var shadows the variant type and can be used as an int:" << my_var << std::endl;
    }
    is (my_var, float) {
        std::cout << "This macro doesn't define any new scopes so it can be returned from" << std::endl;
        return 1;
    }
    else {
        std::cout << "Else statements are also supported" << std::endl;
    }
}
```

## Limitations

### Format

For formatting the following needs to be added to _.clang-format_.

```yaml
AttributeMacros: ["is", "IS_VAR"]
IfMacros: ["is", "IS_VAR"]
WhitespaceSensitiveMacros: ["is", "IS_VAR"]
```

### Scope

The macro uses a common word **is** which can conflict with predefined variables. If that happens the compile-time variable **ISVAR_VERBOSE_NAMING** can be defined and the macro becomes **IS_VAR**.

```c++
#define ISVAR_VERBOSE_NAMING
```

Or

```cmake
set(ISVAR_VERBOSE_NAMING ON)
```

### Arguments

The variant passed as the first argument to the macro must be a predefined variable so it can be shadowed. Member or array access will not work.

```c++
is (my_vars[1], Type)  // Error
is (my_wrapper.var, Type)  // Error
```
