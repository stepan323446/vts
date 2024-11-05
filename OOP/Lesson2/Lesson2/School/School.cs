using Social;
using Utils;

namespace Education;

public class School : ISocialStructure 
{
    public string name { get; set; }
    public string country_code { get; set; }
    
    private List<Student> students = new List<Student>();

    public School(string name, string country_code = "sr")
    {
        this.name = name;
        this.country_code = country_code;
    }

    public void AddStudents(params Student[] students) => this.students.AddRange(students);

    public void BanStudent(Student student, string reason)
    {
        student.completedEducation = false;
        this.students.Remove(student);
        ConsoleUtils.WriteLineColor(reason, ConsoleColor.Red);
    }
    public void BanStudent(Student student) => this.BanStudent(student, "Not pass Abu Exam");
    
    public void CompleteEducationStudent(Student student)
    {
        student.completedEducation = true;
        this.students.Remove(student);
        ConsoleUtils.WriteLineColor($"Thanks for your time, {student.name}!", ConsoleColor.Green);
    }
}