#include <iostream>
#include <string>
#include <map>


int main()
{
	int m;
	int aminoAcidMass[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
	std::map<int, long> count = { {0, 1} };
	std::cin >> m;

	for (int i = 57; i <= m; i++)
	{
		count[i] = 0;

		for (int j = 0; j < 18; j++)
		{
			if (count.find(i - aminoAcidMass[j]) != count.end())
			{
				count[i] += count[i - aminoAcidMass[j]];
			}
		}
	}

	std::cout << count[m];
	return 0;
}