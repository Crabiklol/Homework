using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;

namespace OrderManagement
{
    class Order
    {
        public int Id { get; set; }
        public string Product { get; set; }
        public double Price { get; set; }
        public int Quantity { get; set; }
    }

    class Program
    {
        private static List<Order> orders = new List<Order>();
        private const string OrdersFile = "orders.json";
        private const string LogFile = "app.log";

        static void Main()
        {
            Log("INFO", "Программа запущена");
            LoadOrders();

            while (true)
            {
                Console.WriteLine("\n1. Показать все заказы");
                Console.WriteLine("2. Добавить заказ");
                Console.WriteLine("3. Удалить заказ");
                Console.WriteLine("4. Найти заказ по Id");
                Console.WriteLine("5. Выход");
                Console.Write("Выбор: ");

                string choice = Console.ReadLine();
                switch (choice)
                {
                    case "1": ShowAllOrders(); break;
                    case "2": AddOrder(); break;
                    case "3": DeleteOrder(); break;
                    case "4": FindOrder(); break;
                    case "5": return;
                    default: Console.WriteLine("Неверный ввод"); break;
                }
            }
        }

        static void LoadOrders()
        {
            try
            {
                if (File.Exists(OrdersFile))
                {
                    string json = File.ReadAllText(OrdersFile);
                    orders = JsonSerializer.Deserialize<List<Order>>(json) ?? new List<Order>();
                    Log("INFO", $"Загружено {orders.Count} заказов");
                }
                else
                {
                    orders = new List<Order>();
                    Log("INFO", "Файл не найден, создан пустой список");
                }
            }
            catch (Exception ex)
            {
                Log("ERROR", $"Ошибка загрузки: {ex.Message}");
                orders = new List<Order>();
            }
        }

        static void SaveOrders()
        {
            try
            {
                string json = JsonSerializer.Serialize(orders, new JsonSerializerOptions { WriteIndented = true });
                File.WriteAllText(OrdersFile, json);
                Log("INFO", $"Сохранено {orders.Count} заказов");
            }
            catch (Exception ex)
            {
                Log("ERROR", $"Ошибка сохранения: {ex.Message}");
            }
        }

        static void ShowAllOrders()
        {
            if (orders.Count == 0)
            {
                Console.WriteLine("Заказов нет.");
                return;
            }
            foreach (var o in orders)
                Console.WriteLine($"Id: {o.Id}, Товар: {o.Product}, Цена: {o.Price}, Кол-во: {o.Quantity}");
        }

        static void AddOrder()
        {
            try
            {
                Console.Write("Название товара: ");
                string product = Console.ReadLine();
                if (string.IsNullOrWhiteSpace(product)) throw new Exception("Название не может быть пустым");

                Console.Write("Цена: ");
                if (!double.TryParse(Console.ReadLine(), out double price) || price <= 0)
                    throw new Exception("Цена должна быть > 0");

                Console.Write("Количество: ");
                if (!int.TryParse(Console.ReadLine(), out int quantity) || quantity <= 0)
                    throw new Exception("Количество должно быть > 0");

                int newId = orders.Count > 0 ? orders.Max(o => o.Id) + 1 : 1;
                orders.Add(new Order { Id = newId, Product = product, Price = price, Quantity = quantity });
                SaveOrders();
                Log("INFO", $"Добавлен заказ Id={newId}");
                Console.WriteLine("Заказ добавлен.");
            }
            catch (Exception ex)
            {
                Log("WARNING", $"Ошибка ввода: {ex.Message}");
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        static void DeleteOrder()
        {
            Console.Write("Введите Id заказа для удаления: ");
            if (!int.TryParse(Console.ReadLine(), out int id))
            {
                Console.WriteLine("Неверный Id.");
                return;
            }

            var order = orders.FirstOrDefault(o => o.Id == id);
            if (order == null)
            {
                Log("WARNING", $"Попытка удалить несуществующий Id={id}");
                Console.WriteLine("Заказ не найден.");
                return;
            }

            orders.Remove(order);
            SaveOrders();
            Log("INFO", $"Удалён заказ Id={id}");
            Console.WriteLine("Заказ удалён.");
        }

        static void FindOrder()
        {
            Console.Write("Введите Id заказа: ");
            if (!int.TryParse(Console.ReadLine(), out int id))
            {
                Console.WriteLine("Неверный Id.");
                return;
            }

            var order = orders.FirstOrDefault(o => o.Id == id);
            if (order == null)
                Console.WriteLine("Заказ не найден.");
            else
                Console.WriteLine($"Id: {order.Id}, Товар: {order.Product}, Цена: {order.Price}, Кол-во: {order.Quantity}");
        }

        static void Log(string level, string message)
        {
            try
            {
                string logEntry = $"[{DateTime.Now:yyyy-MM-dd HH:mm:ss}] [{level}] {message}";
                File.AppendAllText(LogFile, logEntry + Environment.NewLine);
            }
            catch { /* игнорируем ошибки логирования */ }
        }
    }
}
