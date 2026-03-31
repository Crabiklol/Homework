using System;


interface IConverter
{
    decimal Convert(decimal value);
}


class LengthConverter : IConverter
{
    public decimal Convert(decimal value)
    {
        //  из метров в сантиметры
        return value * 100;
    }
}


class WeightConverter : IConverter
{
    public decimal Convert(decimal value)
    {
        // из килограммов в граммы
        return value * 1000;
    }
}


class TemperatureConverter : IConverter
{
    public decimal Convert(decimal value)
    {
        // Формула: (°C * 9/5) + 32
        return (value * 9 / 5) + 32;
    }
}

class Program
{
    static void Main()
    {
       
        IConverter lengthConverter = new LengthConverter();
        IConverter weightConverter = new WeightConverter();
        IConverter tempConverter = new TemperatureConverter();

        decimal meters = 2;
        decimal kilos = 5;
        decimal celsius = 25;

        
        Console.WriteLine($"Длина: {meters} м = {lengthConverter.Convert(meters)} см");
        Console.WriteLine($"Вес: {kilos} кг = {weightConverter.Convert(kilos)} г");
        Console.WriteLine($"Температура: {celsius} °C = {tempConverter.Convert(celsius)} °F");
    }
}
