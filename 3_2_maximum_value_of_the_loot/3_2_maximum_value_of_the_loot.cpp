#include <iostream>
#include <vector>

using std::vector;


void get_ratio(vector<uint32_t> weights, vector<uint32_t> values, vector<double>& ratio_out) {

	uint32_t n = weights.size();
	for (uint32_t i = 0; i < n; i++) {
		ratio_out[i] = (double)values[i] / weights[i];
	}


}

double get_optimal_value(uint32_t capacity, vector<uint32_t> weights, vector<uint32_t> values) {
	double value = 0.0;

	// write your code here
	int n = weights.size();
	double W = capacity;
	vector<double> ratio(n);
	double max_ratio = 0;
	int max_idx = 0;
	get_ratio(weights, values, ratio);


	for (int loop = 0; loop < n; loop++) {
		//Check if capacity not empty
		if (W > 0) {
			//find max value and weight greater than 0
			max_ratio = 0;
			max_idx = 0;
			for (int i = 0; i < n; i++) {
				if (weights[i] > 0 && max_ratio < ratio[i]) {
					max_ratio = ratio[i];
					max_idx = i;
				}
			}
			if (W > weights[max_idx]) {
				W -= weights[max_idx];
				weights[max_idx] = 0;
				value += values[max_idx];
			}
			else {
				value += W * values[max_idx] / weights[max_idx];
				W = 0;
			}
		}
		else {
			break;
		}
	}

	return value;
}


int main() {
	int n; //1--1000
	uint32_t capacity; //0 ≤ 𝑊 ≤ 2 · 106
	std::cin >> n >> capacity;
	vector<uint32_t> values(n); //0 ≤ 𝑣𝑖 ≤ 2 · 106
	vector<uint32_t> weights(n); //0 < 𝑤𝑖 ≤ 2 · 106

	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
