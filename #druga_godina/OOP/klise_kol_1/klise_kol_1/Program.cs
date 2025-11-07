using System.Globalization;
using System.Text;

namespace klise_kol_1;

class Program
{
    static void Main(string[] args)
    {
        Separator(1);
        string text = "U nasej ucionici TV ima crnu boju, a tabla ima belu boju.";
        // a) Ispišite tekst velikim slovima. (2P
        Console.WriteLine(text.ToUpper());
        // b) Ispišite u obrnutom redosledu. (2P)
        Console.WriteLine(text.ToCharArray().Reverse().ToString());
        // c) Izmenite string da sadrži samo mala slova i ispišite string. (2P)
        string changedText = text.ToLower();
        Console.WriteLine(changedText);
        // d) Indeks reči TV. (2P)
        Console.WriteLine(text.IndexOf("TV"));
        
        Separator(2);
        // Get data
        string fileDataPath = @"/home/steve-dekart/Документы/Programming/vts/OOP/#files/bank1.txt";
        string[] lines = File.ReadAllLines(fileDataPath);
        
        List<Employer> employers = new List<Employer>();
        
        Dictionary<string, int> educations = new Dictionary<string, int>();
        foreach (string line in lines)
        {
            // Set new employer
            Employer employer = (Employer)line;
            employers.Add(employer);
            
            // 3. Education counter
            if(educations.ContainsKey(employer.education))
                educations[employer.education]++;
            else
                educations.Add(employer.education, 1);
        }
        
        // 3. Ispišite jedinstvena obrazovanja i koliko ih ima (Dictionary za podatke o obrazovanju "education".) (6P)
        foreach (KeyValuePair<string, int> education in educations)
        {
            Console.WriteLine($"Education \"{education.Key}\": {education.Value}");
        }
        
        // 4. Ispišite one radnike kojima je obrazovanje osnovno (education = primary), koji su nezaposleni (Job = unemployed), imaju dugove prema banci (loan + yes) i balans u banci veći od 1000 (balance >1000). (5P)
        
        Employer[] employerPrimaryEducation = employers.Where(emp => emp.education == "primary").ToArray();
        PrintEmployerCategories(employerPrimaryEducation, "radnike kojima je obrazovanje osnovno (education = primary)");
        
        Employer[] employerNoJob = employers.Where(emp => emp.job == "unemployed").ToArray();
        PrintEmployerCategories(employerNoJob, "koji su nezaposleni (Job = unemployed)");
        
        Employer[] balanceMore1000 = employers.Where(emp => emp.salary > 1000).ToArray();
        PrintEmployerCategories(balanceMore1000, "balans u banci veći od 1000 (balance >1000)");
    }

    static void Separator(int n)
    {
        Console.WriteLine($"================ {n} zadatak  ================\n");
    }

    static void PrintEmployerCategories(Employer[] employers, string category)
    {
        Console.WriteLine($"{category}:");
        foreach(Employer employer in employers)
            Console.WriteLine($"Education: {employer.education}, salary: {employer.salary}, job: {employer.job}");
    }
    
    public static string cutter(StringBuilder line, string delim)
    {
        string oneLine = line.ToString();
        int x = oneLine.IndexOf(delim);
        int length = delim.Length;
        if (x == -1)
        {
            x = oneLine.Length;
            length = 0;
        }
        string result = oneLine.Substring(0, x);
        line.Remove(0, x + length);
        Console.WriteLine("Ostatak: " + line.ToString());
        return result;
    }

    public static void parseLine(string line)
    {
   
//StringBuilder logLine = new StringBuilder();
//  ovo je linija koda zbog koje je bila greska na casu i zbog cega je izbacivalo gresku za metod parseDate 
// treba da bude konstruktor sa prametrom, a parameter je ulazni podatak tipa string  (line) metode LogEntry
//sve ostalo sto smo radili na casu je dobro

        StringBuilder logLine = new StringBuilder(line); //ß ovako je ispravno
        Console.WriteLine(line);
        string ip = cutter(logLine, " ");
        Console.WriteLine("IP adresa: " + ip);
        cutter(logLine, " "); //brisemo deo podataka koji nam ne treba
        cutter(logLine, "[");
        string dateString = cutter(logLine, " ");
        Console.WriteLine("Datum: "+dateString);
        DateTime date=parseDate(dateString);
        Console.WriteLine("Datum (kao DateTime tip):"+date.ToString()); 
            
        cutter(logLine, " \"");
        string request = cutter(logLine, "\"");
        Console.WriteLine("Request: "+request);
        cutter(logLine, " ");
        string statusStr= cutter(logLine, " ");
        int status=int.Parse(statusStr);
        Console.WriteLine("Status: "+status);
            
        string returnedBytesStr=cutter(logLine, " ");
        int returnedBytesInt=int.Parse(returnedBytesStr);
        Console.WriteLine("Bytes: "+returnedBytesInt);
    }
    private static DateTime parseDate(string dateString)
    {
            
        //21/Sep/2015:07:59:14
        string format = "//dd/MM/yyyy:HH:mm:ss";
        CultureInfo provider = CultureInfo.InvariantCulture;

        return DateTime.ParseExact(dateString, format, provider);
        /*
        StringBuilder date = new StringBuilder(dateString);
        int x = dateString.IndexOf(":");
        date.Replace(":", " ", x, 1);
        return DateTime.Parse(date.ToString());
        */
    }


}