#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, char> RNACodonTable = { {"AAA", 'K'},
														{"AAC", 'N'},
														{"AAG", 'K'},
														{"AAU", 'N'},
														{"ACA", 'T'},
														{"ACC", 'T'},
														{"ACG", 'T'},
														{"ACU", 'T'},
														{"AGA", 'R'},
														{"AGC", 'S'},
														{"AGG", 'R'},
														{"AGU", 'S'},
														{"AUA", 'I'},
														{"AUC", 'I'},
														{"AUG", 'M'},
														{"AUU", 'I'},
														{"CAA", 'Q'},
														{"CAC", 'H'},
														{"CAG", 'Q'},
														{"CAU", 'H'},
														{"CCA", 'P'},
														{"CCC", 'P'},
														{"CCG", 'P'},
														{"CCU", 'P'},
														{"CGA", 'R'},
														{"CGC", 'R'},
														{"CGG", 'R'},
														{"CGU", 'R'},
														{"CUA", 'L'},
														{"CUC", 'L'},
														{"CUG", 'L'},
														{"CUU", 'L'},
														{"GAA", 'E'},
														{"GAC", 'D'},
														{"GAG", 'E'},
														{"GAU", 'D'},
														{"GCA", 'A'},
														{"GCC", 'A'},
														{"GCG", 'A'},
														{"GCU", 'A'},
														{"GGA", 'G'},
														{"GGC", 'G'},
														{"GGG", 'G'},
														{"GGU", 'G'},
														{"GUA", 'V'},
														{"GUC", 'V'},
														{"GUG", 'V'},
														{"GUU", 'V'},
														{"UAA", ' '},
														{"UAC", 'Y'},
														{"UAG", ' '},
														{"UAU", 'Y'},
														{"UCA", 'S'},
														{"UCC", 'S'},
														{"UCG", 'S'},
														{"UCU", 'S'},
														{"UGA", ' '},
														{"UGC", 'C'},
														{"UGG", 'W'},
														{"UGU", 'C'},
														{"UUA", 'L'},
														{"UUC", 'F'},
														{"UUG", 'L'},
														{"UUU", 'F'} };

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
std::string ProteinTranslation(std::string RNA) {
	std::string peptid = "";

	for (int i = 0; i < RNA.length(); i += 3) {
		peptid += RNACodonTable.at(RNA.substr(i, 3));
	}

	return peptid;
}

std::string DNATranslateRNA(std::string DNA) {
	std::string rez="";
	for (int i = 0; i < DNA.length(); i++) {
		if (DNA[i] == 'T') {
			rez +='U';
		}
		else {
			rez += DNA[i];
		}
	}
	return rez;
}

std::string reversDNA(std::string DNA) {
	std::string reverseDNA;

	for (int i = DNA.length() - 1; i >= 0; --i) {
		reverseDNA += reverse(DNA[i]);
	}
	return reverseDNA;
}

int main() {

	std:: string DNA;
	std::string partRNA;
	std::string partreverseRNA;
	std::string GeneticCode;
	
	std::cin >> DNA;
	std::cin >> GeneticCode;


	for (int i = 0; i < DNA.length()-GeneticCode.length()*3+1; i++) {
		partreverseRNA = ProteinTranslation(DNATranslateRNA( reversDNA(DNA.substr(i, GeneticCode.length() * 3))));
		partRNA = ProteinTranslation(DNATranslateRNA( DNA.substr(i, GeneticCode.length() * 3)));

		if (partRNA == GeneticCode || partreverseRNA == GeneticCode) {
			std::cout << DNA.substr(i, GeneticCode.length() * 3) << std::endl;
		}
		
	}
	
	return 0;
}