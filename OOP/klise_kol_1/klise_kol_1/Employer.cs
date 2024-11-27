namespace klise_kol_1;

public class Employer
{
    // a) Svi atributi su privatni.
    // b) Set i Get metode.
    public int age { get; set; }
    public string job { get; set; }
    public string education { get; set; }
    public int salary { get; set; }
    public bool isEmployed { get; set; }


    // d) Definisati konstruktor sa parametrima za inicijalizaciju atributa.
    public Employer(int age, string job, string education, int salary, bool isEmployed)
    {
        this.age = age;
        this.job = job;
        this.education = education;
        this.salary = salary;
        this.isEmployed = isEmployed;
    }

    public static Employer GetEmployerFromString(string line)
    {
        string[] parts = line.Split(',');
        bool isEmployed = parts[4] == "yes";

        return new Employer(
            int.Parse(parts[0]),
            parts[1],
            parts[2],
            int.Parse(parts[3]),
            isEmployed
        );
    }
    // c) Definisati ToString() metodu, koji vraća podatke o godinama "age" i obrazovanju "education".
    public override string ToString()
    {
        return $"Education: {education}, age: {age}";
    }
}