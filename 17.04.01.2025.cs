using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace OrderManagement
{
    class Program
    {
        static string ordersFile = "orders.json";
        static string backupFile = "orders_backup.json";
        static string logFile = "app.log";

        static List<Order> orders = new List<Order>();
        static int nextId = 1;

        static void Main()
        {
            try
            {
                Log("Запуск программы", "INFO");
                LoadOrders();
            }
            catch (Exception ex)
            {
                Log($"Ошибка при запуске: {ex.Message}", "ERROR");
            }

            bool exit = false;
            while (!exit)
            {
                Console.WriteLine("\nМеню:");
                Console.WriteLine("1. Показать все заказы");
                Console.WriteLine("2. Добавить заказ");
                Console.WriteLine("3. Удалить заказ");
                Console.WriteLine("4. Найти заказ по Id");
                Console.WriteLine("5. Выход");
                Console.Write("Выберите действие: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        ShowAllOrders();
                        break;
                    case "2":
                        AddOrder();
                        break;
                    case "3":
                        DeleteOrder();
                        break;
                    case "4":
                        FindOrder();
                        break;
                    case "5":
                        exit = true;
                        break;
                    default:
                        Log("Некорректный ввод", "WARNING");
                        Console.WriteLine("Некорректный выбор. Попробуйте снова.");
                        break;
                }
            }

            try
            {
                SaveOrders();
            }
            catch (Exception ex)
            {
                Log($"Ошибка при сохранении: {ex.Message}", "ERROR");
            }

            Console.WriteLine("До свидания!");
        }

        static void LoadOrders()
        {
            if (File.Exists(ordersFile))
            {
                try
                {
                    string json = File.ReadAllText(ordersFile);
                    orders = JsonSerializer.Deserialize<List<Order>>(json);
                    if (orders != null && orders.Count > 0)
                    {
                        nextId = maxId() + 1;
                    }
                    Log("Данные успешно загружены", "INFO");
                }
                catch (JsonException)
                {
                    Log("Ошибка десериализации файла", "ERROR");
                    Console.WriteLine("Ошибка чтения данных. Старт с пустым списком.");
                    orders = new List<Order>();
                }
                catch (Exception ex)
                {
                    Log($"Ошибка чтения файла: {ex.Message}", "ERROR");
                    Console.WriteLine("Ошибка чтения файла. Старт с пустым списком.");
                    orders = new List<Order>();
                }
            }
            else
            {
                orders = new List<Order>();
                // Файл еще не существует, создаем пустой список
            }
        }

        static void SaveOrders()
        {
            try
            {
                // Создаем резервную копию
                if (File.Exists(ordersFile))
                {
                    File.Copy(ordersFile, backupFile, true);
                }

                string json = JsonSerializer.Serialize(orders, new JsonSerializerOptions { WriteIndented = true });
                File.WriteAllText(ordersFile, json);
                Log("Данные успешно сохранены", "INFO");
            }
            catch (Exception ex)
            {
                Log($"Ошибка при записи файла: {ex.Message}", "ERROR");
                Console.WriteLine("Ошибка при сохранении данных.");
            }
        }

        static void ShowAllOrders()
        {
            if (orders.Count == 0)
            {
                Console.WriteLine("Нет заказов.");
                return;
            }

            Console.WriteLine("\nСписок заказов:");
            foreach (var order in orders)
            {
                Console.WriteLine($"Id: {order.Id} | Товар: {order.Product} | Цена: {order.Price} | Количество: {order.Quantity} | Итог: {order.Total}");
            }
        }

        static void AddOrder()
        {
            Console.Write("Введите название товара: ");
            string product = Console.ReadLine();

            double price;
            while (true)
            {
                Console.Write("Введите цену: ");
                if (double.TryParse(Console.ReadLine(), out price) && price > 0)
                    break;
                else
                    Log("Некорректный ввод цены", "WARNING");
            }

            int quantity;
            while (true)
            {
                Console.Write("Введите количество: ");
                if (int.TryParse(Console.ReadLine(), out quantity) && quantity > 0)
                    break;
                else
                    Log("Некорректный ввод количества", "WARNING");
            }

            Order newOrder = new Order
            {
                Id = nextId++,
                Product = product,
                Price = price,
                Quantity = quantity
            };

            orders.Add(newOrder);
            Log($"Добавлен заказ Id={newOrder.Id}", "INFO");
            SaveOrders();
        }

        static void DeleteOrder()
        {
            Console.Write("Введите Id заказа для удаления: ");
            if (int.TryParse(Console.ReadLine(), out int id))
            {
                var order = orders.Find(o => o.Id == id);
                if (order != null)
                {
                    orders.Remove(order);
                    Log($"Удален заказ Id={id}", "INFO");
                    SaveOrders();
                }
                else
                {
                    Log($"Попытка удалить несуществующий заказ Id={id}", "WARNING");
                    Console.WriteLine("Заказ не найден.");
                }
            }
            else
            {
                Log("Некорректный ввод Id для удаления", "WARNING");
                Console.WriteLine("Некорректный ввод Id.");
            }
        }

        static void FindOrder()
        {
            Console.Write("Введите Id заказа: ");
            if (int.TryParse(Console.ReadLine(), out int id))
            {
                var order = orders.Find(o => o.Id == id);
                if (order != null)
                {
                    Console.WriteLine($"Id: {order.Id} | Товар: {order.Product} | Цена: {order.Price} | Количество: {order.Quantity} | Итог: {order.Total}");
                }
                else
                {
                    Console.WriteLine("Заказ не найден.");
                }
            }
            else
            {
                Log("Некорректный ввод Id для поиска", "WARNING");
                Console.WriteLine("Некорректный ввод Id.");
            }
        }

        static int maxId()
        {
            if (orders.Count == 0) return 0;
            return Math.Max(0, Math.Max(0, orders[^1].Id));
        }

        static void Log(string message, string level)
        {
            string timestamp = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            string logEntry = $"[{timestamp}] [{level}] {message}";
            Console.WriteLine(logEntry);

            // Для логирования ошибок в JSON формате можно расширить:
            if (level == "ERROR")
            {
                var errorLog = new { Time = timestamp, Level = level, Message = message };
                string jsonLog = JsonSerializer.Serialize(errorLog);
                File.AppendAllText(logFile, jsonLog + Environment.NewLine);
            }
            else
            {
                File.AppendAllText(logFile, logEntry + Environment.NewLine);
            }
        }
    }

    public class Order
    {
        public int Id { get; set; }
        public string Product { get; set; }
        public double Price { get; set; }
        public int Quantity { get; set; }

        public double Total => Price * Quantity;
    }
}
