#include <iostream>
#include<list>
#include<string>
#include<map>

std::map<char, int> MassOfAminoAcid{ {'G', 57},
									{'A', 71},
									{'S', 87},
									{'P', 97},
									{'V', 99},
									{'T', 101},
									{'C', 103},
									{'I', 113},
									{'L', 113},
									{'N', 114},
									{'D', 115},
									{'K', 128},
									{'Q', 128},
									{'E', 129},
									{'M', 131},
									{'H', 137},
									{'F', 147},
									{'R', 156},
									{'Y', 163},
									{'W', 186} };

int SubpeptidesCount(std::string peptide) {
	return peptide.length()*(peptide.length() - 1);
}

int main()
{
	std::string aminoAcid;
	std::list<std::string> subpeptidesOfPeptide;
	std::string tmp;
	int weight = 0;
	std::cin >> aminoAcid;
	for (int i = 1; i < aminoAcid.length(); i++) {
		for (int j = 0; j < aminoAcid.length(); j++) {
			if (aminoAcid.length() - j >= i) {
				subpeptidesOfPeptide.push_back(aminoAcid.substr(j, i));
			}
			else {
				tmp = aminoAcid.substr(j, aminoAcid.length() - j) + aminoAcid.substr(0, i - (aminoAcid.length() - j));
				subpeptidesOfPeptide.push_back(tmp);
			}
		}
	}
	subpeptidesOfPeptide.push_back(aminoAcid);
	std::cout << weight << " ";
	for (int i = 0; i < SubpeptidesCount(aminoAcid) + 1; i++) {
		tmp = subpeptidesOfPeptide.front();
		subpeptidesOfPeptide.pop_front();
		for (int j = 0; j < tmp.length(); j++) {
			weight += MassOfAminoAcid.at(tmp[j]);
		}
		std::cout << weight << " ";
		weight = 0;
	}

	return 0;
}