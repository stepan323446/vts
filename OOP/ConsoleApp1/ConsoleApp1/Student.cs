namespace ConsoleApp1;

public class MyNumber
{
    public int Number { get; set; }

    public MyNumber(string number)
    {
        Number = int.Parse(number);
    }
    public MyNumber(int number)
    {
        Number = number;
    }
}

public class Car
{
    static Car()
    {
        
    }
    
}

public class A { }

public class B : A { }

public class C : B { }
public class D : C { }