#include <iostream>
#include<limits> //used to get numeric limits
//using namespace std;

int main() {
	int a = 0;
	int b = 0;
	std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//std::cout << "Please enter first integer?\n";
	std::cin >> a >> b;

	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cout << "Please enter valid integer?\n";
		std::cin >> a >> b;
	}
	//std::cout << "Please enter second integer?\n";
	//std::cin >> b;
	//while (!std::cin.good()) {
	//	std::cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	std::cout << "Please enter valid integer?\n";
	//	std::cin >> b;
	//}
	std::cout << a + b;
	return 0;
}