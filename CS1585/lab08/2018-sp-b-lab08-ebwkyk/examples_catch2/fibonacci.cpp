#include<stdexcept>

/* Generate the Nth Fibonacci number */
int fibonacci(int n)
{
    if(n < 0)
    {
        throw std::domain_error("The Fibonacci sequence is not defined for negative indices");
    }
    else if(n <= 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Fibonacci", "[Fibonacci]") // Test name and tag
{
	CHECK(fibonacci(0) == 1);
	CHECK(fibonacci(1) == 1);
	CHECK(fibonacci(2) == 2);
	CHECK(fibonacci(5) == 8);
}

TEST_CASE("Fibonacci Domain", "[Fibonacci]")
{
    CHECK_NOTHROW(fibonacci(0));
    CHECK_NOTHROW(fibonacci(10));
    CHECK_THROWS_AS(fibonacci(-1), std::domain_error);
    CHECK_THROWS_WITH(fibonacci(-1), "The Fibonacci sequence is not defined for negative indices");
}
