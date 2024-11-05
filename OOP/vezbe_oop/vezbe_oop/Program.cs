using System;
using System.IO;
using System.Linq;

namespace MyApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
             *          VEŽBA 31.10.2024.
             *          Zadatak 1
             */
            
            /*
             *          Zadatak 1
             *          Sadržaj data1.txt fajla prekopirati u string.
             */

            string path = @"/home/steve-dekart/Documents/vts/#files/oop_31102024/data1.txt";
            string fileContent1 = File.ReadAllText(path);
            
            // Izbrojte koliko puta se slovo 'i' (malo slovo) pojavljuje u tekstu. 
            int counterWordI = fileContent1.Count(c => c == 'i');
            PrintAnswer(
                "data1.txt", 
                1, 
                "Izbrojte koliko puta se slovo 'i' (malo slovo) pojavljuje u tekstu.", 
                counterWordI.ToString());
            
            // Izbrojte koliko puta se malo i veliko slovo 'c'  (ukupno) pojavljuje u tekstu. 
            int counterWordC = fileContent1.Count(c => c == 'c' || c == 'C');
            PrintAnswer(
                "data1.txt", 
                1, 
                "Izbrojte koliko puta se malo i veliko slovo 'c'  (ukupno) pojavljuje u tekstu.", 
                counterWordC.ToString());
            
            /*
             *          Zadatak 2, Zadatak 3
             *          Ispišite tekst iz tačke 1 velikim slovima!
             */
            PrintAnswer(
                "data1.txt",
                2,
                "Ispišite tekst iz tačke 1 velikim slovima!",
                fileContent1.ToUpper());
            
            /*
            *          Zadatak 4
            *          Sadržaj data2.txt fajla prekopirajte u novi string. Taj string dodajte tekstu iz prethodnog zadatka (sabrati dva stringa). Ispišite kompletan (spojen) tekst i odredite njegovu dužinu! 
            */
            path = @"/home/steve-dekart/Documents/vts/#files/oop_31102024/data2.txt";
            string fileContent2 = File.ReadAllText(path) + fileContent1;
            int fileContent2Length = fileContent2.Length;
            PrintAnswer(
                "data2.txt",
                4,
                "Sadržaj data2.txt fajla prekopirajte u novi string. Taj string dodajte tekstu iz prethodnog zadatka (sabrati dva stringa). Ispišite kompletan (spojen) tekst i odredite njegovu dužinu! ",
                $"{fileContent2}\n\nText Length: {fileContent2Length}");
            
            /*
             *          Zadatak 5
             *          Na kojim lokacijama (na kom indexu) se u tekstu nalazi reč “the” ! 
             */
            List<int> indexesWordTHE = new List<int>();
            int indexStartTHE = 0;
            int indexTHE = -1;
            do
            {
                indexTHE = fileContent2.IndexOf("the", indexStartTHE);
                if (indexTHE != -1)
                {
                    indexesWordTHE.Add(indexTHE);
                    indexStartTHE = indexTHE + 1;
                }
                
            } while (indexTHE != -1);
            PrintAnswer(
                "data2.txt",
                5,
                "Na kojim lokacijama (na kom indexu) se u tekstu nalazi reč “the”",
                string.Join(", ", indexesWordTHE));

            /*
             *          Zadatak 6
             *          Kreirajte novi niz koji sadrži prvih 20 karaktera iz predhodnog teksta. Ispišite sadržaj niza
             */
            char[] first20Chars = fileContent2.Substring(0, 20).ToCharArray();
            PrintAnswer(
                "data2.txt",
                6,
                "Kreirajte novi niz koji sadrži prvih 20 karaktera iz predhodnog teksta. Ispišite sadržaj niza”",
                string.Join(", ", first20Chars));
            
            /*
             *          Zadatak 7
             *          Dat je niz koji sadrži sledeće elemente str1= {"jun", "jul", "maj", "avg", "sep"}.Prebacite ga u listu i: 
               	ispišite sadržaj liste u obrnutom redosledu
               	sortirajte listu 
               	ispišite sadržaj liste.
               
             */
            string[] str1 = new string[] {"jun", "jul", "maj", "avg", "sep"};
            List<string> str1List = new List<string>(str1);
            str1List.Reverse();
            PrintAnswer(
                "data2.txt",
                7,
                "ispišite sadržaj liste u obrnutom redosledu",
                string.Join(", ", str1List));
            str1List.Sort();
            PrintAnswer(
                "data2.txt",
                7,
                "sortirajte listu, ispišite sadržaj liste.",
                string.Join(", ", str1List));
            
            /*
             *          Zadatak 8
             *           Popunite dve liste sa po 5 prirodnih broja iz opsega [10,20] (i 10 i 20 su deo opsega)
               Ispisati sadržaj ove dve liste, kao i njihovu uniju (unija ne sadrži duplikate vrednosti).
             */
            List<int> intList1 = new List<int>();
            List<int> intList2 = new List<int>();
            Random rand = new Random();
            for (int i = 0; i < 5; i++)
            {
                intList1.Add(rand.Next(10, 20));
                intList2.Add(rand.Next(10, 20));
            }
            List<int> intUnionList = new List<int>();
            intUnionList.AddRange(intList1);
            intUnionList.AddRange(intList2);
            PrintAnswer(
                "data2.txt",
                8,
                "Popunite dve liste sa po 5 prirodnih broja iz opsega [10,20] (i 10 i 20 su deo opsega)\n Ispisati sadržaj ove dve liste, kao i njihovu uniju (unija ne sadrži duplikate vrednosti).",
                $"{string.Join(", ", intList1)}\n" +
                $"{string.Join(", ", intList2)}\n" +
                $"{string.Join(", ", intUnionList.Distinct())}");
            
            /*
            *          Zadatak data3.txt
            *         Uz ovaj dokumenat ste dobili tekstualnu bazu podataka (data3.txt). Nazivi kolona su dati sledećom tabelom:
               
            */
            path = @"/home/steve-dekart/Documents/vts/#files/oop_31102024/data3.txt";
            Car[] data3Arr = File.ReadAllLines(path)
                .Select(line => line.Split(" - "))
                .ToArray()
                .Select(dataArr => new Car(dataArr[0], int.Parse(dataArr[1]), int.Parse(dataArr[2]), int.Parse(dataArr[3])))
                .ToArray();
            
            /*
            *          2 .Ispisati one zapise gde je prodajna cena za 10% veća od nabavne cene!
             *          Prodajna - 12428 - 100%
             *          Nabavna - 10997 - ?
             * 
            */
            Car[] selected10PCars = data3Arr.Where(car => 100f - (float)car.BuyPrice * 100 / (float)car.SellPrice >= 10).ToArray();

            PrintAnswer(
                "data3.txt",
                2,
                "Ispisati one zapise gde je prodajna cena za 10% veća od nabavne cene!",
                string.Join("\n", selected10PCars.Select(car => car.ToString()))
                );
            
            /*
            *          3.	Ispisati one zapise gde je tip vozila BMW a godina proizvodnje je iz intervala  od 2010 do 2015 godine. 
               
             * 
            */
            Car[] selectedBMW = data3Arr
                .Where(car => car.Name == "BMW" && car.RealeseYear >= 2010 && car.RealeseYear <= 2015)
                .ToArray();

            PrintAnswer(
                "data3.txt",
                3,
                "Ispisati one zapise gde je tip vozila BMW a godina proizvodnje je iz intervala  od 2010 do 2015 godine.",
                string.Join("\n", selectedBMW.Select(car => car.ToString()))
            );
            
            /*
            *    4.	Ispisati broj vozila za sve tipove (koliko audija, koliko bmw-a itd.) 
               
            */
            Dictionary<string, int> counterCarType = new Dictionary<string, int>();
            foreach (Car car in data3Arr)
            {
                if (counterCarType.ContainsKey(car.Name))
                    counterCarType[car.Name]++;
                else
                    counterCarType.Add(car.Name, 1);
            }
            
            PrintAnswer(
                "data3.txt",
                4,
                "Ispisati broj vozila za sve tipove (koliko audija, koliko bmw-a itd.) ",
                string.Join("\n", counterCarType.Select(car => $"[{car.Key}] {car.Value}]"))
            );
        }

        static void PrintAnswer(string filename, int num, string question, string answer)
        {
            ConsoleColor defaultColor = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine($"[{filename}][{num}]: {question}");
            Console.ForegroundColor = defaultColor;
            Console.WriteLine($">> {answer}");
            Console.WriteLine();
        }
    }
}