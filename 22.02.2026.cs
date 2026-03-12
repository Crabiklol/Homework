//1
using System;

namespace DelegatesDemo
{
    
    public delegate void StringDelegate(string text);

    class Program
    {
        
        static void PrintToConsole(string text)
        {
            Console.WriteLine(text);
        }

        static void Main()
        {
            
            StringDelegate d = PrintToConsole;

            
            d("Кавабанга");
        }
    }
}

//2
using System;

namespace Task2_DelegateWithNumbers
{
    class Program
    {
        
        delegate int IntOperation(int a, int b);

        static int Add(int a, int b) => a + b;
        static int Multiply(int a, int b) => a * b;

        static void Main()
        {
            int x = 7, y = 4;

            IntOperation op;

            op = Add;
            Console.WriteLine($"Сложение: {op(x, y)}");

            op = Multiply;
            Console.WriteLine($"Умножение: {op(x, y)}");
        }
    }
}

//3
using System;

namespace LambdaExample
{
    
    public delegate void MessageDelegate(string text);

    class Program
    {
        static void Main(string[] args)
        {
            
            MessageDelegate messageDelegate = (text) =>
            {
                Console.WriteLine($"Сообщение: {text}");
            };

            
            messageDelegate("Привет, как дела?");

        }
    }
}

//4
using System;


public class Counter
{
    
    private int value;
    
   
    public event EventHandler ValueChanged;
    
    
    public Counter()
    {
        value = 0;
    }
    
   
    public int Value
    {
        get { return value; }
    }
    
    
    public void Increment()
    {
        value++; 
        OnValueChanged(); 
    }
    
   
    protected virtual void OnValueChanged()
    {
        
        ValueChanged?.Invoke(this, EventArgs.Empty);
    }
}

class Program
{
    static void Main()
    {
        
        Counter counter = new Counter();
        
        counter.ValueChanged += Counter_ValueChanged;
        
      
        Console.WriteLine("Начинаем увеличивать счетчик:");
        
        counter.Increment(); 
        counter.Increment(); 
        counter.Increment(); 
        counter.Increment(); 
        counter.Increment(); 
        
        Console.WriteLine($"\nИтоговое значение счетчика: {counter.Value}");
    }
    
    
    private static void Counter_ValueChanged(object sender, EventArgs e)
    {
        Console.WriteLine("Значение изменилось");
        
        
        Counter counter = sender as Counter;
        if (counter != null)
        {
            Console.WriteLine($"Текущее значение: {counter.Value}");
        }
    }
}

//5
using System;


class TaskRunner
{
    
    public event EventHandler TaskCompleted;

    
    public void RunTask()
    {
        Console.WriteLine("Задача выполняется...");
        
        
        OnTaskCompleted();
    }

    
    protected virtual void OnTaskCompleted()
    {
        TaskCompleted?.Invoke(this, EventArgs.Empty);
    }
}

class Program
{
    static void Main()
    {
        
        TaskRunner runner = new TaskRunner();

       
        runner.TaskCompleted += Runner_TaskCompleted;

        
        runner.RunTask();

        Console.ReadLine(); 
    }

    
    private static void Runner_TaskCompleted(object sender, EventArgs e)
    {
        Console.WriteLine("Задача завершена!");
    }
}
