#include <iostream>
#include <string>
#include <map>
#include <vector>
#include<list>

using namespace std;

std::map<char, int> MassOfAminoAcid{ {'G', 57}, {'A', 71},	{'S', 87},	{'P', 97},{'V', 99},
								   {'T', 101},	{'C', 103},	{'I', 113},	{'L', 113},	{'N', 114},
								   {'D', 115},	{'K', 128},	{'Q', 128},	{'E', 129},	{'M', 131},
								   {'H', 137},	{'F', 147},	{'R', 156},	{'Y', 163},	{'W', 186} };

int SubpeptidesCount(std::string peptide) {
	return peptide.length()*(peptide.length() - 1);
}
string CycloSpectrum(string aminoAcid)
{
	std::string res = "";
	std::list<std::string> subpeptidesOfPeptide;
	std::list<int> weightSubpeptidesOfPeptide;
	std::string tmp;
	int weight = 0;

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
	weightSubpeptidesOfPeptide.push_back(weight);
	for (int i = 0; i < SubpeptidesCount(aminoAcid) + 1; i++) {
		tmp = subpeptidesOfPeptide.front();
		subpeptidesOfPeptide.pop_front();
		for (int j = 0; j < tmp.length(); j++) {
			weight += MassOfAminoAcid.at(tmp[j]);
		}
		weightSubpeptidesOfPeptide.push_back(weight);

		weight = 0;
	}
	weightSubpeptidesOfPeptide.sort();
	list<int>::const_iterator it = weightSubpeptidesOfPeptide.begin();
	for (list<int>::const_iterator it = weightSubpeptidesOfPeptide.begin(); it != weightSubpeptidesOfPeptide.end(); it++) {

		res += to_string(*it);
		res += " ";
	}

	return res;

}
vector<int> ToVector(string str)
{
	//str += " ";
	vector<int> res;

	while (str != "") {

		res.push_back(stoi(str.substr(0, str.find(" "))));
		str.erase(0, str.find(" ") + 1);

	}
	return res;
}
vector<int> Remove(vector<int> peptides, int peptide,int k=1)
{
	vector<int> res;
	int j = 0;

	for (int i = 0; i < peptides.size(); i++) {

		
		if (peptides[i] != peptide || k == 0) {
			res.push_back(peptides[i]);
			

		}
		if(peptides[i] == peptide && k == 1)  k = 0 ;
	}
	return res;
}
int  Score(string peptide, string spectrum)
{
	std::string teoreticalCycloSpectrum = CycloSpectrum(peptide);
	vector<int> expSpectrum = ToVector(spectrum+" ");
	vector<int> teorSpectrum = ToVector(teoreticalCycloSpectrum);
	int count = 0;
	int tmp = teorSpectrum.size();
		
	for (int i = 0; i < expSpectrum.size(); i++) {
		for (int j = 0; j < teorSpectrum.size(); j++) {
			if (expSpectrum[i] == teorSpectrum[j]) {
				count++;
				teorSpectrum = Remove(teorSpectrum, teorSpectrum[j]);
				//j = 0;
				break;
			}
		}
	}

	return count;
}
int main()
{

	std::string experementSpectrum;// = "0 99 113 114 128 227 242 242 242 257 299 355 356 370 371 484";
	std::string peptide;
	int res;


	std::getline(cin, peptide);
	std::getline(cin, experementSpectrum);
	
	res = Score(peptide, experementSpectrum);
	cout << res;

	return 0;
}