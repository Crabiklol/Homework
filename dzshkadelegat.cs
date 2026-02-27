using System;

namespace CalculatorApp
{
    
    delegate double MathOperation(double a, double b);

    internal class Program
    {
       
        public static double Add(double a, double b)
        {
            return a + b;
        }

       
        public static double Subtract(double a, double b)
        {
            return a - b;
        }

        
        public static double Multiply(double a, double b)
        {
            return a * b;
        }

       
        public static double Divide(double a, double b)
        {
            if (b == 0)
            {
                throw new DivideByZeroException("Деление на ноль невозможно!");
            }
            return a / b;
        }

       
        public static void Calculator(double x, double y, MathOperation operation)
        {
            try
            {
                double result = operation(x, y);
                Console.WriteLine($"Результат: {result}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        public static void Main(string[] args)
        {
            double num1 = 10;
            double num2 = 5;

            
            Calculator(num1, num2, Add);        
            Calculator(num1, num2, Subtract);   
            Calculator(num1, num2, Multiply);    
            Calculator(num1, num2, Divide);     

            
            Calculator(num1, 0, Divide);
        }
    }
}
