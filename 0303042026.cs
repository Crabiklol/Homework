using System;
using System.Collections.Generic;


public class User
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Status { get; set; }

    public User(string name, int age, string status)
    {
        Name = name;
        Age = age;
        Status = status;
    }

   
    public override string ToString()
    {
        return $"[Имя: {Name,-12} | Возраст: {Age,-2} | Статус: {Status}]";
    }
}

public class Program
{
   
    public static List<User> FilterUsers(List<User> users, Predicate<User> condition)
    {
        List<User> result = new List<User>();
        foreach (User user in users)
        {
            
            if (condition(user))
            {
                result.Add(user);
            }
        }
        return result;

     
    }

    public static void Main()
    {
       
        List<User> users = new List<User>
        {
            new User("Алексей", 20, "Активен"),
            new User("Мария", 17, "Активен"),
            new User("Иван", 25, "Забанен"),
            new User("Ольга", 30, "Забанен"),
            new User("Дмитрий", 16, "Забанен"),
            new User("Елена", 19, "Активен")
        };

        Console.WriteLine("--- Исходный список пользователей ---");
        PrintUsers(users);

      

       
        Console.WriteLine("\n--- 1. Совершеннолетние пользователи ---");
        List<User> adults = FilterUsers(users, u => u.Age >= 18);
        PrintUsers(adults);

       
        Console.WriteLine("\n--- 2. Забаненные пользователи ---");
        List<User> banned = FilterUsers(users, u => u.Status == "Забанен");
        PrintUsers(banned);

       
        Console.WriteLine("\n--- 3. Активные совершеннолетние пользователи ---");
        List<User> activeAdults = FilterUsers(users, u => u.Age >= 18 && u.Status == "Активен");
        PrintUsers(activeAdults);
    }

    
    private static void PrintUsers(List<User> userList)
    {
        if (userList.Count == 0)
        {
            Console.WriteLine("Пользователи не найдены.");
            return;
        }

        foreach (User user in userList)
        {
            Console.WriteLine(user);
        }
    }
}
