//main.cpp
#include <iostream>
#include "prime.hpp"

int main() {
    constexpr int LO = 4, HI = 4;
    
    // TODO: Count modulo operations for both algorithms
    long long halfOps = countModOps(isPrimeHalf, LO, HI);
    long long sqrtOps = countModOps(isPrimeSqrt, LO, HI);
    
    // TODO: Print the results
    std::cout << "Half method operations: " << halfOps << "\n";

    std::cout << "Square method operations: " << sqrtOps << "\n";
    // Add more output as needed
    
    // TODO: Calculate and print the ratio
    double ratio = halfOps / sqrtOps;
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";
    
    return 0;
}