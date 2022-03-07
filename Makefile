COMPILER = clang++ -std=c++20
INCLUDES = -Iutilities

test:		math_test

build:		math_build 71_build

clean:		math_clean 71_clean

math_build:	utilities/math.hpp test/math.cpp
			$(COMPILER) $(INCLUDES) test/math.cpp -o test/math

math_test:	math_build
			test/math

math_clean:
			rm -f test/math

71_build:	71/solution.cpp
			$(COMPILER) $(INCLUDES) 71/solution.cpp -o 71/solution

71_solve:	71_build
			71/solution

71_clean:	
			rm -f 71/solution
