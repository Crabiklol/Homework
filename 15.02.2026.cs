//zadanie1
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }


    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

   
    public void ShowInfo()
    {
        Console.WriteLine($"Имя: {Name}, Возраст: {Age}");
    }

   
    public void SayHello()
    {
        Console.WriteLine($"Привет! Меня зовут {Name}.");
    }
}

//zadanie 2-3
public class Student : Person
{
    public string University { get; set; }

  
    public Student(string name, int age, string university) 
        : base(name, age)
    {
        University = university;
    }

   
    public void Study()
    {
        Console.WriteLine($"{Name} учится в {University}.");
    }
}

public class Teacher : Person
{
    public string Subject { get; set; }

  
    public Teacher(string name, int age, string subject)
        : base(name, age)
    {
        Subject = subject;
    }

    
    public void Teach()
    {
        Console.WriteLine($"{Name} преподаёт {Subject}.");
    }
}

public class Doctor : Person
{
    public string Specialization { get; set; }

 
    public Doctor(string name, int age, string specialization)
        : base(name, age)
    {
        Specialization = specialization;
    }

   
    public void Treat()
    {
        Console.WriteLine($"{Name} лечит пациентов как {Specialization}.");
    }
}

//zadanie 4-5
using System;

class Program
{
    static void Main()
    {
        
        Student student = new Student("Алиса", 20, "МГУ");
        Teacher teacher = new Teacher("Борис", 45, "Математика");
        Doctor doctor = new Doctor("Виктор", 38, "Кардиолог");

       
        Console.WriteLine("=== Студент ===");
        student.ShowInfo();
        student.Study();
        student.SayHello();  

        Console.WriteLine("\n=== Преподаватель ===");
        teacher.ShowInfo();
        teacher.Teach();
        teacher.SayHello();  

        Console.WriteLine("\n=== Врач ===");
        doctor.ShowInfo();
        doctor.Treat();
        doctor.SayHello(); 
    }
}

