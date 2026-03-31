using System;

static class MathUtils
{
    public static bool IsEven(int n)
    {
        return n % 2 == 0;
    }

    public static long Factorial(int n)
    {
        long result = 1;
        for (int i = 1; i <= n; i++)
        {
            result = result * i;
        }
        return result;
    }

    public static double Power(double a, int b)
    {
        double result = 1;
        for (int i = 0; i < b; i++)
        {
            result = result * a;
        }
        return result;
    }

    public static int Clamp(int value, int min, int max)
    {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Чётное число 4: " + MathUtils.IsEven(4));
        Console.WriteLine("Факториал 5: " + MathUtils.Factorial(5));
        Console.WriteLine("2 в степени 3: " + MathUtils.Power(2, 3));
        Console.WriteLine("Ограничение 10 в диапазоне 0-5: " + MathUtils.Clamp(10, 0, 5));
    }
}
