#include "math.hpp"

void test_hcf() noexcept
{
    using namespace euler;

    static_assert(math::highest_common_factor(1, 0) == 1);
    static_assert(math::highest_common_factor(2, 1) == 1);
    static_assert(math::highest_common_factor(90, 60) == 30);
    static_assert(math::highest_common_factor(27, 42) == 3);
}

int main(int argc, char * argv[])
{
    test_hcf();
}