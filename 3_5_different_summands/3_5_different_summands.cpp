#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int i = 1;
	int cmp = 3;
	while (true) {
		if (n >= (cmp)) {
			n -= i;
			summands.push_back(i);
			i++;
			cmp += 2;
		}
		else {
			summands.push_back(n);
			break;
		}
	}
	return summands;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}
