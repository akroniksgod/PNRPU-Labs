using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Dynamic;
using System.Globalization;
using System.Linq;
using System.Net;
using System.Runtime.Remoting;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace DiscreteMaths2
{
    class Program
    {
        static Random rnd = new Random();
        static bool IsTransitive(int[,] arr)
        {
            int countZeros = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (arr[i, j] == 1)
                    {
                        for (int k = j; k < arr.GetLength(0);)
                        {
                            int countOnes = 0;
                            for (int m = 0; m < arr.GetLength(1); m++)
                            {
                                if (arr[k, m] == 1 && arr[i, m] == 0)
                                    return false;
                                if (arr[k, m] == 1)
                                    countOnes++;
                            }

                            if (countOnes == 0)
                                return false;
                            break;
                        }
                    }
                    if (arr[i, j] == 0)
                        countZeros++;
                }
            }
            if (countZeros >= arr.Length - arr.GetLength(0))
                return false;
            return true;          
        }
        static bool IsTied(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (arr[i, j] == 0 && arr[i, j] == arr[j, i])
                        return false;
                }
            }
            return true;
        }
        static bool IsAntiSymmetric(int[,] arr)
        {
            int diagonal = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (i == diagonal && j == diagonal)
                    {
                        diagonal++;
                        continue;
                    }
                    if (arr[i, j] == arr[j, i] && arr[i, j] != 0)
                        return false;
                }
            }
            return true;
        }        
        static bool IsSymmetric(int[,] arr)
        {
            int countZeros = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (arr[i, j] == 1 && arr[i, j] != arr[j, i])                       
                        return false;
                    if (arr[i, j] == 0)
                        countZeros++;
                }
            }
            if (countZeros >= arr.Length - arr.GetLength(0))
                return false;
            return true;
        }
        static bool IsReflective(int[,] arr)
        {
            int countOnes = 0, k = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = k; j < arr.GetLength(1); )
                {
                    if (arr[i, j] == 1)                    
                        countOnes++;

                    k = ++j;
                    break;
                }
            }
            return countOnes == arr.GetLength(0);
        }
        static bool IsAntiReflective(int[,] arr)
        {
            int countZeros = 0, k = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = k; j < arr.GetLength(1);)
                {
                    if (arr[i, j] == 0)
                        countZeros++;

                    k = ++j;
                    break;
                }
            }
            return countZeros == arr.GetLength(0);
        }        
        static void Main(string[] args)
        {
            bool exit = false;
            do
            {
                int size = 0, choice = 0;
                Menu(ref size);

                if (size != 4)
                    Menu2(ref choice);
                else
                    choice = 3;

                ChangingSizeDepandingOnChoice(ref size);
                int[,] arr = new int[size, size];

                switch (choice)
                {
                    case 1: CreateMatrixWithRandom(arr); break;
                    case 2: CreateMatrixManually(arr); break;
                    case 3: exit = true; break;
                }

                if (!exit)
                {
                    ShowArr(arr);

                    CheckIfReflective(arr);
                    CheckIfSymmetric(arr);
                    CheckIfTied(arr);
                    CheckIfTransitive(arr);
                    Console.WriteLine();
                }
            } while (!exit);                        
        }
        static void CheckIfReflective(int[,] arr)
        {
            if (IsReflective(arr))
                Console.WriteLine("1. Рефлексивно");
            else if (IsAntiReflective(arr))
                Console.WriteLine("1. Антирефлексивно");
            else
                Console.WriteLine("1. Не рефлексивно");
        }
        static void CheckIfSymmetric(int[,] arr)
        {
            if (IsSymmetric(arr))
                Console.WriteLine("2. Симметрично");
            else if (IsAntiSymmetric(arr) && IsAntiReflective(arr))
                Console.WriteLine("2. Асимметрично");
            else if (IsAntiSymmetric(arr))
                Console.WriteLine("2. Антисимметрично");
            else
                Console.WriteLine("2. Не симметрично");
        }
        static void CheckIfTied(int[,] arr)
        {
            if (IsTied(arr))
                Console.WriteLine("3. Связно");
            else
                Console.WriteLine("3. Не связно");
        }
        static void CheckIfTransitive(int[,] arr)
        {
            if (IsTransitive(arr))
                Console.WriteLine("4. Транзитивно");
            else
                Console.WriteLine("4. Не транзитивно");
        }
        static void ChangingSizeDepandingOnChoice(ref int size)
        {
            if (size == 1)
                size = 3;
            else if (size == 2)
                size = 4;
            else if (size == 3)
                size = 5;
            else if (size == 4)
                size = 6;
        }
        static int ReadVars(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.Write(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                    isParsed = true;
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }
        static void Menu(ref int size)
        {
            bool isFine = false;
            Console.WriteLine(@"Выберете размерность матрицы: 
1. 3 x 3
2. 4 x 4
3. 5 x 5
4. Выход");
            do
            {
                size = ReadVars("");
                if (size > 0 && size < 5)
                    isFine = true;
                else
                    Console.WriteLine("Ошибка");
            } while (!isFine);

        }

        static void Menu2(ref int choice)
        {
            bool isFine = false;
            Console.WriteLine(@"
1. Заполнить с помощью ДСЧ
2. Заполнить вручную");
            
            do
            {
                choice = ReadVars("");
                if (choice > 0 && choice < 3)
                    isFine = true;
                else
                    Console.WriteLine("Ошибка");
            } while (!isFine);
        }
        static void CreateMatrixWithRandom(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = rnd.Next(0, 2);
                }
            }
        }
        static void CreateMatrixManually(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    bool isFine = false;
                    do
                    {
                        arr[i, j] = ReadVars("Введите элемент: ");
                        if (arr[i, j] > -1 && arr[i, j] < 2)
                            isFine = true;
                        else
                            Console.WriteLine("Можно вводить только 0 или 1");
                    } while (!isFine);
                }
                Console.WriteLine();
            }
        }
        static void ShowArr(int[,] arr)
        {
            Console.WriteLine("\nПечать матрицы");
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    Console.Write(arr[i, j] + "; ");
                    Console.Write("\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}