#ifndef __EULER_UTILITIES_MATH_HPP__
#define __EULER_UTILITIES_MATH_HPP__

#include <ostream>
#include <type_traits>

namespace euler::math
{

template<typename T>
constexpr std::enable_if_t<std::is_integral_v<T>, T> greatest_common_divisor(T upper, T lower) noexcept
{
    if (upper < lower) return greatest_common_divisor(lower, upper);

    if (lower == 0) return upper;

    return greatest_common_divisor(lower, upper % lower);
}

template<typename T = int, std::enable_if_t<std::is_integral_v<T>, void *> = nullptr>
class rational_number
{
public:

    constexpr rational_number  (T numerator = 0, T denominator = 1) noexcept
    : i_number (presentation::normalize(numerator, denominator))
    {
    }

    [[nodiscard]]
    constexpr bool operator < (rational_number const & n) const noexcept
    {
        return numerator() * n.denominator() < n.numerator() * denominator();
    }

    constexpr T const & numerator           () const noexcept
    {
        return i_number.numerator;
    }

    constexpr T const & denominator         () const noexcept
    {
        return i_number.denominator;
    }

private:

    struct presentation
    {
    public:

        [[nodiscard]]
        constexpr static presentation normalize (T numerator, T denominator) noexcept
        {
            auto gcd = greatest_common_divisor (numerator, denominator);

            return presentation {numerator / gcd, denominator / gcd};
        }

        T numerator;
        T denominator;
    };

    presentation i_number;

};

template<typename T>
std::enable_if_t<std::is_integral_v<T>, std::ostream &> operator << (std::ostream & os, rational_number<T> const & number)
{
    return os << number.numerator() << "/" << number.denominator();
}

}

#endif // __EULER_UTILITIES_MATH_HPP__