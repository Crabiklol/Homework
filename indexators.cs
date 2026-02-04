//1
public class ToDoList
{

    private string[] tasks = new string[5];

    
    public string this[int index]
    {
        get
        {
            
            if (index < 0 || index >= tasks.Length)
            {
                return "Задача не найдена";
            }
            return tasks[index];
        }
        set
        {
           
            if (index < 0 || index >= tasks.Length)
            {
                
                return;
            }
            tasks[index] = value;

        }
    }
}
//2
using System;

public class WeatherJournal
{
    private double[] temperatures = new double[7];

    public double this[int day]
    {
        get
        {
            if (day < 0 || day >= temperatures.Length)
                return 0.0;
            return temperatures[day];
        }
        set
        {
            if (day >= 0 && day < temperatures.Length)
            {
                if (value < -50.0 || value > 50.0)
                    temperatures[day] = 0.0;
                else
                    temperatures[day] = value;
            }
        }
    }

    public void PrintAllTemperatures()
    {
        Console.WriteLine("Температуры за неделю:");
        for (int i = 0; i < temperatures.Length; i++)
        {
            Console.WriteLine($"День {i + 1}: {temperatures[i]:F1}°C");
        }
    }
}

class Program
{
    static void Main()
    {
        WeatherJournal journal = new WeatherJournal();

       
        journal[0] = 23.5;
        journal[1] = 18.2;
        journal[2] = 25.0;
        journal[3] = 30.1;
        journal[4] = 27.8;
        journal[5] = 22.4;
        journal[6] = 19.6;

       
        journal[3] = 60.0;  
        journal[4] = -55.0; 

       
        Console.WriteLine($"Температура в день 1: {journal[0]:F1}°C");
        Console.WriteLine($"Температура в день 4: {journal[3]:F1}°C");
        Console.WriteLine($"Температура в день 5: {journal[4]:F1}°C");

       
        journal.PrintAllTemperatures();

        
        Console.WriteLine($"Температура в день 8: {journal[7]:F1}°C");
    }
}
