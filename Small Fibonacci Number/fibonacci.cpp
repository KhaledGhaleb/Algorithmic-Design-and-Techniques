#include <iostream>
#include <cassert>
#include <chrono>
#include <random>
using namespace std::chrono;
using namespace std;
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
	if (n <= 1)
		return n;

	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}
uint32_t fib_num[46] = { 0,1 };

int fibonacci_fast(int n) {
	// write your code here
	if (n > 1) {
		for (int i = 2; i <= n;i++) {
			fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
		}
	}
	else if (n <= 1) {
		return n;
	}

	return fib_num[n];
}

int fibonacci_fast_opt(int n) {
	// write your code here
	uint32_t fib1 = 0;
	uint32_t fib2 = 1;
	uint32_t temp;
	
	if (n > 1) {
		for (int i = 2; i <= n; i++) {
			temp = fib2 + fib1;
			fib1 = fib2;
			fib2 = temp;
		}
	}
	else if (n <= 1) {
		return n;
	}

	return temp;
}

void test_solution() {
	assert(fibonacci_fast(3) == 2);
	assert(fibonacci_fast(10) == 55);
	for (int n = 0; n < 45; ++n)
		assert(fibonacci_fast_opt(n) == fibonacci_fast(n));
}

#if 0
void test_speed() {
	std::mt19937 mt(10987);
	std::uniform_int_distribution<int> dist(0, 45);
	int rr;
	steady_clock::time_point start, stop;
	//while (true) {
	//	rr= dist(mt);
	//	start = high_resolution_clock::now();
	//	fibonacci_fast(rr);
	//	stop = high_resolution_clock::now();
	//	auto duration = duration_cast<nanoseconds>(stop - start);
	//	cout <<"Count = " <<rr <<", Time taken by function: " << duration.count() << " nanoseconds" << endl;		
	//}
	for (int i = 0; i < 45; i++) {
		start = high_resolution_clock::now();
		fibonacci_fast_opt(i);
		stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Count = " << i << ", Time taken by function: " << duration.count() << " nanoseconds" << endl;
	}

}
#endif

int main() {
	int n = 0;
	std::cin >> n;
	//test_speed();
	//std::cout << fibonacci_naive(n) << '\n';
	//test_solution();
	std::cout << fibonacci_fast(n) << '\n';
	return 0;
}
