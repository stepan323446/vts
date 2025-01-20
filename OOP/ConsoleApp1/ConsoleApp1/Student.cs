namespace ConsoleApp1;

abstract class Vegetables
{
    public string Color { get; set; }
    protected abstract void SomeMethod();

    public Vegetables(string color)
    {
        Color = color;
    }
}

interface ISome
{
    public string GetData();
    public void Eat();
}
class Tomato<T> : Vegetables, ISome
{
    public T Data { get; set; }
    protected override void SomeMethod() { }

    public Tomato(string color, T wtf) : base(color)
    {
        Data = wtf;
    }
    public string GetData()
    {
        return $"This is tomato. {Color}";
    }

    public void Eat()
    {
        throw new NotImplementedException();
    }
}

