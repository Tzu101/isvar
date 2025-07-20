#pragma once

#include <utility>
#include <variant>

namespace isvar {

template <typename Type>

// For this to work the variant needs to be default constructable
std::pair<bool, Type> validateAndUnpackVariant(auto& variant) {
    bool holds = std::holds_alternative<Type>(variant);
    return {holds, holds ? std::get<Type>(variant) : Type{}};
}

}  // namespace isvar

#define INTERNAL_IS_(variant, type) \
    if (auto [holds, variant] = isvar::validateAndUnpackVariant<type>(variant); holds)

#ifdef RIS_VERBOSE_NAMING
#define IS_VARIANT(variant, type) INTERNAL_IS_(variant, type)
#else
#define is(variant, type) INTERNAL_IS_(variant, type)
#endif
