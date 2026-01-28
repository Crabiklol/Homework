using System;

public class Car
{
    // Поля класса
    private string brand;
    private string model;
    private int year;
    private double engineVolume;
    private bool isRunning;
    private int currentSpeed;

    // Конструктор с параметрами
    public Car(string brand, string model, int year, double engineVolume)
    {
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.engineVolume = engineVolume;
        isRunning = false;
        currentSpeed = 0;
    }

    // Методы
    public void StartEngine()
    {
        if (!isRunning)
        {
            isRunning = true;
            Console.WriteLine("Двигатель запущен!");
        }
    }

    public void StopEngine()
    {
        if (isRunning)
        {
            isRunning = false;
            Console.WriteLine("Двигатель остановлен!");
        }
    }

    public void Accelerate(int speed)
    {
        currentSpeed = speed;
        Console.WriteLine($"Текущая скорость: {currentSpeed} km/h");
    }

    // Метод для отображения информации
    public void DisplayInfo()
    {
        Console.WriteLine($"Brand: {brand}");
        Console.WriteLine($"Model: {model}");
        Console.WriteLine($"Year: {year}");
        Console.WriteLine($"Engine Volume: {engineVolume} L");
        Console.WriteLine($"Is Running: {isRunning}");
        if (currentSpeed > 0)
            Console.WriteLine($"Current Speed: {currentSpeed} km/h");
    }
}

class Program
{
    static void Main()
    {
        // Создаем три объекта
        Car car1 = new Car("Toyota", "Corolla", 2020, 1.8);
        Car car2 = new Car("BMW", "X5", 2019, 3.0);
        Car car3 = new Car("Ford", "Focus", 2021, 2.0);

        // Демонстрируем работу
        car1.StartEngine();
        car1.DisplayInfo();

        car2.StopEngine();
        car2.DisplayInfo();

        car3.Accelerate(50);
        car3.DisplayInfo();
    }
}
