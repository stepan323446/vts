using System;
using System.Collections;
using System.IO;
using System.Runtime;
using System.Linq;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            NumbersFromFile();
            
            Divider();
            
            OptionsWithText();
        }

        static void OptionsWithText()
        {
            string str =
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse vehicula lacinia sapien, a iaculis elit blandit sed. Proin placerat mattis dolor, in feugiat magna consectetur a. Nullam purus orci, blandit eget turpis ut, accumsan fermentum justo. Suspendisse lobortis, est a blandit viverra, massa tortor vestibulum enim, ac consectetur libero lorem efficitur justo. Suspendisse sit amet suscipit quam, eget mollis turpis. Proin ut elementum diam. Suspendisse non convallis tellus. Suspendisse finibus ultrices ante sed consequat. Praesent quis gravida metus. Donec ut sapien ac tellus dictum pharetra.\nFusce imperdiet turpis congue efficitur pellentesque. Phasellus pretium et tortor sit amet euismod. Duis ut ex quis ex eleifend tincidunt. Maecenas ac mauris ac turpis porta convallis. Nam hendrerit iaculis luctus. Nullam vitae nisi dolor. Aliquam sagittis, tortor et ultricies tempor, sem elit aliquet libero, nec fringilla mi nibh at dolor. Cras imperdiet, mi vitae efficitur tincidunt, neque ante sodales ligula, nec venenatis urna augue eu lacus. Phasellus maximus tellus ex, a tristique risus sollicitudin quis. Vestibulum non semper nisi. Duis eu velit ipsum. Nunc dapibus urna mi, nec iaculis sem feugiat non. Aenean commodo fringilla lobortis. Praesent lacinia dolor odio, et bibendum sem placerat id.";

            string[] separators = { ".", " ", ",", "\n" };
            string[] words = str.Split(separators, StringSplitOptions.RemoveEmptyEntries);

            Dictionary<string, int> counterWords = new Dictionary<string, int>();
            foreach (string word in words)
            {
                string formattedWord = word.ToLower();
                if (counterWords.ContainsKey(formattedWord))
                    counterWords[formattedWord]++;
                else
                    counterWords.Add(formattedWord, 1);
            }

            foreach (KeyValuePair<string, int> empty in counterWords.OrderBy(key => key.Value))
            {
                Console.WriteLine($"{empty.Key}: {empty.Value}");
            }
             
        }

        static void NumbersFromFile()
        {
            string[] number_lines = File.ReadAllLines("numbers.txt");
            List<int> numbers = new List<int>();

            for (int i = 0; i < number_lines.Length; i++)
            {
                string[] nums = number_lines[i].Split(' ');
                if (nums.Length == 0)
                    continue;

                foreach (string num_str in nums)
                {
                    try
                    {
                        numbers.Add(int.Parse(num_str));
                    }
                    catch (FormatException ex)
                    {
                        numbers.Add(0);
                    }
                }
            }

            numbers.Sort();
            int sum = numbers.Sum();
            int count = numbers.Count;

            string numbersString = String.Join(", ", numbers);
            Console.WriteLine($"Numbers: {numbersString}");

            Divider();
            Console.WriteLine($"Sum: {sum}");
            Console.WriteLine($"Count numbers: {count}");
        }
        static void Divider()
        {
            Console.WriteLine("===========================");
        }
    }
}