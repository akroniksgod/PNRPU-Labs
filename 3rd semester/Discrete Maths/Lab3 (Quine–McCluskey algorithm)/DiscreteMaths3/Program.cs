using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiscreteMaths3
{
    class Program
    {
        static List<List<bool>> implicantTable;//bool[,] implicantTable;
        static void Main(string[] args)
        {
            //1111111111110001
            //1110110011001100
            //1000100000111111 - 4 variables
            //1110000111100101 - 5 variables

            string vector = InputVector();
            List<string> truthTable = new List<string>(),
                constituents = new List<string>();
            CreateTruthTable(vector, ref truthTable, ref constituents);
            PrintTruthTable(truthTable);

            Console.WriteLine("ДНФ");
            PrintDNF(constituents);

            List<string> gluedConstituents = new List<string>();
            gluedConstituents.AddRange(constituents);
            
            GluingConstituents(ref gluedConstituents);            
            AbsorpSDNF(ref gluedConstituents);
            
            Console.WriteLine("CДНФ");
            PrintDNF(gluedConstituents);

            implicantTable = new List<List<bool>>();//new bool[gluedConstituents.Count, constituents.Count];
            CreateImplicantTable(constituents, gluedConstituents);
            PrintImplicantTable(constituents, gluedConstituents);

            List<int> minRows = new List<int>();
            minRows = FindRowsMinNum(minRows, 0, 0);
            minRows.Sort();
            PrintResult(minRows, gluedConstituents);
        }
        static string InputVector()
        {
            string inputVector = "";
            Console.Write("Введите вектор: ");
            bool isCorrectSize = false;
            do
            {
                inputVector = Console.ReadLine();
                if (inputVector.Length != 16 && !ContainsOnesAndZeros(inputVector))
                    Console.Write("Ошибка, введите вектор заново\n>");
                else
                    isCorrectSize = true;                    
            } while (!isCorrectSize);

            return inputVector;
        }
        static bool ContainsOnesAndZeros(string inputVector)
        {
            for (int i = 0; i < inputVector.Length; i++)
            {
                if (inputVector[i] != '1' || inputVector[i] != '0')
                    return false;
            }
            return true;
        }
        static void CreateTruthTable(string vector, ref List<string> truthTable, ref List<string> constituents)
        {
            int numeralSystem = 2;
            for (int i = 0; i < 16; i++)
            {
                string binaryNum = "";
                CalculateBinNum(i, numeralSystem, ref binaryNum);
                AddZerosToBinNum(i, ref binaryNum);

                binaryNum = ReverseString(binaryNum);

                if (vector[i] == '1')
                {
                    string inLetters = "";
                    inLetters = InLettersBinNum(binaryNum);
                    constituents.Add(inLetters);
                }

                string toAddToArr = binaryNum + " " + vector[i];
                truthTable.Add(toAddToArr);
            }
        }
        static void CalculateBinNum(int n, int numeralSystem, ref string binaryNum)
        {
            StringBuilder str = new StringBuilder();
            while (n > 0)
            {
                str.Append(n % numeralSystem);
                n /= numeralSystem;
            }
            binaryNum = str.ToString();
        }
        static void AddZerosToBinNum(int tmpN, ref string result)
        {
            StringBuilder str = new StringBuilder();
            str.Append(result);
            if (tmpN == 0)
                str.Append("0000");
            else if (tmpN < 2)
                str.Append("000");
            else if (tmpN < 4)
                str.Append("00");
            else if (tmpN < 8)
                str.Append("0");
            
            result = str.ToString();
        }
        static string ReverseString(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
        static string InLettersBinNum(string binNumber)
        {
            string al = "xyzw", inverseAl = "XYZW";
            StringBuilder str = new StringBuilder();
            for (int i = 0, j = -1; i < binNumber.Length; i++)
            {
                j++;
                if (binNumber[i] == '1')
                    str.Append(al[j]);
                else
                    str.Append(inverseAl[j]);
            }
            return str.ToString();
        }
        static void PrintTruthTable(List<string> truthTable)
        {
            Console.WriteLine("Таблица истинности\nxyzw f\n");
            for (int i = 0; i < truthTable.Count; i++)
            {
                Console.Write(truthTable[i] + "\n");
            }
            Console.WriteLine();
        }
        static void PrintDNF(List<string> constituents)
        {
            Console.Write($"F = {PrintConstituent(constituents[0])}");
            for (int i = 1; i < constituents.Count; i++)
            {
                Console.Write($" + {PrintConstituent(constituents[i])}");
            }
            Console.WriteLine("\n");
        }
        static string PrintConstituent(string constituent)
        {
            string al = "xyzw", invAl = "XYZW";
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < constituent.Length; i++)
            {
                if (constituent[i] == 'X')
                    res.Append("!" + al[0]);
                if (constituent[i] == 'Y')
                    res.Append("!" + al[1]);
                if (constituent[i] == 'Z')
                    res.Append("!" + al[2]);
                if (constituent[i] == 'W')
                    res.Append("!" + al[3]);
                if (constituent[i] == 'x')
                    res.Append(al[0]);
                if (constituent[i] == 'y')
                    res.Append(al[1]);
                if (constituent[i] == 'z')
                    res.Append(al[2]);
                if (constituent[i] == 'w')
                    res.Append(al[3]);
            }
            return res.ToString();
        }
        static void GluingConstituents(ref List<string> constituentsToGlue)
        {
            int changesCount = 0, count = 1;
            do
            {
                changesCount = 0;
                List<int> usedPairNumbers = new List<int>();
                List<string> tempCorrectPairs = new List<string>();
                for (int i = 0; i < constituentsToGlue.Count - 1; i++)
                {
                    int loopChangesCount = 0;
                    string pair1 = constituentsToGlue[i];
                    for (int j = i + 1; j < constituentsToGlue.Count; j++)
                    {
                        string pair2 = constituentsToGlue[j], resPair = "";
                        if (MightBeGlued(pair1, pair2))
                        {
                            resPair = Glue(pair1, pair2);
                            tempCorrectPairs.Add(resPair);

                            usedPairNumbers.Add(i);
                            usedPairNumbers.Add(j);
                            changesCount++;
                        }
                    }
                }
                usedPairNumbers = usedPairNumbers.Distinct().ToList();
                usedPairNumbers.Sort();
                
                //in case pairs with higher indexes not included
                List<int> notUsedPairs = new List<int>();
                if (usedPairNumbers.Count != constituentsToGlue.Count)
                {
                    for (int i = usedPairNumbers.Count; i < constituentsToGlue.Count; i++)
                    {
                        if (!usedPairNumbers.Contains(i))
                            notUsedPairs.Add(i);
                    }
                }
                notUsedPairs.Sort();
                notUsedPairs = notUsedPairs.Distinct().ToList();
                AddUnusedConstituents(usedPairNumbers, ref constituentsToGlue, ref tempCorrectPairs, notUsedPairs);

                DeleteDublicates(ref tempCorrectPairs);

                if (changesCount > 0)
                {
                    constituentsToGlue.Clear();
                    constituentsToGlue.AddRange(tempCorrectPairs);
                }

                Console.Write($"{count++})\n");
                PrintConstituentsList(constituentsToGlue);
            } while (changesCount > 0);
        }
        static bool MightBeGlued(string pair1, string pair2)
        {
            if (pair1.Length != pair2.Length)
                return false;

            int diffCount = 0;
            int length = pair1.Length;
            for (int i = 0; i < length; i++)
            {
                if (pair1[i] != pair2[i])
                {
                    if (!AreEqualLetters(pair1[i], pair2[i]))
                        return false;
                    else
                        diffCount++;
                }
            }
            if (diffCount > 1)
                return false;

            return true;
        }
        static bool AreEqualLetters(char first, char second)
        {
            if (first == 'x' && second == 'X' || first == 'X' && second == 'x')
                return true;
            if (first == 'y' && second == 'Y' || first == 'Y' && second == 'y')
                return true;
            if (first == 'z' && second == 'Z' || first == 'Z' && second == 'z')
                return true;
            if (first == 'w' && second == 'W' || first == 'W' && second == 'w')
                return true;

            return false;
        }
        static string Glue(string pair1, string pair2)
        {
            StringBuilder resPair = new StringBuilder();
            for (int i = 0; i < pair1.Length; i++)
            {
                if (pair1[i] == pair2[i])
                    resPair.Append(pair1[i]);
            }
            return resPair.ToString();
        }
        static void AddUnusedConstituents(List<int> usedPairNumbers, ref List<string> correctPairs, ref List<string> tempCorrectPairs, List<int> notUsedPairs)
        {
            int counter = 0, size = usedPairNumbers.Count;

            for (int i = 0; i < size; i++)
            {
                if (counter != usedPairNumbers[i])
                {
                    tempCorrectPairs.Add(correctPairs[counter]);
                    usedPairNumbers.Add(counter);
                    --i;
                }
                counter++;
            }

            foreach (int item in notUsedPairs)
                tempCorrectPairs.Add(correctPairs[item]);
        }
        static void DeleteDublicates(ref List<string> correctPairs)
        {
            correctPairs.Sort();
            correctPairs = correctPairs.Distinct().ToList();
        }
        static void PrintConstituentsList(List<string> pairs)
        {
            string al = "xyzw", invAl = "XYZW";
            for (int i = 0; i < pairs.Count; i++)
            {
                for (int j = 0; j < pairs[i].Length; j++)
                {
                    if (pairs[i][j] == 'X')
                        Console.Write($"!{al[0]} ");//cout << "!" << al[0] << " ";
                    if (pairs[i][j] == 'Y')
                        Console.Write($"!{al[1]} ");//cout << "!" << al[1] << " ";
                    if (pairs[i][j] == 'Z')
                        Console.Write($"!{al[2]} ");//cout << "!" << al[2] << " ";
                    if (pairs[i][j] == 'W')
                        Console.Write($"!{al[3]} ");//cout << "!" << al[3] << " ";
                    if (pairs[i][j] == 'x')
                        Console.Write($"{al[0]} ");//cout << al[0] << " ";
                    if (pairs[i][j] == 'y')
                        Console.Write($"{al[1]} ");//cout << al[1] << " ";
                    if (pairs[i][j] == 'z')
                        Console.Write($"{al[2]} ");//cout << al[2] << " ";
                    if (pairs[i][j] == 'w')
                        Console.Write($"{al[3]} ");//cout << al[3] << " ";
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void AbsorpSDNF(ref List<string> constituentsToAbsorb)
        {
            for (int i = 0; i < constituentsToAbsorb.Count - 1; i++)
            {
                int index = i + 1, differences = 0, similarities = 0;
                if (constituentsToAbsorb[i] != constituentsToAbsorb[index])
                {
                    int size = (constituentsToAbsorb[i].Length > constituentsToAbsorb[index].Length) ? 
                        constituentsToAbsorb[i].Length 
                        : constituentsToAbsorb[index].Length;

                    if (constituentsToAbsorb[i].Contains(constituentsToAbsorb[index])
                        || constituentsToAbsorb[index].Contains(constituentsToAbsorb[i]))
                    {
                        if (constituentsToAbsorb[i].Length == size)
                            constituentsToAbsorb.RemoveAt(i);
                        else
                            constituentsToAbsorb.RemoveAt(index);
                    }
                }
            }
        }
        static void CreateImplicantTable(List<string> constituents, List<string> gluedConstituents)
        {
            for (int i = 0; i < gluedConstituents.Count; i++)
            {
                List<bool> tmpMatr = new List<bool>();
                for (int j = 0; j < constituents.Count; j++)
                {
                    bool elem = FindSubsrtInStr(gluedConstituents[i], constituents[j]);                    
                    tmpMatr.Add(elem);//implicantTable[i][j] = elem;
                }
                implicantTable.Add(tmpMatr);
            }
        }
        static bool FindSubsrtInStr(string subStr, string str)
        {
            int foundCounter = 0;
            for (int i = 0; i < subStr.Length; i++)
            {
                if (str.Contains(subStr[i]))
                    foundCounter++;
            }
            if (foundCounter == subStr.Length)
                return true;
            return false;
        }
        static void PrintImplicantTable(List<string> constituents, List<string> gluedConstituents)
        {
            Console.Write(" ");
            for (int i = 0; i < constituents.Count; i++)
            {
                Console.Write("\t" + constituents[i] + " ");
            }
            Console.WriteLine();

            for (int i = 0; i < gluedConstituents.Count; i++)
            {
                Console.Write(PrintConstituent(gluedConstituents[i]) + " ");
                for (int j = 0; j < implicantTable[i].Count; j++)
                {
                    if (implicantTable[i][j])
                        Console.Write("\t 1  ");
                    else
                        Console.Write("\t    ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static List<int> FindRowsMinNum(List<int> solution, int str, int col)
        {
            if (str < implicantTable.Count && col < implicantTable[str].Count && str >= 0 && col >= 0)
            {
                if (implicantTable[str][col])
                {
                    if (!solution.Contains(str)) 
                        solution.Add(str);
                    return FindRowsMinNum(solution, str, col + 1);
                }
                else
                {
                    bool isFirst = true;
                    for (var i = 0; i < implicantTable.Count; i++)//implicantTable.Count - 1; i >= 0; i--)
                    {                        
                        if (implicantTable[i][col])
                        {
                            var tempList = new List<int>(solution);
                            if (!tempList.Contains(i)) 
                                tempList.Add(i);

                            tempList = FindRowsMinNum(tempList, i, col + 1);
                            if (isFirst) 
                                solution = tempList;
                            else
                            {
                                if (tempList.Count < solution.Count)
                                    solution = tempList;
                            }                                
                            isFirst = false;
                        }   
                    }
                    return solution;
                }
            }
            else 
                return solution;
        }
        static void PrintResult(List<int> answer, List<string> gluedConstituents)
        {
            Console.Write("\nF = " + PrintConstituent(gluedConstituents[answer[0]]));
            for (int i = 1; i < answer.Count; i++)
            {
                Console.Write(" + " + PrintConstituent(gluedConstituents[answer[i]]));
            }
            Console.WriteLine();
        }
    }    
}
