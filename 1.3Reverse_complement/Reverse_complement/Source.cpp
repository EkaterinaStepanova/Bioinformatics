#include <iostream>
#include <string>

std::string reverse(char g)
{
	if (g == 'A')
		return "T";
	else if (g == 'T')
		return "A";
	else if (g == 'G')
		return "C";
	else if (g == 'C')
		return "G";
}

int main() {
	std::string genom;
	std::string result;

	std::cin >> genom;
	
	for (int i = genom.length() - 1; i >= 0; --i) {
		result+= reverse(genom[i]);

	}
	std::cout << result ;

	return 0;
}