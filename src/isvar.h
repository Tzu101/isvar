#pragma once

#include <utility>
#include <variant>

namespace isvar {

template <typename Type> std::pair<bool, Type> unpack(auto &variant) {
  bool holds = std::holds_alternative<Type>(variant);
  return {holds, holds ? std::get<Type>(variant) : Type{}};
}

} // namespace isvar

#define ISVAR_INTERNAL_IS(variant, type)                                       \
  if (auto [holds, variant] = isvar::unpack<type>(variant); holds)

#ifdef ISVAR_VERBOSE_NAMING
#define IS_VAR(variant, type) ISVAR_INTERNAL_IS(variant, type)
#else
#define is(variant, type) ISVAR_INTERNAL_IS(variant, type)
#endif
