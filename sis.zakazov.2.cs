using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using Microsoft.Extensions.DependencyInjection;

// ========== Модель ==========
public class Order
{
    public int Id { get; set; }
    public string Product { get; set; } = "";
    public double Price { get; set; }
}

// ========== Интерфейсы ==========
public interface IOrderRepository
{
    void Save(Order order);
    List<Order> GetAll();
}

public interface ILogger
{
    void Log(string message);
}

public interface IOrderService
{
    void CreateOrder(Order order);
    List<Order> GetOrders();
}

// ========== Реализация репозитория (файл JSON) ==========
public class FileOrderRepository : IOrderRepository
{
    private readonly string _filePath = "orders.json";

    public FileOrderRepository()
    {
        if (!File.Exists(_filePath))
            File.WriteAllText(_filePath, "[]");
    }

    public void Save(Order order)
    {
        var orders = GetAll();
        order.Id = orders.Any() ? orders.Max(o => o.Id) + 1 : 1;
        orders.Add(order);
        var json = JsonSerializer.Serialize(orders, new JsonSerializerOptions { WriteIndented = true });
        File.WriteAllText(_filePath, json);
    }

    public List<Order> GetAll()
    {
        var json = File.ReadAllText(_filePath);
        return JsonSerializer.Deserialize<List<Order>>(json) ?? new List<Order>();
    }
}

// ========== Реализация логгера (файл) ==========
public class FileLogger : ILogger
{
    private readonly string _logFile = "app.log";
    public void Log(string message)
    {
        var logEntry = $"[{DateTime.Now:yyyy-MM-dd HH:mm:ss}] {message}";
        File.AppendAllText(_logFile, logEntry + Environment.NewLine);
    }
}

// ========== Сервис (бизнес-логика) ==========
public class OrderService : IOrderService
{
    private readonly IOrderRepository _repository;
    private readonly ILogger _logger;

    public OrderService(IOrderRepository repository, ILogger logger)
    {
        _repository = repository;
        _logger = logger;
    }

    public void CreateOrder(Order order)
    {
        if (string.IsNullOrWhiteSpace(order.Product))
            throw new ArgumentException("Название товара не может быть пустым");
        if (order.Price <= 0)
            throw new ArgumentException("Цена должна быть больше 0");

        _repository.Save(order);
        _logger.Log($"Создан заказ: {order.Product} - {order.Price}");
    }

    public List<Order> GetOrders()
    {
        _logger.Log("Запрошен список заказов");
        return _repository.GetAll();
    }
}

// ========== Главная программа с DI ==========
class Program
{
    static void Main()
    {
        // Настройка DI контейнера
        var services = new ServiceCollection();
        services.AddTransient<IOrderRepository, FileOrderRepository>();
        services.AddSingleton<ILogger, FileLogger>();   // синглтон для логгера
        services.AddTransient<IOrderService, OrderService>();

        var provider = services.BuildServiceProvider();
        var orderService = provider.GetRequiredService<IOrderService>();

        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("\n=== Система обработки заказов ===");
            Console.WriteLine("1. Добавить заказ");
            Console.WriteLine("2. Показать заказы");
            Console.WriteLine("3. Выход");
            Console.Write("Выбор: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    AddOrder(orderService);
                    break;
                case "2":
                    ShowOrders(orderService);
                    break;
                case "3":
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Неверный ввод");
                    break;
            }
        }
    }

    static void AddOrder(IOrderService service)
    {
        try
        {
            Console.Write("Название товара: ");
            string product = Console.ReadLine();
            Console.Write("Цена: ");
            string priceStr = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(product) || string.IsNullOrWhiteSpace(priceStr))
            {
                Console.WriteLine("Ошибка: поля не могут быть пустыми");
                return;
            }

            if (!double.TryParse(priceStr, out double price))
            {
                Console.WriteLine("Ошибка: цена должна быть числом");
                return;
            }

            var order = new Order { Product = product, Price = price };
            service.CreateOrder(order);
            Console.WriteLine("Заказ добавлен!");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }

    static void ShowOrders(IOrderService service)
    {
        try
        {
            var orders = service.GetOrders();
            if (orders.Count == 0)
            {
                Console.WriteLine("Заказов нет.");
                return;
            }

            Console.WriteLine("\nСписок заказов:");
            foreach (var o in orders)
                Console.WriteLine($"ID: {o.Id}, Товар: {o.Product}, Цена: {o.Price}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }
}
