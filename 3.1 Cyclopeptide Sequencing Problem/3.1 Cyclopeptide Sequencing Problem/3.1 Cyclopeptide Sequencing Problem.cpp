#include <iostream>
#include <string>
#include <map>
#include <vector>
#include<list>

using namespace std;
 
 vector<char> tmp = { 'G','A','S','P','V','T','C','I','L','N','D','K','Q','E','M','H','F','R','Y','W' };

 std::map<char, int> MassOfAminoAcid{ {'G', 57}, {'A', 71},	{'S', 87},	{'P', 97},{'V', 99},
									{'T', 101},	{'C', 103},	{'I', 113},	{'L', 113},	{'N', 114},
									{'D', 115},	{'K', 128},	{'Q', 128},	{'E', 129},	{'M', 131},
									{'H', 137},	{'F', 147},	{'R', 156},	{'Y', 163},	{'W', 186} };
 int Mass(std::string peptide)
 {
	 int mass = 0;
	 for (int i = 0; i < peptide.length(); i++) {
		 mass += MassOfAminoAcid[peptide[i]];
	 }
	 return mass;
 }
 vector<string> Expand(vector<string> peptides)
 {
	 vector<string> newPeptides;
	 for (int i = 0; i < peptides.size(); i++) {

		for (int j = 0; j < MassOfAminoAcid.size(); j++) {

			 newPeptides.push_back(peptides[i]+tmp[j]);
		 }
	 }
	
	 return newPeptides;
 }
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

		 res += to_string (*it);
		 res += " ";
	 }
	 
	 return res;

 }
 int  PtidesCount(string aminoAcid) {
	 int res=0;
	 for (int i = 1; i <= aminoAcid.length(); i++) {
		 res += i;
	 }
	 return res;
 }
 string LinearSpectrum(string aminoAcid)
 {
	 std::string res = "";
	 std::list<std::string> subpeptidesOfPeptide;
	 std::string tmp;
	 int weight = 0;

	 for (int i = 1; i < aminoAcid.length(); i++) {

		 for (int j = 0; j < aminoAcid.length(); j++) {

			 if (aminoAcid.length() - j >= i) {

				 subpeptidesOfPeptide.push_back(aminoAcid.substr(j, i));
			 }
		}
	 }

	 subpeptidesOfPeptide.push_back(aminoAcid);
	 res += to_string(weight);
	 res += " ";

	 for (int i = 0; i < PtidesCount(aminoAcid); i++) {

		 tmp = subpeptidesOfPeptide.front();
		 subpeptidesOfPeptide.pop_front();

		 for (int j = 0; j < tmp.length(); j++) {

			 weight += MassOfAminoAcid.at(tmp[j]);
		 }
		 res += to_string(weight);
		 res += " ";
		 weight = 0;
	 }
	 return res;

 }
 vector<string> Remove(vector<string> peptides, string peptide)
 {
	 vector<string> res;
	 int j = 0;

	 for (int i = 0; i < peptides.size(); i++) {

		 if (peptides[i] != peptide) {
			 res.push_back( peptides[i]);

		 }
	 }
	 return res;
 }
 vector<string> ToVector(string str)
 {
	 vector<string> res ;
	 
	 while (str != ""){
		 
		 res.push_back(str.substr(0, str.find(" ")));
		 str.erase(0, str.find(" ")+1);

	 }
	 return res;
 }


 bool IsConsistent(string peptide, string spectrum)
 {
	 bool flag = false;
	 vector<string> specMass = ToVector(spectrum+ " ");
	 vector<string> peptideMass = ToVector(LinearSpectrum(peptide));

	 for (int i = 0; i < peptideMass.size(); i++) {

		 for (int j = 0; j < specMass.size(); j++) {

			 if (specMass[j] == peptideMass[i]) {
				 flag = true;
			 }

		 }
		 if (!flag) return false;

		 flag = false;
	 }

	 return true;
 }
 int main()
 {

 	std::string spectrum;
	std::getline(cin, spectrum);
	int parentMass = stoi(spectrum.substr(spectrum.find_last_of(' ') + 1, spectrum.length() - 1));
	vector<string> peptides = {""};
	vector<string> totalPeptides;

	spectrum += " ";

	while (peptides.size() > 0)
	{
		peptides = Expand(peptides);
		vector<string> copyTotalPeptides = peptides;

		for (int i = 0; i < copyTotalPeptides.size(); i++){

			string peptide= copyTotalPeptides[i];
			
			if (Mass(peptide) == parentMass) {
				
				string t = CycloSpectrum(peptide);

				if (CycloSpectrum(peptide) == (spectrum)) {
					
					totalPeptides.push_back(peptide);
				}
				peptides = Remove(peptides, peptide);
			}
			else if (!IsConsistent(peptide, spectrum))
			{
				peptides = Remove(peptides, peptide);
			}
			
		}
	}

	string res;

	for (int i = 0; i < totalPeptides.size(); i++) {

		string tmp ;

		for (int j = 0; j < totalPeptides[i].length(); j++) {

			tmp += to_string(MassOfAminoAcid[totalPeptides[i][j]]);
			tmp += "-";

		}
		tmp = tmp.substr(0, tmp.length() - 1);
		
		if (res.find(tmp) > res.length() || res.find(tmp) < 0) {

			res += tmp;
			res += " ";
		}
	}

	res = res.substr(0, res.length() - 1);
	cout << res;

	 return 0;
 }