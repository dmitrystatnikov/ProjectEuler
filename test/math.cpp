#include "math.hpp"

void test_hcf() noexcept
{
    using namespace euler;

    static_assert(math::greatest_common_divisor(1, 0) == 1);
    static_assert(math::greatest_common_divisor(2, 1) == 1);
    static_assert(math::greatest_common_divisor(90, 60) == 30);
    static_assert(math::greatest_common_divisor(27, 42) == 3);
}

int main(int argc, char * argv[])
{
    test_hcf();
}