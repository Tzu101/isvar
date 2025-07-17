#pragma once

#include <utility>
#include <variant>

namespace ris {

template <typename Type>
std::pair<bool, Type> unpackVariant(auto& variant) {
    bool holds = std::holds_alternative<Type>(variant);
    return {holds, holds ? std::get<Type>(variant) : Type{}};
}

}  // namespace ris

#define INTERNAL_IS_(variant, type) \
    if (auto [holds, variant] = ris::unpackVariant<type>(variant); holds)

#ifdef RIS_VERBOSE_NAMING
#define IS_(variant, type) INTERNAL_IS_(variant, type)
#else
#define is(variant, type) INTERNAL_IS_(variant, type)
#endif
