// Least Common Multiple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

uint32_t gcd_opt(uint32_t a, uint32_t b) {
    uint32_t current_gcd = 1;
    if (b == 0)
        return a;


    return gcd_opt(b, a % b);
}

uint64_t lcm_opt(uint32_t a, uint32_t b) {
    uint32_t gcd = gcd_opt(a, b);
    uint64_t output = (uint64_t) a / gcd * b;
    return output;
}


int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_opt(a, b) << std::endl;
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
