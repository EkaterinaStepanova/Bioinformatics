#include <iostream>

int main() {
	long int lengthPeptide;

	std::cin >> lengthPeptide;
	std::cout << lengthPeptide * (lengthPeptide - 1);

	return 0;
}