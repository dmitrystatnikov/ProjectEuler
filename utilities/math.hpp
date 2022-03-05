#ifndef __EULER_UTILITIES_MATH_HPP__
#define __EULER_UTILITIES_MATH_HPP__

#include <type_traits>

namespace euler::math
{

template<typename T>
constexpr std::enable_if_t<std::is_integral_v<T>, T> highest_common_factor(T upper, T lower) noexcept
{
    if (upper < lower) return highest_common_factor(lower, upper);

    if (lower == 0) return upper;

    return highest_common_factor(lower, upper % lower);
}

}

#endif // __EULER_UTILITIES_MATH_HPP__