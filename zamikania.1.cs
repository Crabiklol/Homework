using System;

class Program
{
    
    public delegate decimal CheckCalculator(decimal price);

    
    public static CheckCalculator CreateCalculator(decimal discountPercent)
    {
      
        return delegate (decimal price)
        {
            return price * (1 - discountPercent / 100);
        };
    }

    static void Main()
    {
 
        CheckCalculator beginnerCalculator = CreateCalculator(5);
       
        CheckCalculator vipCalculator = CreateCalculator(20);

        decimal price = 1000;


        Console.WriteLine($"Цена для новичка: {beginnerCalculator(price)}");
        Console.WriteLine($"Цена для VIP: {vipCalculator(price)}");
    }
}
