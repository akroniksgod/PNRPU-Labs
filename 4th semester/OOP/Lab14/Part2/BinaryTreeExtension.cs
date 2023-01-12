using System;
using System.Collections.Generic;
using System.Linq;
using Lab12;
using PersonLibrary;

namespace Part2
{
    public static class BinaryTreeExtension
    {
        public static IEnumerable<T> Where<T>(this BinaryTree<T> source, Func<T, bool> predicate)
        {
            var result = new List<T>();
            foreach (var item in source)
            {
                if (predicate(item))
                    result.Add(item);
            }
            return result;
        }
        public static int Count<T>(this BinaryTree<T> source, Func<T, bool> predicate)
        {
            var res = 0;
            foreach (var item in source)
            {
                if (predicate(item))
                    res++;
            }
            return res;
        }
        public static int Sum<T>(this BinaryTree<T> source, Func<T, int> selector)
        {
            var sum = 0;
            foreach (var item in source)
            {
                sum += selector(item);
            }
            return sum;
        }
        public static double Average<T>(this BinaryTree<T> source, Func<T, int> selector)
        {
            var sum = source.Sum(selector);
            var count = source.Count;
            return (double)sum / count;
        }
        public static T Max<T>(this BinaryTree<T> source, Func<T, T, T> selector)
        {
            var max = source.Root._value;
            foreach (var item in source)
            {
                max = selector(max, item);
            }
            return max;
        }
        public static T Min<T>(this BinaryTree<T> source, Func<T, T, T> selector)
        {
            var min = source.Root._value;
            foreach (var item in source)
            {
                min = selector(min, item);
            }
            return min;
        }
    }
}