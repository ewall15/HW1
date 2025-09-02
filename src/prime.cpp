//prime.cpp
#include <cmath>
#include "prime.hpp"

// TODO: Implement isPrimeHalf
bool isPrimeHalf(int n, long long* modOps) {
    // Your implementation here
    // Checks for divisibility up to n/2
    // return true if n is prime else return false
    // count modulo operations when modOps is not nullptr
    if(n <= 1){
        return false;
    }
    if(n == 2||n == 3){
        if(modOps != nullptr){
            (*modOps)++;
        }
        return true;
    }
    for(int i = 2; i <= n/2; i++) {
        if(modOps != nullptr){
            (*modOps)++;
        }
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// TODO: Implement isPrimeSqrt
bool isPrimeSqrt(int n, long long* modOps) {
    // Your implementation here
    // Checks for divisibility up to square root of n
    // return true if n is prime else return false
    // Remember to count modulo operations when modOps is not nullptr
    if(n <= 1){
        return false;
    }
    if(n == 2||n == 3){
        if(modOps != nullptr){
            (*modOps)++;
        }
        return true;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if(modOps != nullptr){
            (*modOps)++;
        }
        if(n % i ==0){
            return false;
        }
    }
    return true;
}

// TODO: Implement countModOps
long long countModOps(PrimeFn isPrime, int lo, int hi) {
    // Your implementation here
    // This should call the provided isPrime function for each number in range [lo, hi]
    // and return the total number of modulo operations performed
    long long count = 0;
    for(int i = lo; i <= hi; i++){
        isPrime(i, &count);
    }
    return count;
}