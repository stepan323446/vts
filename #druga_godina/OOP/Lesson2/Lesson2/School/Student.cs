using Social;
namespace Education;



public class Student : IPerson
{
    // IPerson
    public string name { get; set; }
    public string surname { get; set; }
    public string jmbg { get; set; }
    public bool isAlive { get; set; }
    
    public string index { get; set; }
    public bool completedEducation { get; set; }

    public Student(string name, string surname, string jmbg, string index)
    {
        this.name = name;
        this.surname = surname;
        this.index = index;
        this.jmbg = jmbg;
        
        this.isAlive = true;
        this.completedEducation = false;
    }
}