using System.Data.SqlClient;
namespace SQLConnectionLesson;

class Program
{
    static void Main(string[] args)
    {
        string server = "localhost";
        string database = "softing";
        string username = "root";
        string password = "root";

        string connectionString = $"SERVER={server};DATABASE={database};UID={username};PASSWORD={password};";

        SqlConnection conn = new SqlConnection(connectionString);
        conn.Open();
        
        SqlCommand cmd = new SqlCommand("SELECT title, author FROM `books`", conn);
        SqlDataReader reader = cmd.ExecuteReader();
        while (reader.Read())
        {
            Console.WriteLine("{0},{1}", reader.GetString(0), reader.GetString(1));
        }
        reader.Close();
        
        conn.Close();
        
        Console.WriteLine("Hello, World!");
    }
}