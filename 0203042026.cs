using System;


public class Employee
{
   
    public string Name { get; set; }

    public Employee(string name)
    {
        Name = name;
    }

    
    public virtual double CalculateSalary()
    {
        return 0; 
    }
}


public class Teacher : Employee
{
    
    public double Rate { get; set; }
    public double Bonus { get; set; }

    public Teacher(string name, double rate, double bonus) : base(name)
    {
        Rate = rate;
        Bonus = bonus;
    }

    
    public override double CalculateSalary()
    {
        return Rate + Bonus;
    }
}


public class Administrator : Employee
{
    
    public double FixedSalary { get; set; }

    public Administrator(string name, double fixedSalary) : base(name)
    {
        FixedSalary = fixedSalary;
    }

    
    public override double CalculateSalary()
    {
        return FixedSalary;
    }
}

public class Program
{
    public static void Main()
    {
        
        Employee[] employees = new Employee[]
        {
            new Teacher("Иван Петров", 40000, 10000),    
            new Administrator("Мария Сидорова", 65000),     
            new Teacher("Алексей Смирнов", 45000, 5000)    
        };

        Console.WriteLine("--- Расчёт зарплат сотрудников ---\n");

        
        foreach (Employee emp in employees)
        {
            
            Console.WriteLine($"Сотрудник: {emp.Name,-20} | Зарплата: {emp.CalculateSalary(),8} руб.");
        }
    }
}
