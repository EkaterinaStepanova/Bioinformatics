using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._2_Median_String_Problem
{
    class Program
    {
        static List<string> CreateWords(string text, int length)
        {
            List<string> words = new List<string>((int)Math.Pow(4, length));
            CreateAllWords(ref words, text, length);
            return words;
        }
        static void CreateAllWords(ref List<string> words, string text, int length, string currentStr = "")
        {
            if (length == 0)
            {
                words.Add(currentStr);
            }
            else
                foreach (char c in text)
                {
                    CreateAllWords(ref words, text, length - 1, currentStr + c);
                }
        }
        static int HammingDistance(string pattern, string p)
        {
            int count = 0;
            
            for (int i = 0; i < pattern.Length; i++)
            {
                if (pattern[i] != p[i])
                {
                    count++;
                }
            }

            return count;
        }
        
        static int D(string pattern, string[] DNA)
        {
            int result = 0;

            foreach (string s in DNA)
            {
                List<int> d = new List<int>();
                for (int i = 0; i < s.Length - pattern.Length  + 1; i++)
                {
                    d.Add(HammingDistance(pattern, s.Substring(i, pattern.Length)));
                }
                result += d.Min();
            }

            return result;
        }
        static string MedianString(string[] dna, int k)
        {
            int distance = int.MaxValue;
            string median = "";
            List<string> kMers = CreateWords("AGCT", k);

            foreach (string kmer in kMers)
            {
                if (distance > D(kmer, dna))
                {
                    distance = D(kmer, dna);
                    median = kmer;
                }
            }

            return median;
        }
        static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());

            string tmp = "";
            while (true)
            {
                string s = Console.ReadLine();
                if (string.IsNullOrEmpty(s))
                    break;

                tmp += s + ' ';
            }
            tmp = tmp.Trim();
            
            string[] DNA = tmp.Split(' ');
           /* string[] DNA =
            {
                "GAAACTACGCACGTAGTGTTTTGCTACGGTTCTCA",
                "TATATCCACATGACCTCGACAACGCACGGTCGAAT",
                "TAGCGGGACAATCAGGTCTGAGTCGACTGTTGTGC",
                "TCCTGCCGGTTGCTAACTGTAGACGTTTACCCCTT",
                "TCCCTCCCTAACTCTAGGCTACTGTCGTCCGCAGT",
                "AGGCAGAAAGACAACGGTAGTAATCTAGAGACCGT",
                "CGCTCCACGCAGCTCATAGAACCGTGTTGTTCAAC",
                "ACTGTCTCCCGGAAACCATAAACTACTTGGTTTGT",
                "GGTTTTCTTGACTGTAATTACAATCCAGGAGACCA",
                "ATGTCGCTCTACAGTGAACACGTAACTGTCTTCGG"
            };*/
            string result = MedianString(DNA, k);
            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}