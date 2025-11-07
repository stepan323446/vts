using System;
using Education;

namespace MyApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            School vts = new School("VTS");
            Student david = new Student(
                "David", 
                "Katrinka", 
                "1011012101", 
                "26123035"
                );
            
            Student stepan = new Student(
                "Stepan", 
                "Turitsin", 
                "10101101221002", 
                "26123036"
            );
            Student dao = new Student(
                "Dao", 
                "Qin", 
                "10110134234501", 
                "26123000"
            );
            vts.AddStudents(david, stepan, dao);
            
            vts.BanStudent(dao);
            vts.CompleteEducationStudent(david);
            vts.CompleteEducationStudent(stepan);
            
            Console.WriteLine("Hello World!");
        }
    }
}