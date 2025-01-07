using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;

namespace justfun
{

    enum Logtype
    {
        Error,
        Warning,
        Information,
    }

    class FormInvalidException : Exception
    {
        public FormInvalidException(string message) : base(message) { }
    }

    public partial class MainWindow : Window
    {
        List<Student> students = new List<Student>();
        const int indexSize = 8;
        string saveFile = "";

        public MainWindow()
        {
            // Save file for data
            string folderPath = System.IO.Path.Combine(Directory.GetCurrentDirectory(), "Files");
            Directory.CreateDirectory(folderPath);
            saveFile = System.IO.Path.Combine(folderPath, "data.txt");

            InitializeComponent();
            listStudents.ItemsSource = students;

            LoadData();
        }
        

        private void SaveData()
        {
            List<string> saveLines = new List<string>();
            foreach(Student student in students)
            {
                saveLines.Add(student.SaveDataLine());
            }
            File.WriteAllLines(saveFile, saveLines);
        }
        private void LoadData()
        {
            if(File.Exists(saveFile)) {
                string[] lines = File.ReadAllLines(saveFile);

                foreach(string line in lines)
                {
                    students.Add(Student.LoadDataLine(line));
                }
                listStudents.Items.Refresh();
            }
        }
        
        private bool ValidData()
        {
            string name = NameInput.Text;
            string index = IndexInput.Text;

            int grade = 0;
            string comment = CommentInput.Text;

            try
            {
                grade = int.Parse(GradeInput.Text);
                if(grade < 0)
                {
                    IndexInput.Text = "0";
                    WriteLog("Grade is lower than 0. Minimum is 0", Logtype.Warning);
                }
                if (grade > 100)
                {
                    GradeInput.Text = "100";
                    WriteLog("Grade is higher than 100. Maximum is 100", Logtype.Warning);
                }
            }
            catch(FormatException ex)
            {
                throw new FormInvalidException("Grade has wrong format");
            }
            catch(OverflowException ex)
            {
                throw new FormInvalidException("Grade is overflow");
            }

            if (index.Length != indexSize)
                throw new FormInvalidException("Index with wrong size");

            if(students.Where(s => s.Index == index).Count() > 0)
                throw new FormInvalidException("Students with this index exist");

            if (!int.TryParse(index, out _))
                throw new FormInvalidException("Index is not number");

            if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(index))
                throw new FormInvalidException("Some field is empty");
            
            return true;
        }
        private void ClearTextBoxes()
        {
            NameInput.Clear();
            IndexInput.Clear();
            GradeInput.Clear();
            CommentInput.Clear();
        }

        private void WriteLog(string content, Logtype type = Logtype.Information)
        {
            LogViewerText.Text += $"> {type}: {content}\n";
        }

        private void AddStudent_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                ValidData();
                
            }
            catch(FormInvalidException ex)
            {
                MessageBox.Show($"Form is not valid. {ex.Message}", "Form Invalid");
                return;
            }

            string name = NameInput.Text;
            string index = IndexInput.Text;

            int grade = int.Parse(GradeInput.Text);
            string comment = CommentInput.Text;

            students.Add(new Student(name, index, grade, comment));
            listStudents.Items.Refresh();
            WriteLog($"Student \"{name}\" is added successful");
            SaveData();
            ClearTextBoxes();
        }
        private void Reset_Click(object sender, RoutedEventArgs e)
        {
            MessageBoxResult res = MessageBox.Show("Are you sure that you want to delete all data from eref?", "Alert", MessageBoxButton.YesNo, MessageBoxImage.Question);
            if (res == MessageBoxResult.Yes)
            {
                ClearTextBoxes();

                WriteLog("All data was removed", Logtype.Warning);
                students.Clear();

                listStudents.Items.Refresh();
                SaveData();
            }
        }

        private void Remove_Click(object sender, RoutedEventArgs e)
        {
            if (listStudents.SelectedItem is Student student)
            {
                WriteLog($"Student \"{student.Name}\" is removed");
                students.Remove(student);
                listStudents.Items.Refresh();
                SaveData();
            }
            else
            {
                MessageBox.Show("User is not selected");
                return;
            }
            
        }

        private void Average_Click(object sender, RoutedEventArgs e)
        {
            if(students.Count == 0)
            {
                MessageBox.Show("No students");
                return;
            }
            double average = students.Average(r => r.Grade);
            WriteLog($"Average grade is {average}");
        }
    }
}
