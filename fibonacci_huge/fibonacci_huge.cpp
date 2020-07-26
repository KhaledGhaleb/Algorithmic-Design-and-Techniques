#include <iostream>
#include <random>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


uint32_t  fibonacci_fast_opt(uint32_t n, uint32_t m) {
	// write your code here
	uint32_t fib1 = 0;
	uint32_t fib2 = 1;
	uint32_t temp;

	if (n > 1) {
		for (int i = 2; i <= n; i++) {
			temp = (fib2 + fib1) % m;
			fib1 = fib2;
			fib2 = temp;
		}
	}
	else if (n <= 1) {
		return n;
	}

	return temp % m;
}
//Stress Testing
//Stress Testing
int main() {
    //std::random_device rd;
    std::mt19937 mt(10987);

    uint32_t n, max;
    cin >> n >> max;
    std::uniform_int_distribution<uint32_t> dist(0, max);
    uint32_t* numbers = new uint32_t[n];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_fast_opt(n, m) << '\n';
}
