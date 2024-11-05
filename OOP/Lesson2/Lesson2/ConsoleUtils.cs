namespace Utils;

public static class ConsoleUtils
{
    public static void WriteLineColor(string text, ConsoleColor color)
    {
        ConsoleColor temp = Console.ForegroundColor;
        Console.ForegroundColor = color;
        Console.WriteLine(text);
        Console.ForegroundColor = temp;
    }

    public static void Divider()
    {
        Console.WriteLine();
        WriteLineColor("====================================================", ConsoleColor.DarkBlue);
        Console.WriteLine();
    }
}