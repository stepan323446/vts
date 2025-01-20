# PITANJA ZA USMENI

*Code samo za primere. Ne treba pisati za odgovor na ispitu*

## Sadrzaj
* [1. Šta je cilj definisanja klase?](#1-šta-je-cilj-definisanja-klase)
* [2. Šta znate o konstruktoru?](#2-šta-znate-o-konstruktoru)
* [3. Kakvo nasleđivanje podržava C#?](#3-kakvo-nasleđivanje-podržava-c)
* [4. Koje nivoe pristupa možemo definisati atributu klase?](#4-koje-nivoe-pristupa-možemo-definisati-atributu-klase)
* [5. Koji elementi klase se ne nasleđuju?](#5-koji-elementi-klase-se-ne-nasleđuju)
* [6. Navedite dva razloga zbog kojih bi trebalo da se predefiniše metod koji je već implementiran u nadklasi!](#6-navedite-dva-razloga-zbog-kojih-bi-trebalo-da-se-predefiniše-metod-koji-je-već-implementiran-u-nadklasi)
* [7. Koje metode se ne mogu predefinisati u podklasi?](#7-koje-metode-se-ne-mogu-predefinisati-u-podklasi)
* [8. Koje metode se moraju predefinisati u podklasi?](#8-koje-metode-se-moraju-predefinisati-u-podklasi)
* [9. Koja je ključna reč za kreiranje klase koja se ne može koristiti u procesu nasleđivanja?](#9-koja-je-ključna-reč-za-kreiranje-klase-koja-se-ne-može-koristiti-u-procesu-nasleđivanja)
* [10. Objasnite pojam polimorfizma!](#10-objasnite-pojam-polimorfizma)
* [11. Objasnite pojam apstraktne klase!](#11-objasnite-pojam-apstraktne-klase)
* [12. Koje prednosti ima korišćenje interface-a?](#12-koje-prednosti-ima-korišćenje-interface-a)
* [13. Šta je izuzetak?](#13-šta-je-izuzetak)
* [14. Objasnite prednost korišćenja stilova u XAML fajlu!](#14-objasnite-prednost-korišćenja-stilova-u-xaml-fajlu)
* [15. Šta znate o Grid kontejneru?](#15-šta-znate-o-grid-kontejneru)
* [16. Šta znate o StackPanel kontejneru?](#16-šta-znate-o-stackpanel-kontejneru)

## **1. Šta je cilj definisanja klase?**

**Klasa** je korisnički definisan tip koji se sastoji od polja podataka (promenljivih) i članova koji rade sa ovim podacima (metode, svojstva).

Svrha definisanja klase je da grupisanjem podataka i povezanih funkcionalnosti u određenu klasu, možemo da modelujemo naš program prema objektima kao u stvarnom svetu.

```cs
class Student 
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Student(string name, string age) {
        Name = name;
        Age = age;
    }
    // Daleće nešto sa studentom...
}
```

## 2. Šta znate o konstruktoru?

**Konstruktor** je posebna metoda klase koja se implicitno poziva kada se objekat kreira pomoću ključne reči `new`. 

Za razliku od drugih metoda klase, konstruktor nema povratnu vrednost (čak ni `void`) i ima ime identično imenu klase.

```cs
class Student {
    // ....
    public Student(string name) {
        Name = name;
    }
    // ....
}
```
Kada se definiše klasa bez sopstvenog konstruktora, definiše se defoltni, koji nema nikakve parametre. Možemo ga redefinisati ako želimo. Takođe možemo da koristimo preopterećenje metoda za kreiranje više varijanti definicije klase.
```cs
class Student {
    // ....
    public Student(string name, int age) {
        Name = name;
        Age = age;
    }
    public Student(string name) {
        Name = name;
        Age = 18;
    }
    // ....
}
```

## 3. Kakvo nasleđivanje podržava C#?

C# i .NET podržavaju samo **Jednostruko nasleđivanje**. To znači da svaka klasa može da nasledi članove samo iz jedne klase. Ovo nam pomaže da primenimo hijerarhiju nasleđivanja.

```cs
public class GameObject {
    public int x;
    public int y;
    // ....
}
public class Entity : GameObject {
    public float speed;
    public float health;
    // ...
}
public class Player : Entity {
    // ...
}
```

## 4. Koje nivoe pristupa možemo definisati atributu klase?

Imamo nekoliko modifikatora pristupa za članove klase:

* **public** – elementi nemaju ograničenja. Javnom članu se može pristupiti iz objekta i iz bilo koje druge proizvoljne klase. Takođe dostupno za spoljne _sklopa (assembly)_.
* **private** – Elementi su dostupni samo klasi u kojoj su definisani
* **protected** – Elementi dostupni sopstvenim klasama i naslednicama sa definisanim pristupom.
* **internal** -  Elementi dostupni samo unutar trenutnog .NET _sklopa (assembly)._
* **protected internal** - Elementi unutar trenutnog _sklopa (.NET assembly)_ dostupni su kao public, dok su u drugim _sklopovima_ dostupni kao protected (preko nasleđivanja klase).
* **private protected** - Elementi su dostupni kao protected, ali isključivo unutar trenutnog _sklopa (.NET assembly)_.

> Sklop (.NET assembly) - To je druga aplikacija ili biblioteka napisana na .NET jeziku (uključujući C#). Na primer, Math.

```cs
/*
    Sklop `AccoundManager.dll` 
    ili projekat `AccountManager.sln`
*/
class Account {
    // Dostupno bio gde
    public string Username {get; set;}
    
    // Dostupno samo u ovom klasu
    private int password { get; set; }

    // Dostupno unutar trenutnog sklopa (.NET assembly)
    internal int AccountNumber { get; set; }

    // Dostupno u trenutnom sklopa kao public, a u drugim sklopa kao protected
    protected internal bool IsVerified { get; set; }

    // Dostupno kao protected, ali samo unutar trenutnog sklopa
    private protected DateTime LastLogin { get; set; }
}
```

## 5. Koji elementi klase se ne nasleđuju?

* **Statički konstruktori**, koji inicijalizuju statičke podatke u klasi
* **Konstruktori** koji su pozvani da kreiraju novu instancu klase
* Članovi klase sa modifikatorom pristupa **private**

## 6. Navedite dva razloga zbog kojih bi trebalo da se predefiniše metod koji je već implementiran u nadklasi!

* Da se ​​izbegne kopiranje istog koda metode kao u roditeljskoj klasi
* Možemo dodati funkcionalnost metodu u roditeljskoj klasi i ova promena treba da se odrazi na sve podređene klase

## 7. Koje metode se ne mogu predefinisati u podklasi?

* static;
* private;
* konstruktori
* metode koje nemaju `virtual`, `abstract` ili `override` modifikator.

## 8. Koje metode se moraju predefinisati u podklasi?

Samo apstraktne metode iz roditeljskih klasa za podređene klase.

```cs
// Ako class ima abstraktni metod, to class isto mora biti abstraktni
abstract class GameObject {
    // ...
    // Moramo napisati public, protected, ..., dabi nemati `private` zato sta private ne mozemo nasledivati
    public abstract string GetObjectName();
}
class Player : GameObject {
    public override string GetObjectName() {
        return "Player Object";
    }
}
```

> Ako se ovde podrazumeva i interfejs, onda moramo takođe implementirati sve članove iz interfejsa

## 9. Koja je ključna reč za kreiranje klase koja se ne može koristiti u procesu nasleđivanja?

`sealed`

```cs 
sealed class Player : GameObject { ... } 
```

## 10. Objasnite pojam polimorfizma!

**Polimorfizam** pruža podklasi način da definiše sopstvenu verziju metode, definisane u roditeljskoj klasi, primenom procesa koji se naziva preopterećenje metode. 

U jeziku C# za to koristimo ključne reči `override` (za podklase) i `virtual` (za baznu klasu).

```cs
class GameObject {
    public int x;
    public int y;
    public bool invincible = false;

    public virtual void Destroy() {
        this.x = 0;
        this.y = 0;
        this.invincible = true;
    }
}
class Enemy : GameObject {
    public string EnemyType;

    public override void Destroy() {
        base.Destroy(); // Zovemo metod iz GameObject

        Console.WriteLine($"Enemy {EnemyType} is died"); // Dodamo funkcionalnost
    }
}
```

## 11. Objasnite pojam apstraktne klase!

**Apstraktna** klasa je slična redovnoj klasi. Takođe može imati promenljive, metode, konstruktore, svojstva. Jedino što se pri definisanju apstraktnih klasa koristi ključna reč `abstract`.

```cs
abstract class GameObject { 
    public GameObject(int x, int y) { ... }
    // ...
}
```

Ali glavna razlika između apstraktnih klasa i redovnih klasa je u tome što NE MOŽEMO koristiti konstruktor apstraktne klase za kreiranje instance klase.
```cs
GameObject obj = new GameObject(2, 10); // Greska
```

Međutim, apstraktne klase su korisne za opisivanje neke uobičajene funkcionalnosti koju izvedene klase mogu naslediti i koristiti.
```cs
class Player : GameObject {
    // ...
    public Player(string name) : base(0, 0) {
        // ....
    }
}
```

## 12. Koje prednosti ima korišćenje interface-a?  

Interfejs je samo imenovani skup apstraktnih članova i nema sopstvenu implementaciju kao što to ima apstraktna klasa. Klasa može da implementira više interfejsa i na taj način podržava višestruka ponašanja.

Nakon implementacije interfejsa u klasu, možemo da komuniciramo sa objektom te klase preko interfejsa.
```cs
interface IClickable {
    public void Click();
}
class MyButton : UI, IClickable {
    public string Content { get; set; };

    public MyButton(string text) {
        Content = text;
    }

    // Iz IClickable
    public void Click() {
        Console.WriteLine($"Button is clicked")
    }
}
/*
 *  Negde u programe
 */
class VisualProgram {
    public void OnClick(object obj) {
        if(obj is IClickable iclickable) {
            obj.Click(); // Ako MyButton, bice 'Button is clicked'
        }
    }
}
```

## 13. Šta je izuzetak?

Izuzeci su kvarovi, netačan korisnički unos i greške tokom izvršavanja programa.

U C#, svi izuzeci su nasleđeni iz klase `System.Exception`, gde možemo dobiti poruku o grešci, izvor, broj reda u kodu itd.

C# vam takođe omogućava da uhvatite greške pomoću
```cs
try {
    // Some code
}
catch(ExceiptionClass ex) {
    // Code after error
}
```

## 14. Objasnite prednost korišćenja stilova u XAML fajlu!

**XAML (Extensible Application Markup Language)** opisuje korisnički interfejs u ​​programu za naknadni rad sa njim u kodu (kao HTML). 

XAML nije ograničen na .NET aplikacije i može se koristiti na drugim jezicima. Za C# XAML koristimo u WPF aplikacijama.

Pored toga, XAML olakšava prilagođavanje vizuelnog izgleda kontrola koristeći stilove i animacije.

## 15. Šta znate o Grid kontejneru?

Raspoređuje sadržaj unutar niza ćelija koje se održavaju unutar mreže tabele.

```xml
<Grid>
    <!-- Definisimo Grid tabelu sa 3 kolonami i 2 redami -->
    <Grid.ColumnDefinitions>
        <ColumnDefinition Width="150" />
        <ColumnDefinition Width="2*" />
        <ColumnDefinition Width="1*" />
    </Grid.ColumnDefinitions>
    <Grid.RowDefinitions>
        <RowDefinition Height="1*" />
        <RowDefinition Height="1*" />
    </Grid.RowDefinitions>

    <!-- Elementi u Grid -->
    <StackPanel Grid.Row="1" Grid.Column="2"> ... </StackPanel>
    ...
</Grid>
```

Možemo definisati veličinu ćelija koristeći svojstva `RowDefinition` i `RowDefinition` sa `Height` i `Width`. Možemo postaviti sopstvene veličine (100, 250) u pikselama ili relativne (1*, 3*).

Da bismo element priložili ćeliji, koristimo svojstva `Grid.Row` i `Grid.Column`, gde pišemo redni broj ćelije.

## 16. Šta znate o StackPanel kontejneru?

Sadržaj postavljamo vertikalno ili horizontalno, u zavisnosti od svojstva `Orientation`. Prilikom promene veličine StackPanela, sadržaj se ne omotava, već se rasteže unutar StackPanela.

```xml
<StackPanel Orientation="Vertical">
    <TextBlock Text="Hello world"/>
    <TextBlock Text="Hello world 2"/>
</StackPanel>
```