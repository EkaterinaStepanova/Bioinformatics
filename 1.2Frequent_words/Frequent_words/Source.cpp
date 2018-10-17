#include <iostream>
#include<string>

int PaternCount(std::string st, std::string text) {

	int count = 0;

	for (int i = 0; i < st.length(); ++i) {
		if (st.substr(i, text.length()) == text) {
			count++;
		}
	}

	return count;
}

int main() {
	std::string genom;
	int k, maxCount =-1;
	int count = 0;
	std::string result = "";

	std::cin >>genom;
	std::cin >> k;

	for (int i = 0; i < genom.length() - k; ++i) {
		count = PaternCount(genom, genom.substr(i, k));
		if (count > maxCount) {
			maxCount = count;
			result = genom.substr(i, k);
		}
		if (count == maxCount) {
			if (!PaternCount(result, genom.substr(i, k)))
				result += genom.substr(i, k) + " ";
		}

	}

	std::cout << result << std::endl;

		return 0;
}