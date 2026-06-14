using System;
using System.Collections.Generic;


public class Calculator
{
    
    public event Action<string> OnResult;

    
    public double Calculate(double a, double b, Func<double, double, double> operation)
    {
        
        double result = operation(a, b);

        
        string message = $"Операция над {a} и {b}, Результат: {result}";
        OnResult?.Invoke(message);

        return result;
    }
}

public class Program
{
    public static void Main()
    {
        
        Calculator calculator = new Calculator();

        
        List<string> history = new List<string>();

        
        calculator.OnResult += (msg) => history.Add($"{DateTime.Now:HH:mm:ss} | {msg}");

        Console.WriteLine("--- Выполнение вычислений ---\n");

        

        
        double sum = calculator.Calculate(15, 5, (x, y) => x + y);
        Console.WriteLine($"15 + 5 = {sum}");

        
        double difference = calculator.Calculate(15, 5, (x, y) => x - y);
        Console.WriteLine($"15 - 5 = {difference}");

        
        double power = calculator.Calculate(2, 3, (x, y) => Math.Pow(x, y));
        Console.WriteLine($"2 ^ 3 = {power}");

        
        Console.WriteLine("\n--- История операций (Лог) ---");
        if (history.Count == 0)
        {
            Console.WriteLine("История пуста.");
        }
        else
        {
            foreach (string logEntry in history)
            {
                Console.WriteLine(logEntry);
            }
        }
    }
}
