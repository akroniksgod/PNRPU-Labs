using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Program
    {
        static Random rnd = new Random();
        static bool IsVowel(char item)
        {
            string al = "eEyYuUiIoOaA";
            for (int i = 0; i < al.Length; i++)
            {
                if (item == al[i])
                    return true;
            }
            return false;
        }
        static bool ContainsCyrillicLetters(string toComp)
        {
            string al = "йцукенгшщзхъёфывапролджэячсмитьбюЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
            for (int i = 0; i < toComp.Length; i++)
            {
                for (int j = 0; j < al.Length; j++)
                {
                    if (toComp[i] == al[j])
                        return true;
                }                
            }
            return false;
        }
        static void CreateCharArrWithRandom(ref char[] arr)
        {
            string al = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = al[rnd.Next(0, al.Length - 1)];
            }
        }        
        static void CreateCharArrManually(ref char[] arr)
        {
            Console.WriteLine($"Введите строку размером {arr.Length} латинскими символами");
            bool isFine = false;
            do
            {
                string temp = Console.ReadLine();
                if (temp.Length <= arr.Length && !ContainsCyrillicLetters(temp))
                {
                    arr = temp.ToCharArray();
                    isFine = true;
                }
                else
                {
                    Console.WriteLine("Ошибка ввода!");
                }
            } while (!isFine);            
            
        }
        static void RemoveLastVowelFrom(ref char[] arr)
        {
            char[] tmpArr = new char[arr.Length - 1];
            int index = 0;
            bool containsVowels = false;
            for (int i = arr.Length - 1; i >= 0 && !containsVowels; i--)
            {
                if (IsVowel(arr[i]))
                {
                    index = i;
                    containsVowels = true;
                }
            }
            
            if (containsVowels)
            {
                Array.Copy(arr, 0, tmpArr, 0, index);
                Array.Copy(arr, index + 1, tmpArr, index, arr.Length - index - 1);
                Array.Clear(arr, 0, arr.Length);
                tmpArr.CopyTo(arr, 0);
                tmpArr = null;
                Console.WriteLine("Была удалена гласная буква\n");
            }
            else
                Console.WriteLine("Гласных букв нет!\n");
        }
        static void MenuForCreating(ref char[] arr)
        {
            bool exit = false;
            do
            {
                Console.WriteLine("1. Сформировать массив вручную\n2. Сформировать массив с помощью ДСЧ\n3. Назад\n");
                
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            CreateCharArrManually(ref arr);
                            Console.WriteLine("Массив сформирован\n");
                            break;
                        }
                    case "2":
                        {
                            CreateCharArrWithRandom(ref arr);
                            Console.WriteLine("Массив сформирован\n");
                            break;
                        }
                    case "3":
                        {
                            exit = true;
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода\n");
                        break;
                }
            } while (!exit);            
        }        
        static void Menu()
        {
            bool exit = false;
            char[] arr = null;
            int len = 0;
            do
            {
                Console.WriteLine("1. Сформировать массив символов\n2. Удалить последнюю гласную\n3. Печать\n4. Выход из программы");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            len = InsertVariables("Введите размер массива ");
                            arr = new char[len];
                            MenuForCreating(ref arr);                            
                            break;
                        }
                    case "2":
                        {
                            if (arr != null)
                            {
                                RemoveLastVowelFrom(ref arr);
                            }                                
                            else
                                Console.WriteLine("Массив пуст\n");
                            break;
                        }                        
                    case "3":
                        {
                            if (arr != null)
                            {
                                if (arr[0] != '\0')
                                    PrintCharArr(arr);
                                else
                                    Console.WriteLine("Массив пуст\n");
                            }                                
                            else
                                Console.WriteLine("Массив пуст\n");
                            break;
                        }
                    case "4": exit = true; break;
                    default:
                        Console.WriteLine("Ошибка ввода\n");
                        break;
                }
            } while (!exit);
        }
        static void Main(string[] args)
        {
            Menu();        
        }
        static void PrintCharArr(char[] arr)
        {
            foreach (char item in arr)
            {
                Console.Write($"{item}");
            }
            Console.WriteLine();
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
    }
}
