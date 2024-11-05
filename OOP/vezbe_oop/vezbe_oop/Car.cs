using System.Collections;

namespace MyApp;

public class Car : IEnumerable<string>
{
    public string Name { get; set; }
    public int BuyPrice { get; set; }
    public int SellPrice { get; set; }
    public int RealeseYear { get; set; }

    public Car(string name, int buyPrice, int sellPrice, int realeseYear)
    {
        Name = name;
        BuyPrice = buyPrice;
        SellPrice = sellPrice;
        RealeseYear = realeseYear;
    }


    public IEnumerator<string> GetEnumerator()
    {
        throw new NotImplementedException();
    }

    public override string ToString()
    {
        return "Name: " + Name + " BuyPrice: " + BuyPrice + " SellPrice: " + SellPrice;
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}