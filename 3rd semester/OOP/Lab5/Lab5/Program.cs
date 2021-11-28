using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Runtime.ExceptionServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Lab5
{
    class Program
    {
        static Random rnd = new Random();
        static void MakeOneDimArrDepandingOnChoice(int choice, ref int[] arr)
        {
            if (choice == 1)
                FillArrManually(ref arr);
            else if (choice == 2)
                FillArrRandomly(ref arr);
        }        
        static int[] TryingOneDimensionalArray(int choice)
        {          
            int size = InsertVariables("Введите размер массива ");
            int[] arr = new int[size];

            MakeOneDimArrDepandingOnChoice(choice, ref arr);
            return arr;
        }
        static int[] AddElWithKindex(int[] arr)
        {
            int k = 0;
            ReadElementToAddToArr(ref k, arr.Length);

            //объявление массива размерностью на 1 большей
            int size = arr.Length;
            int[] tmpArr = new int[++size];

            //запись в переменную числа с номером k
            int temp = arr[k];
            arr.CopyTo(tmpArr, 0);

            //вставка того элемента по необходимому месту
            tmpArr[tmpArr.Length - 1] = temp;
            return tmpArr;
        }
        static void MakeTwoDimArrDepandingOnChoice(int choice, ref int[,] table)
        {
            if (choice == 1)
                FillTwoDimensionalArrManually(table);
            else if (choice == 2)
                FillTwoDimensionalArrRandomly(table);
        }
        static int[,] TryingTwoDimensionalArray(int choice)
        {
            int strings = InsertVariables("Введите количество строк"),
                columns = InsertVariables("Введите количество столбцов");
            int[,] table = new int[strings, columns];

            MakeTwoDimArrDepandingOnChoice(choice, ref table);
            return table;            
        }
        
        static int[][] TryingJaggedArray(int choice)
        {
            int strings = InsertVariables("Введите количество строк");
            int[][] jagArr = new int[strings][];

            MakeJaggedArrDepandingOnChoice(choice, ref jagArr);
            return jagArr;
        }
        static void Main(string[] args)
        {
            Menu();
        }
        static bool IsEmpty(int[] arr)
        {
            if (arr == null)
                return true;
            else if (arr.Length == 0)
                return true;
            return false;
        }
        static bool IsEmpty(int[,] arr)
        {
            if (arr == null)
                return true;
            else if (arr.Length == 0)
                return true;
            return false;
        }
        static bool IsEmpty(int[][] arr)
        {
            if (arr == null)
                return true;
            else if (arr.Length == 0)
                return true;
            return false;
        }
        static void MenuOneDimArr()
        {
            int[] arr = null;
            bool CorrectChoice = false;
            do
            {
                Console.Write("1. Создать массив\n" +
                            "2. Напечатать массив\n" +
                            "3. Добавить элемент с номером К в конец\n" +
                            "4. Назад\n");                
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            int choice = DecideRandomOrManualInput();
                            arr = TryingOneDimensionalArray(choice);
                            Console.WriteLine("Массив был создан.\n");
                            break;
                        }
                    case "2":
                        {
                            if (!IsEmpty(arr))
                                PrintArr(arr);
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "3":
                        {
                            if (!IsEmpty(arr))
                            {
                                arr = AddElWithKindex(arr);
                                Console.WriteLine("Добавление произошло!\n");
                            }
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "4":
                        {
                            CorrectChoice = true;
                            Console.WriteLine();
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода!");
                        break;
                }

            } while (!CorrectChoice);            
        }
        static void MenuTwoDimArr()
        {
            int[,] arr = null;
            bool CorrectChoice = false;
            do
            {
                Console.Write("1. Создать массив\n" +
                            "2. Напечатать массив\n" +
                            "3. Удалить строку, в которой находится наибольший элемент матрицы\n" +
                            "4. Назад\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            int choice = DecideRandomOrManualInput();
                            arr = TryingTwoDimensionalArray(choice);
                            Console.WriteLine("Массив был создан.\n");
                            break;
                        }
                    case "2":
                        {
                            if (!IsEmpty(arr))
                                PrintTwoDimensionalArr(arr);
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "3":
                        {
                            if (!IsEmpty(arr))
                            {
                                int stringToRemove = FindMaxElString(arr, arr.GetLength(0), arr.GetLength(1)),
                                    strings = arr.GetLength(0), columns = arr.GetLength(1);

                                int[,] newTable = new int[--strings, columns];

                                arr = RemovingFirstStringWithMaxElement(arr, newTable, stringToRemove);                                
                                Console.WriteLine("Удаление произошло!\n");
                            }
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "4":
                        {
                            CorrectChoice = true;
                            Console.WriteLine();
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода!");
                        break;
                }

            } while (!CorrectChoice);
        }
        static void MenuJagArr()
        {
            int[][] arr = null;
            bool CorrectChoice = false;
            do
            {
                Console.Write("1. Создать массив\n" +
                            "2. Напечатать массив\n" +
                            "3. Добавить строку в начало массива\n" +
                            "4. Назад\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            int choice = DecideRandomOrManualInput();
                            arr = TryingJaggedArray(choice);
                            Console.WriteLine("Массив был создан.\n");
                            break;
                        }
                    case "2":
                        {
                            if (!IsEmpty(arr))
                                PrintJaggedArr(arr);
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "3":
                        {
                            if (!IsEmpty(arr))
                            {
                                int strings = arr.GetLength(0);
                                int[][] newArr = new int[++strings][];

                                Console.WriteLine("\nКоличество элементов в строке, которую вы хотите добавить? ");
                                int size = InsertVariables("Введите размер строки ");
                                int[] strToAdd = new int[size];
                                FillArrRandomly(ref strToAdd);

                                Console.WriteLine("Сгенерированная строка.");
                                PrintArr(strToAdd);

                                arr = AddStringToJaggedArr(strToAdd, arr, newArr);
                                Console.WriteLine("Добавление произошло!\n");
                            }
                            else
                                Console.WriteLine("Массив пуст!\n");
                            break;
                        }
                    case "4":
                        {
                            CorrectChoice = true;
                            Console.WriteLine();
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода!");
                        break;
                }

            } while (!CorrectChoice);
        }
        static void Menu()
        {
            bool CorrectChoice = false;
            do
            {
                Console.Write("1. Работа с одномерным массивом\n" +
                            "2. Работа с двумерным массивом\n" +
                            "3. Работа с рваным массивом\n" +
                            "4. Выход\n");
                switch (Console.ReadLine())
                {
                    case "1": MenuOneDimArr(); break;
                    case "2": MenuTwoDimArr(); break;
                    case "3": MenuJagArr(); break;
                    case "4": CorrectChoice = true; break;
                    default:
                        {
                            Console.WriteLine("Ошибка ввода!");
                            continue;
                        }
                }                
            } while (!CorrectChoice);
        }
        static int DecideRandomOrManualInput()
        {
            bool selected = false;
            int x;
            Console.Write("1. Создать массив вручную\n" +
                            "2. Создать массив с помощью ДСЧ\n");
            do
            {
                if (int.TryParse(Console.ReadLine(), out x) && x > 0  && x < 3)
                    selected = true;
                else
                    Console.WriteLine("Некорректный выбор! Введите заново");
            } while (!selected);
            return x;
        }
        static int[,] RemovingFirstStringWithMaxElement(int[,] table, int[,] newTable, int stringToRemove)
        {
            for (int i = 0; i < stringToRemove; i++)
            {
                for (int j = 0; j < table.GetLength(1); j++)
                {
                    newTable[i, j] = table[i, j];
                }
            }

            for (int i = stringToRemove + 1; i < table.GetLength(0); i++)
            {
                for (int j = 0; j < table.GetLength(1); j++)
                {
                    newTable[i - 1, j] = table[i, j];
                }
            }
            return newTable;
        }
        static int[][] AddStringToJaggedArr(int[] arr, int[][] jagArr, int[][] resJagArr)
        {
            
            resJagArr[0] = new int[arr.Length];

            for (int i = 0; i < arr.Length; i++)
            {
                resJagArr[0][i] = arr[i];
            }

            for (int i = 1; i < resJagArr.Length; i++)
            {
                resJagArr[i] = new int[jagArr[i - 1].Length];
                for (int j = 0; j < resJagArr[i].Length; j++)
                {
                    resJagArr[i][j] = jagArr[i - 1][j];
                }
            }
            return resJagArr;
        }
        static void PrintJaggedArr(int[][] jagArr)
        {
            Console.WriteLine("Сформированный массив.");
            for (int i = 0; i < jagArr.Length; i++)
            {
                for (int j = 0; j < jagArr[i].Length; j++)
                {
                    Console.Write("\t" + jagArr[i][j] + "; ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void MakeJaggedArrDepandingOnChoice(int choice, ref int[][] jagArr)
        {
            if (choice == 1)
                FillJaggedArrManually(jagArr);
            else if (choice == 2)
                FillJaggedArrWithRandom(jagArr);
        }
        static void FillJaggedArrManually(int[][] jagArr)
        {
            for (int i = 0; i < jagArr.Length; i++)
            {
                int colSize = InsertVariables("Введите количество столбцов");    
                
                jagArr[i] = new int[colSize];
                for (int j = 0; j < jagArr[i].Length; j++)
                {
                    jagArr[i][j] = ReadVars("элементы массива");
                }
            }
        }
        static void FillJaggedArrWithRandom(int[][] jagArr)
        {            
            for (int i = 0; i < jagArr.Length; i++)
            {
                jagArr[i] = new int[i + 1];
                for (int j = 0; j < i + 1; j++)
                {
                    jagArr[i][j] = rnd.Next(1, 100);
                }                
            }
        }
        static void PrintTwoDimensionalArr(int [,] arr)
        {
            Console.WriteLine();
            if (arr.GetLength(0) != 0)
            {
                for (int i = 0; i < arr.GetLength(0); i++)
                {
                    for (int j = 0; j < arr.GetLength(1); j++)
                    {
                        Console.Write("\t" + arr[i, j] + " ");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            else
                Console.WriteLine("Пустой массив!\n");
        }
        static int FindMaxElString(int [,] arr, int str, int col)
        {
            int max = arr[0, 0], strOfMaxEl = 0;
            for (int i = 0; i < str; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (arr[i, j] > max)
                    {
                        max = arr[i, j];
                        strOfMaxEl = i;
                    }
                }
            }
            return strOfMaxEl;
        }
        static void FillTwoDimensionalArrManually(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = ReadVars("элемент массива");                   
                }
            }
        }
        static void FillTwoDimensionalArrRandomly(int [,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = rnd.Next(1, 100);
                }
            }
        }
        static void ReadElementToAddToArr(ref int k, int size)
        {
            Console.WriteLine();
            bool isCorrectSize = false;
            do
            {
                k = InsertVariables("Введите k");
                if (--k > (size - 1) || k < 0)
                    Console.WriteLine("Ввыход за пределы массива!");
                else
                    isCorrectSize = true;
            } while (!isCorrectSize);
        }
        static int ReadVars(string toAsk)
        {
            int x;
            bool isParsed = false;
            string str;
            do
            {
                Console.WriteLine("Введите " + toAsk);
                str = Console.ReadLine();
                if (int.TryParse(str, out x))
                    isParsed = true;
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }        
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                    if (x > 0)
                        isParsed = true;
                    else
                        continue;
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }
        static void FillArrRandomly(ref int[] arr)
        {            
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rnd.Next(1, 100);
            }
        }        
        static void FillArrManually(ref int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = ReadVars("элемент массива ");
            }
        }
        static void PrintArr<T>(T[] arr)
        {
            Console.WriteLine();
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + "; ");
            }
            Console.WriteLine();
        }
    }
}
