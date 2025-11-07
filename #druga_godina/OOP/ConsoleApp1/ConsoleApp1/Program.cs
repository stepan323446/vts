namespace ConsoleApp1;

// 1) Napisati novi klass (naravno abstraktni) sa imenom "Vozilo"
abstract class Vozilo
{
    // imati jedan atribut sa imenom "boja"
    public string boja;
    
    // imati konstruktor koji definise ovaj atribut (kroz argumenti)
    public Vozilo(string boja) {
        this.boja = boja;
    }
    
    // imati jedan bio koji abstraktni metodu
    public abstract void Break();
}

// 2) Stvarati novi bio koji interfejs
interface ISomeInterface
{
    // objaviti metod koji vrati bool i ima u argumentu string
    public bool IsValidRegistar(string registar);
    
    // objaviti metodu koji nista ne vrati i nema argumenta
    public void PrintPrimeNumbers();
}

// 3) uraditi novu bio koji klasu koji nasleduje "Vozilo" (npr. class BMV : Vozili, ICustomInterface)
class BMV : Vozilo, ISomeInterface
{
    // dodati dva nova atributa
    public string type;
    public int yearRealese;

    // objaviti ovaj atributi u konstruktoru
    public BMV(string type, int yearRealese, string boja) : base(boja)
    {
        this.type = type;
        this.yearRealese = yearRealese;
    }
    
    // Abstraktna metoda u Vozilo
    public override void Break() {
        Console.WriteLine("BMW is broken");
    }
    
    // realizovati interfejs koji vi ste napravili u proslom zadatku
    
    // prvi metod interfejsa (koji vrati bool i argument je string): argument je registar vozila (npr. "su-00a-re". Vrati  true ako prvo deo (su) je 2, drugo deo (00a) je 3 i treci deo (re) je 2 karaktera. Ako nije tako, to false
    public bool IsValidRegistar(string registar) {
        string[] registarParts = registar.Split('-');

        if (registarParts.Length != 3) // Mora sardzati 3 dela
            return false;
        if (registarParts[0].Length != 2) // Prvo deo je 2 karaktera
            return false;
        if (registarParts[1].Length != 3) // Drugo deo je 3 karaktera
            return false;
        if (registarParts[2].Length != 2) // Trece deo je 2 karaktera
            return false;
    
        // Ako proslo validaciju, to uspešno
        return true;
    }

    // drugi metod iz interfejsa ispisuje prvi 15 prosti brojeva u obrnutom redosledu
    public void PrintPrimeNumbers()
    {
        // List sa prostimi brojevami
        List<int> primeNumbers = new List<int>();
        
        // Traziti svi brojeva. Poceti sa 2 i dalece ++. I tako do toga kada cemo imati 15 brojeva
        for (int num = 2; primeNumbers.Count() != 15; num++)
        {
            // Provera da li prosti broj. Na pocetku je DA
            bool isPrime = true;
            
            // Pokusavamo podeliti sa bio koj brojem od 2 i manje od num
            // npr. Ako je num = 5, to cemo proveravati delenje sa 2, 3, 4
            for (int divideNum = 2; divideNum < num; divideNum++)
            {
                // Ako delenje je uspesno bez ostatka, to nije prime broj
                if (num % divideNum == 0) {
                    isPrime = false;
                    break;
                }
            }
            
            // Ako posle provere broj je prosti, dodajemo u list
            if (isPrime)
                primeNumbers.Add(num);
        }
        
        // U obrnutom redosledu
        primeNumbers.Reverse();
        
        // Ispisati svi prosti brojeva u obrnutom redosledu
        Console.WriteLine(String.Join(", ", primeNumbers));
    }
    
    // Dodati ToString() koji ispisuje svi atributi u klase
    public override string ToString()
    {
        return $"BMW {type} and {yearRealese} realese year with {boja} color.";
    }
}

// 4) uraditi novi klasu koji naslediva klas od proslog zadatka (npr. BMVAqua2018 : BMV)
class BMVAqua2018 : BMV
{
    // dodati jos jedan novi atribut
    public string ownerAuto;

    public BMVAqua2018() : base("Aqua", 2018, "#00f") {
        ownerAuto = "Unknown";
    }
    
    // uraditi novi konstruktor sa novi atributom
    public BMVAqua2018(string owner) : base("Aqua", 2018, "#00f") {
        ownerAuto = owner;
    }
    
    //  Dodati svoj ToString() koji ispisuje sve atributi u ovoj klase
    public override string ToString() {
        return $"{base.ToString()} Owner is {ownerAuto}";
    }
}

// 5) U glavni programe:
class Program
{
    static void Main(string[] args)
    {
        // stvarati novi objekat iz klasa u prethodnom zadatku sa konstruktorom bez parametra
        BMVAqua2018 bmv = new BMVAqua2018();
        
        //  ispisati ToString() za ovaj objekat
        Console.WriteLine(bmv.ToString());
    }
}