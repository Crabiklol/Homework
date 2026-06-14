using System;


public class Box<T>
{
 
    private T _value;

   
    public void SetValue(T value)
    {
        _value = value;
    }

   
    public T GetValue()
    {
        return _value;
    }
}


public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    
    public override string ToString()
    {
        return $"[Имя: {Name}, Возраст: {Age}]";
    }
}

public class Program
{
    public static void Main()
    {
        Console.WriteLine("--- Тестирование обобщённого класса Box<T> ---\n");

       
        Box<int> intBox = new Box<int>();
        intBox.SetValue(42);
        Console.WriteLine($"Box<int>: {intBox.GetValue()}");

       
        Box<string> stringBox = new Box<string>();
        stringBox.SetValue("Привет, обобщения!");
        Console.WriteLine($"Box<string>: {stringBox.GetValue()}");

        
        Box<Person> personBox = new Box<Person>();
        personBox.SetValue(new Person("Алексей", 28));
        Console.WriteLine($"Box<Person>: {personBox.GetValue()}");

        Console.WriteLine("\nВсе тесты прошли успешно!");
    }
}
