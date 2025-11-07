using System;
using System.Collections; // ArrayList
using System.Collections.Generic; // Dictionary
using System.Text;

namespace Lesson1
{
    internal class Program
    {
        struct Person
        {
            public string FirstName;
            public string LastName;
            public int Age;

            public Person(string firstName, string lastName, int age)
            {
                this.FirstName = firstName;
                this.LastName = lastName;
                this.Age = age;
            }
        }
        static void Main(string[] args)
        {
            #region Array
            
            int[] arr = new int[3] { 0, 32, 12 };
            arr[0] = 3;
            
            Console.WriteLine("Elemets: " + String.Join(", ", arr));
            Array.Sort(arr);
            foreach (int num in arr)
            {
                PrintColor("num: " + num, ConsoleColor.Green);
            }
            
            #endregion

            Divider();
            
            #region Long string
            
            string pasus =
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam sed metus sed erat volutpat placerat non et diam. Suspendisse vel elementum dui, et mollis orci. Sed aliquam, enim et imperdiet consectetur, lectus dui consectetur mauris, vel bibendum est quam in tortor. Curabitur et lobortis leo, vitae vestibulum ex. Praesent imperdiet cursus nunc, non convallis urna accumsan quis. Etiam facilisis cursus ultricies. Etiam egestas orci eget tellus bibendum eleifend. Mauris tempus venenatis augue.";

            pasus = pasus.Replace(".", "").Replace(",", "").Replace(":", "");
            string[] words = pasus.Split(' ');
            int counterSLetter = 0;
            foreach (var word in words)
            {
                PrintColor(word, ConsoleColor.Cyan);
                if (word.ToLower().StartsWith("s"))
                    counterSLetter++;
            }
            PrintColor("\nCount S letters: " + counterSLetter, ConsoleColor.Green);
            PrintColor("\nCount words: " + words.Length, ConsoleColor.Green);
            
            #endregion

            Divider();
            
            #region StringBuilder
            
            int x = int.Parse("100");
            string strX = x.ToString();
            /*
             * C#: $"variable: {num}"
             * Py: f"variable: {num}"
             * JS: `variable: ${num}`
             */
            string someStr = $"Number: {x}";
            PrintColor(someStr);
            
            string newStr = String.Concat(strX, someStr);
            PrintColor(newStr);
            
            StringBuilder sb = new StringBuilder("Hello world");
            sb.Append(newStr);
            sb.Replace(newStr, " Subotica ");
            PrintColor($"StringBuilder: {sb}", ConsoleColor.Blue);
            PrintColor($"StringBuilder capacitet: {sb.Capacity}", ConsoleColor.Blue);
            PrintColor($"StringBuilder length: {sb.Length}", ConsoleColor.Blue);

            #endregion
            
            
            
            Divider();

            #region Struct

            // Object

            #endregion
            
            // ArrayList
            // Dictionary
        }

        static void PrintColor(string message, ConsoleColor color = ConsoleColor.Green)
        {
            ConsoleColor defaultColor = Console.ForegroundColor;
            Console.ForegroundColor = color;
            Console.WriteLine(message);
            Console.ForegroundColor = defaultColor;
        }

        static void Divider()
        {
            PrintColor("================================", ConsoleColor.Red);
        }
        
    }
}