//zadanie 1
using System;
using TextTools;

namespace TextTools
{
    public static class TextAnalyzer
    {
        
        public static string ToUpperCase(string text)
        {
            if (text == null) return null;
            return text.ToUpper();
        }

       
        public static int GetLength(string text)
        {
            if (text == null) return 0;
            return text.Length;
        }

        
        public static bool ContainsWord(string text, string word)
        {
            if (text == null || word == null) return false;
            return text.IndexOf(word, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}


class Program
{
    static void Main()
    {
        string sampleText = "Привет, мир! Это пример текста.";
        string searchWord = "пример";

        Console.WriteLine("Исходный текст: " + sampleText);
        Console.WriteLine("В верхнем регистре: " + TextAnalyzer.ToUpperCase(sampleText));
        Console.WriteLine("Длина строки: " + TextAnalyzer.GetLength(sampleText));
        Console.WriteLine($"Слово '{searchWord}' есть в тексте: " + TextAnalyzer.ContainsWord(sampleText, searchWord));
    }
}

//zadanie 2
using MathOperations;
using System;

namespace MathOperations
{
    public class Calculator
    {
        
        public int Add(int a, int b) => a + b;

        
        public int Subtract(int a, int b) => a - b;

        
        public int Multiply(int a, int b) => a * b;

        
        public double Divide(int a, int b)
        {
            if (b == 0)
                throw new DivideByZeroException("Деление на ноль недопустимо.");
            return (double)a / b;
        }
    }
}


class Program
{
    static void Main()
    {
        Calculator calc = new Calculator();

        int x = 10, y = 5;

        Console.WriteLine($"Сложение ({x} + {y}): {calc.Add(x, y)}");
        Console.WriteLine($"Вычитание ({x} - {y}): {calc.Subtract(x, y)}");
        Console.WriteLine($"Умножение ({x} * {y}): {calc.Multiply(x, y)}");

        try
        {
            Console.WriteLine($"Деление ({x} / {y}): {calc.Divide(x, y)}");
            Console.WriteLine($"Деление ({x} / 0): {calc.Divide(x, 0)}"); 
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine("Ошибка: " + ex.Message);
        }
    }
}

//zadanie 3
using School;
using System;

namespace School
{
    public class Student
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public Student(string name, int age)
        {
            Name = name;
            Age = age;
        }

        
        public void PrintInfo()
        {
            Console.WriteLine($"Студент: {Name}, Возраст: {Age}");
        }
    }

    public class Teacher
    {
        public string Name { get; set; }
        public string Subject { get; set; }

        public Teacher(string name, string subject)
        {
            Name = name;
            Subject = subject;
        }

        
        public void PrintInfo()
        {
            Console.WriteLine($"Преподаватель: {Name}, Предмет: {Subject}");
        }
    }
}



class Program
{
    static void Main()
    {
        
        Student student = new Student("Анна", 20);
        Teacher teacher = new Teacher("Иван Петров", "Математика");


        student.PrintInfo();
        teacher.PrintInfo();
    }
}
