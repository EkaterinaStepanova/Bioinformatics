using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._1_Motif_Enumeration_Problem
{
    class Program
    {
        static int CountMismatches(string original, string kmer)
        {
            int count = 0;
            for (int i = 0; i < original.Length; i++)
            {
                if (original[i] != kmer[i])
                {
                    count++;
                }

              
            }

            return count;
        }
        static List<string> CreateWords(string text, int length)
        {
            List<string> words = new List<string>((int)Math.Pow(4, length));
            CreateAllWords(ref words, text, length);
            return words;
        }
        static void CreateAllWords(ref List<string> words, string text, int length, string currentStr ="")
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
        
        static List<string> GetAllKDMotifs(string kMer, int mistake)
        {
            string alphabet = "AGCT";
            List<string> patterns = new List<string>();

            foreach (var item in CreateWords(alphabet, kMer.Length))
            {
                if (mistake >= CountMismatches(item.ToString(), kMer))
                {
                    patterns.Add(item.ToString());
                }
            }

            return patterns;
        }
        static List<string> MotifEnumeration(string[] DNA, int k,int d)
        {
            List<string> result = new List<string>();

            foreach (string str in DNA)
            {
                for (int i = 0; i < str.Length - k + 1; i++)
                {
                    string kMer = str.Substring(i, k);

                    foreach (string pattern in GetAllKDMotifs(kMer, d))
                    {
                        int size = 0;
                        foreach (string s in DNA)
                        {
                            for (int j = 0; j < str.Length - k + 1; j++)
                            {
                                if (d >= CountMismatches(s.Substring(j, k), pattern))
                                {
                                    size++;
                                    break;
                                }
                            }
                        }

                        if (size == DNA.Length)
                        {
                            result.Add(pattern);
                        }
                    }
                }
            }

            result = result.Distinct().ToList();

            return result;
        }
        static void Main(string[] args)
        {
            string tmp = Console.ReadLine();
            int k = int.Parse(tmp.Split(' ')[0]);
            int d = int.Parse(tmp.Split(' ')[1]);

            tmp = "";
            while (true)
            {
                string s = Console.ReadLine();
                if (string.IsNullOrEmpty(s))
                    break;

                tmp += s + ' ';
            }
            tmp = tmp.Trim();
           // Console.WriteLine(tmp);
            string[] DNA = tmp.Split(' ');
            
            List<string> patterns = new List<string>();
            patterns = MotifEnumeration(DNA, k, d);

            Console.WriteLine(string.Join(" ", patterns));
            Console.ReadKey();

        }
    }
}
