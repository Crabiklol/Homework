//1
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class Student
{
    
    public string Name { get; }

    
    public int Age { get; set; }

   
    private double gpa;
    public double GPA
    {
        get { return gpa; }
        set
        {
            if (value < 0.0 || value > 4.0)
            {
                throw new ArgumentOutOfRangeException(nameof(value), "Значения от 0.0 до 4.0 !");
            }
            gpa = value;
        }
    }

    
    public Student(string name, int age, double gpa)
    {
        Name = name;
        Age = age;
        GPA = gpa; // установка через свойство с проверкой
    }
}


//2
using System;

public class BankAccount
{
    public string AccountNumber { get; }

    
    public decimal Balance { get; private set; }


    public string OwnerName { get; set; }

  
    public BankAccount(string accountNumber, string ownerName, decimal initialBalance = 0)
    {
        if (string.IsNullOrWhiteSpace(accountNumber))
            throw new ArgumentException("Номер счета не может быть пустым", nameof(accountNumber));

        AccountNumber = accountNumber;
        OwnerName = ownerName;
        Balance = initialBalance;
    }


    public void Deposit(decimal amount)
    {
        if (amount < 0)
            throw new ArgumentOutOfRangeException(nameof(amount), "Сумма пополнения должна быть неотрицательной.");

        Balance += amount;
    }
    public void Withdraw(decimal amount)
    {
        if (amount < 0)
            throw new ArgumentOutOfRangeException(nameof(amount), "Сумма снятия должна быть неотрицательной.");

        if (amount > Balance)
            throw new InvalidOperationException("Недостаточно средств на счету.");

        Balance -= amount;
    }
}
