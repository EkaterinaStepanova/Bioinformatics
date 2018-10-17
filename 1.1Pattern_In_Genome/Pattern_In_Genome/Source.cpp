#include <iostream>
#include<string>

//using namespace std;
int main() {
	std::string pattern;
	std::string genom;

	int count = 0;

	std::cin >> pattern;
	std::cin >> genom;

	for (int i = 0; i < genom.length(); ++i) {
		if (genom[i] == pattern[0]) {
			if (genom.substr(i, pattern.length()) == pattern) {
				count++;
			}
		}
	 }

	std::cout << count << std::endl;
	
	return 0;
}