#include<iostream>

int main() {
	int number;

	std::cin >> number;
	if (std::cin.fail()) {
		std::cout << "fail" << std::endl;
	}

}