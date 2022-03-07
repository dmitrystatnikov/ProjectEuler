#include "math.hpp"

#include <iostream>

using namespace euler::math;
using namespace std;

int main(int argc, char * argv[])
{
    uint32_t result_n = 1;
    uint32_t result_d = 3;

    for (uint32_t d = 4; d < 1000001; ++d)
    {
        if (d % 7 == 0) continue;
        uint32_t n  = (d * 3) / 7;
        uint64_t l = result_n * d;
        uint64_t r = n * result_d;
        if (l < r)
        {
            result_n = n;
            result_d = d;
        }
    }

    cout << result_n << " / " << result_d << endl;

    return 0;
}