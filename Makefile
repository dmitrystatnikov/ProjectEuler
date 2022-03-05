COMPILER = clang++ -std=c++20
INCLUDES = -Iutilities

test:		math_test

build:		math_build

clean:		math_clean

math_build:	utilities/math.hpp test/math.cpp
			$(COMPILER) $(INCLUDES) test/math.cpp -o test/math

math_test:	math_build
			test/math

math_clean:
			rm test/math
