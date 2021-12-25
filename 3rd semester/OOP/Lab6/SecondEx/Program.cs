using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SecondEx
{
    class Program
    {
        static char[][] CreateJaggedCharArr(string[] strArr)
        {
            char[][] jagArr = new char[strArr.Length][];
            for (int i = 0; i < strArr.Length; i++)
            {
                jagArr[i] = strArr[i].ToCharArray();
            }
            return jagArr;
        }
        static void ReverseElements(ref char[][] jagArr)
        {
            for (int i = 0; i < jagArr.Length; i++)
            {
                if (jagArr[i].Length == (i + 1) && jagArr.Length != 1)
                {
                    Array.Reverse(jagArr[i]);
                }
            }
        }
        static string[] ConvertToString(char[][] jagArr)
        {
            string[] strArr = new string[jagArr.Length];
            for (int i = 0; i < jagArr.Length; i++)
            {
                string tmp = new string(jagArr[i]);
                strArr[i] = tmp;
            }
            return strArr;
        }
        static void RevWordsWithNumCorrWithLen(ref string[] strArr)
        {
            char[][] jagArr = CreateJaggedCharArr(strArr);            
            ReverseElements(ref jagArr);
            strArr = ConvertToString(jagArr);            
        }
        static string[] SplitMyString(string inp)
        {
            string[] separators = { " ", ",", ", ", ".", ". ", "!", "! ", "—", "–", "?", ";", ":" };
            string[] strArr = inp.Split(separators, StringSplitOptions.RemoveEmptyEntries);
            return strArr;
        }
        static string Menu()
        {
            bool toExit = false;
            string res = "";
            do
            {                
                Console.WriteLine("1. Ввести строку самостоятельно\n" +
                            "2. Использовать заготовленную строку\n" +
                            "3. Функции\n" + "4. Выход из программы\n");
                switch (Console.ReadLine())
                {
                    case "1": 
                        { 
                            Console.WriteLine("Введите строку"); 
                            res = Console.ReadLine(); 
                            break; 
                        }
                    case "2":
                        {
                            res = "Не поклонясь до избы, и грибов не поднимешь. Когда поднимается одна пылинка, в ней содержится вся земля, когда распускается один цветок, раскрывается целый мир";
                            Console.WriteLine("Введённая строка: " + res + "\n");
                            break;
                        }                                                                   
                    case "3": toExit = true; break;
                    case "4":
                        {
                            toExit = true;
                            res = "4";
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка выбора!");
                        break;
                }
            } while (!toExit);
            return res;
        }
        static void Task(string inp)
        {
            bool toExit = false;
            string[] strArr = null;
            do
            {
                Console.WriteLine("1. Разбить строку на слова в массив строк\n" +
                            "2. Перевернуть каждое слово, номер которого совпадает с его длиной\n" +
                            "3. Печать массива строк\n" +
                            "4. Печать строки\n" +
                            "5. Назад\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            if (inp != "")
                            {
                                strArr = SplitMyString(inp);                                
                                Console.WriteLine("Строка успешно разбита по словам в массиве строк!\n");
                            }
                            else
                                Console.WriteLine("Строка пустая!\n");
                            break;
                        }
                    case "2":
                        {
                            if (strArr != null)
                            {
                                RevWordsWithNumCorrWithLen(ref strArr);
                                Console.WriteLine("Слова в массиве строк были перевёрнуты\n");
                            }       
                            else
                                Console.WriteLine("Массив строк пуст!\n");
                            break;
                        }
                    case "3":
                        {
                            if (strArr != null)
                                PrintStrArr(strArr);
                            else
                                Console.WriteLine("Массив строк пуст!\n");
                            break;
                        }
                    case "4":
                        {
                            if (strArr != null)
                            {
                                string res = string.Join(" ", strArr);
                                Console.WriteLine(res + "\n");
                            }
                            else
                                Console.WriteLine("Массив строк пуст!\n");
                            break;
                        }
                    case "5": toExit = true; break;
                    default:
                        Console.WriteLine("Ошибка выбора!");
                        break;
                }
            } while (!toExit);
        }
        static void Task2()
        {
            bool exit = false;
            do
            {
                string inp = Menu();
                if (inp != "4")
                    Task(inp);
                else
                    exit = true;
            } while (!exit);
           
        }
        static void Main(string[] args)
        {
            Task2();            
        }
        static void PrintStrArr(string[] strArr)
        {
            int count = 1;
            foreach (string item in strArr)
            {
                Console.WriteLine($"{count}) {item}  \tlen = {item.Length}");
                count++;
            }
            Console.WriteLine();
        }
    }
}
