namespace Social;

public interface IPerson
{
    public string name { get; set; }
    public string surname { get; set; }
    public string jmbg { get; set; } 
    public bool isAlive { get; set; }
}