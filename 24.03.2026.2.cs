using System;

class Student
{
    public string name;
    public int age;
    static int count = 0;

    public Student(string name, int age)
    {
        this.name = name;
        this.age = age;
        count++;
    }

    public static int GetStudentCount()
    {
        return count;
    }

    public void PrintInfo()
    {
        Console.WriteLine($"Имя: {name}, возраст: {age}");
    }
}

class Program
{
    static void Main()
    {
        Student s1 = new Student("Вася", 18);
        Student s2 = new Student("Катя", 20);

        s1.PrintInfo();
        s2.PrintInfo();

        Console.WriteLine("Всего студентов: " + Student.GetStudentCount());
    }
}
