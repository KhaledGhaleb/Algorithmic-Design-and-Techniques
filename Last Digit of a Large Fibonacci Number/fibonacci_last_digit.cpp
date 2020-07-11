#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    uint64_t current  = 1;

    for (uint64_t i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_fast_opt(int n) {
	// write your code here
	uint8_t fib1 = 0;
	uint8_t fib2 = 1;
	uint8_t temp;

	if (n > 1) {
		for (int i = 2; i <= n; i++) {
			temp = (fib2 + fib1)%10;
			fib1 = fib2;
			fib2 = temp;
		}
	}
	else if (n <= 1) {
		return n;
	}

	return temp%10;
}


void test_solution() {
	assert(fibonacci_fast_opt(3) == 2);
	assert(fibonacci_fast_opt(331) == 9);
	assert(fibonacci_fast_opt(327305) == 5);
	for (int n = 0; n < 331; ++n)
		assert(fibonacci_fast_opt(n) == get_fibonacci_last_digit_naive(n));
}

int main() {

	//test_solution();

    uint64_t n;
    std::cin >> n;
    uint64_t c = fibonacci_fast_opt(n);
    std::cout << c << '\n';
    }
