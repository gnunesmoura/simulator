#ifndef enum_h
#define enum_h


#include <type_traits>
#include <iostream>

enum class Type {
    anchor = 0,
    placed = 1,
    not_placed = 2
};

enum class Axis {
    x = 0,
    y = 1
};

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

#endif
