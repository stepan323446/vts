using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace justfun
{
    internal class Student
    {
        public string Name { get; set; }
        public string Index { get; set; }
        public int Grade { get; set; }

        public string Comment { get; set; }

        public string Passed
        {
            get
            {
                if(Grade <= 5)
                    return "Fail";

                return "Success";
            }
        }

        public Student(string name, string index, int grade, string comment = "")
        {
            Name = name;
            Index = index;
            Grade = grade;
            Comment = comment;
        }
        public string SaveDataLine()
        {
            return $"{Name}:{Index}:{Grade}:{Comment}";
        }
        public static Student LoadDataLine(string line)
        {
            string[] dataString = line.Split(':');
            string name = dataString[0];
            string index = dataString[1];
            int grade = int.Parse(dataString[2]);
            string comment = "";

            if(dataString.Length > 2) 
                comment = dataString[3];

            return new Student(name, index, grade, comment);
        }

        public override string ToString()
        {
            return $"{Index}: {Name} with {Grade}. Additional: {Comment}";    
        }
    }
}
