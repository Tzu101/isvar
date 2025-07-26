#pragma once

#include <variant>

#define ISVAR_INTERNAL_IS(variant, type)                                       \
  if (bool ISVAR_HOLDS = std::holds_alternative<type>(variant); ISVAR_HOLDS)   \
    if (auto ISVAR_VARIANT = variant; true)                                    \
      if (auto variant = std::get<type>(ISVAR_VARIANT); true)

#ifdef ISVAR_VERBOSE_NAMING
#define IS_VAR(variant, type) ISVAR_INTERNAL_IS(variant, type)
#else
#define is(variant, type) ISVAR_INTERNAL_IS(variant, type)
#endif
