using System;
using System.Collections.Generic;

namespace Deijkstra
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] matr = InputMatr(1, 8);
            Deijkstra(matr, 0);
            matr = InputMatr(1, 6);
            Deijkstra(matr, 0);
            //matr = InputMatr(4, 8);
            //Deijkstra(matr, 4);
            matr = InputMatr(2, 6);
            //Deijkstra(matr, 1, 6);
        }
		
        private static void Deijkstra(int[,] matr, int startingEdge)
        {
            int count = matr.GetLength(0);
            int[] minDistance = new int[count];                
            int beginIndex = 0;
            CalculateShortestPath(ref matr, ref minDistance, ref beginIndex);
            RestoringRoute(matr, count, minDistance, beginIndex, startingEdge);            
        }
		
        private static void CalculateShortestPath(ref int[,] matr, ref int[] minDistance, ref int beginIndex)
        {
            int size = matr.GetLength(0);
            int[] visitedPoints = new int[size];
            //Инициализация вершин и расстояний
            for (int i = 0; i < size; i++)
            {
                minDistance[i] = 10000;
                visitedPoints[i] = 1;
            }

            int temp, minIndex, min;            

            minDistance[beginIndex] = 0;
            // Шаг алгоритма
            do
            {
                minIndex = 10000;
                min = 10000;
                for (int i = 0; i < size; i++)
                { // Если вершину ещё не обошли и вес меньше min
                    if (visitedPoints[i] == 1 && minDistance[i] < min)
                    { // Переприсваиваем значения
                        min = minDistance[i];
                        minIndex = i;
                    }
                }
                // Добавляем найденный минимальный вес
                // к текущему весу вершины
                // и сравниваем с текущим минимальным весом вершины
                if (minIndex != 10000)
                {
                    for (int i = 0; i < size; i++)
                    {
                        if (matr[minIndex, i] > 0)
                        {
                            temp = min + matr[minIndex, i];
                            if (temp < minDistance[i])
                            {
                                minDistance[i] = temp;
                            }
                        }
                    }
                    visitedPoints[minIndex] = 0;
                }
            } while (minIndex < 10000);

            // Вывод кратчайших расстояний до вершин
            Console.WriteLine("\nКратчайшие расстояния до вершин: \n");
            for (int i = 0; i < size; i++)
                if (i < size - 1)
                    Console.Write(minDistance[i] + "=>");
                else
                    Console.Write(minDistance[i]);
        }
		
        private static void RestoringRoute(int[,] matr, int size, int[] minDistance,  int beginIndex, int startingEdge)
        {
            // Восстановление пути
            int[] ver = new int[size]; // массив посещенных вершин
            int end = size - 1; // индекс конечной вершины = 5 - 1
            ver[0] = end + 1; // начальный элемент - конечная вершина
            int k = 1; // индекс предыдущей вершины
            int weight = minDistance[end]; // вес конечной вершины

            while (end != beginIndex) // пока не дошли до начальной вершины
            {
                for (int i = 0; i < size; i++) // просматриваем все вершины
                    if (matr[i, end] != 0)   // если связь есть
                    {
                        int tmp = weight - matr[i, end]; // определяем вес пути из предыдущей вершины
                        if (tmp == minDistance[i]) // если вес совпал с рассчитанным
                        {                 // значит из этой вершины и был переход
                            weight = tmp; // сохраняем новый вес
                            end = i;       // сохраняем предыдущую вершину
                            ver[k] = i + 1; // и записываем ее в массив
                            k++;
                        }
                    }
            }
            // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
            Console.WriteLine("\nВывод кратчайшего пути\n");
            for (int i = k - 1; i >= 0; i--)
                Console.Write(ver[i] + startingEdge + " ");
            Console.WriteLine("\n-------------------");
        }
		
        private static int[,] InputMatr(int from, int to)
        {
            Console.WriteLine($"Старт из вершины {from} в вершину {to}");

            int[,] matr = { { 0, 1, 2, 0, 0, 0, 0, 0 },
                            { 0, 0, 1, 5, 2, 0, 0, 0 },
                            { 0, 0, 0, 2, 1, 4, 0, 0 },
                            { 0, 0, 0, 0, 3, 6, 8, 0 },
                            { 0, 0, 0, 0, 0, 3, 7, 0 },
                            { 0, 0, 0, 0, 0, 0, 5, 2 },
                            { 0, 0, 0, 0, 0, 0, 0, 6 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 }
            };
            int newSize = (to - from) % 2 == 0 ? to - from : to - from + 1;
            int[,] newMatr = new int[newSize, newSize];

            Queue<int> q = new Queue<int>();
            for (int i = 0; i < matr.GetLength(0); i++)
            {
                for (int j = 0; j < matr.GetLength(1); j++)
                {
                    if (i >= from - 1 && j <= to - 1)
                        q.Enqueue(matr[i, j]);
                }
            }

            for (int i = 0; i < newMatr.GetLength(0); i++)
            {
                for (int j = 0; j < newMatr.GetLength(1); j++)
                {
                    newMatr[i, j] = q.Dequeue();
                }
            }
            ShowMatrix(newMatr);
            return newMatr;
        }
		
        private static void ShowMatrix(int[,] matr)
        {
            Console.WriteLine("Текущая матрица");
            for (int i = 0; i < matr.GetLength(0); i++)
            {
                for (int j = 0; j < matr.GetLength(1); j++)
                {
                    Console.Write(matr[i, j] + "\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}