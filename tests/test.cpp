#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "prime.hpp"  


// Testing few prime identification
TEST_CASE("Known Prime Number Tests") {
    REQUIRE(isPrimeHalf(2) == true);
    REQUIRE(isPrimeHalf(3) == true);
    REQUIRE(isPrimeHalf(5) == true);
    REQUIRE(isPrimeHalf(7) == true);
    REQUIRE(isPrimeHalf(29) == true);
    REQUIRE(isPrimeSqrt(2) == true);
    REQUIRE(isPrimeSqrt(3) == true);
    REQUIRE(isPrimeSqrt(5) == true);
    REQUIRE(isPrimeSqrt(7) == true);
    REQUIRE(isPrimeSqrt(29) == true);
}

// Testing composite numbers

TEST_CASE("Known Composite Number Tests") {
    REQUIRE(isPrimeHalf(4) == false);
    REQUIRE(isPrimeHalf(8) == false);
    REQUIRE(isPrimeHalf(21) == false);
    REQUIRE(isPrimeHalf(32) == false);
    REQUIRE(isPrimeHalf(100) == false);
    REQUIRE(isPrimeSqrt(4) == false);
    REQUIRE(isPrimeSqrt(8) == false);
    REQUIRE(isPrimeSqrt(21) == false);
    REQUIRE(isPrimeSqrt(32) == false);
    REQUIRE(isPrimeSqrt(100) == false);
}

// test for few range of prime numbers if both methods are consistent
TEST_CASE("Prime Identification Consistency") {
    for (int i = 2; i <= 51; ++i) {
        REQUIRE(isPrimeHalf(i) == isPrimeSqrt(i));
    }
    for (int i = 1000; i <= 2100; ++i) {
        REQUIRE(isPrimeHalf(i) == isPrimeSqrt(i));
    }
}
// Testing mod operation counts
TEST_CASE("Modulo Operation Count Tests") {
    long long halfOps = countModOps(isPrimeHalf, 3, 3);
    long long sqrtOps = countModOps(isPrimeSqrt, 3, 3);
    REQUIRE(halfOps == 0);
    REQUIRE(sqrtOps == 0);
    halfOps = countModOps(isPrimeHalf, 2, 10);
    sqrtOps = countModOps(isPrimeSqrt, 2, 10);
    REQUIRE(halfOps == 9);
    REQUIRE(sqrtOps == 8);
    halfOps = countModOps(isPrimeHalf, 2, 10000);
    sqrtOps = countModOps(isPrimeSqrt, 2, 10000);
    REQUIRE(halfOps == 2907640);
    REQUIRE(sqrtOps == 117527);
}

// test edge cases
TEST_CASE("Edge Case Tests") {
    REQUIRE(isPrimeHalf(0) == false);
    REQUIRE(isPrimeHalf(1) == false);
    REQUIRE(isPrimeSqrt(0) == false);
    REQUIRE(isPrimeSqrt(1) == false);
    REQUIRE(isPrimeHalf(-2) == false);
    REQUIRE(isPrimeHalf(-10) == false);
    REQUIRE(isPrimeSqrt(-2) == false);
    REQUIRE(isPrimeSqrt(-10) == false);
}