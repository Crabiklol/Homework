using System;
using System.Collections.Generic;


public class Seat
{
    public decimal Price { get; set; }
    public bool IsBooked { get; set; }
}


public class CinemaHall
{
   
    public Seat[,] Seats { get; } = new Seat[5, 10];

 
    public event Action OnHallFull;

   
    public Action<string> History { get; set; }
    public List<string> HistoryLog { get; } = new List<string>();

    public CinemaHall()
    {
        
        History = (msg) => HistoryLog.Add($"{DateTime.Now:HH:mm:ss} | {msg}");

       
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 10; c++)
            {
               
                decimal basePrice = 600m - (r * 50m);
                Seats[r, c] = new Seat { Price = basePrice, IsBooked = false };
            }
        }
    }

    
    public void ShowAvailable(Predicate<Seat> filter)
    {
        bool found = false;
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                if (filter(Seats[r, c]))
                {
                    Console.WriteLine($"[Ряд {r + 1}, Место {c + 1}] - Цена: {Seats[r, c].Price} руб.");
                    found = true;
                }
            }
        }
        if (!found)
        {
            Console.WriteLine("Подходящие места не найдены.");
        }
    }


    public bool TryBook(int row, int col, Func<int, int, decimal, decimal> priceModifier)
    {
   
        if (row < 1 || row > 5 || col < 1 || col > 10)
        {
            History($"Ошибка: Ряд {row} или Место {col} не существует");
            return false;
        }

        int r = row - 1;
        int c = col - 1;

     
        if (Seats[r, c].IsBooked)
        {
            History($"Ошибка: Ряд {row}, Место {col} уже забронировано");
            return false;
        }

       
        decimal finalPrice = priceModifier(row, col, Seats[r, c].Price);

      
        Seats[r, c].IsBooked = true;
        History($"Ряд {row}, Место {col} забронировано за {finalPrice} руб.");

       
        CheckIfFull();

        return true;
    }

 
    private void CheckIfFull()
    {
        bool isFull = true;
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                if (!Seats[r, c].IsBooked)
                {
                    isFull = false;
                    break;
                }
            }
            if (!isFull) break;
        }

      
        if (isFull)
        {
            OnHallFull?.Invoke();
        }
    }
}

public class Program
{
    public static void Main()
    {
        CinemaHall hall = new CinemaHall();

        hall.OnHallFull += () => hall.History("СОБЫТИЕ: Зал полностью заполнен!");

        Console.WriteLine("--- 1. Все свободные места ---");
        hall.ShowAvailable(s => !s.IsBooked);

        Console.WriteLine("\n--- 2. Свободные места дешевле 400 рублей ---");
        hall.ShowAvailable(s => !s.IsBooked && s.Price < 400m);

        Console.WriteLine("\n--- 3. Тестирование бронирования ---");

       
        hall.TryBook(3, 5, (r, c, basePrice) => basePrice);

   
        
        hall.TryBook(5, 2, (r, c, basePrice) =>
        {
            decimal price = basePrice;
            if (r == 5) price *= 1.2m;      
            if (c >= 1 && c <= 3) price *= 0.9m;
            return price;
        });

        
        hall.TryBook(10, 5, (r, c, basePrice) => basePrice);

      
        hall.TryBook(5, 2, (r, c, basePrice) => basePrice);

        Console.WriteLine("\n--- 4. История операций (Лог) ---");
        foreach (var logEntry in hall.HistoryLog)
        {
            Console.WriteLine(logEntry);
        }
    }
}
