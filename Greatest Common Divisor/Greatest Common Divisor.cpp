// Greatest Common Divisor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}


uint32_t gcd_opt(uint32_t a, uint32_t b) {
    uint32_t current_gcd = 1;
    if (b == 0)
        return a;


    return gcd_opt(b, a % b);
}


int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_opt(a, b) << std::endl;
    return 0;
}
