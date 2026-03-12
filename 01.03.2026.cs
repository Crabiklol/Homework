public class Item
{
    public string Name { get; set; }
    public string Type { get; set; }        // оружие, броня, зелье
    public string Rarity { get; set; }      // обычный, редкий, эпический
    public int Value { get; set; }
}

var inventory = new List<Item>
{
    new Item { Name = "Меч", Type = "Оружие", Rarity = "Редкий", Value = 150 },
    new Item { Name = "Щит", Type = "Броня", Rarity = "Обычный", Value = 50 },
    new Item { Name = "Зелье здоровья", Type = "Зелье", Rarity = "Эпический", Value = 200 },
    // остальные предметы
};




// Найти все редкие предметы
var rareItems = inventory.Where(item => item.Rarity == "Редкий");
Console.WriteLine("Редкие предметы:");
foreach (var item in rareItems)
    Console.WriteLine($"{item.Name} - {item.Rarity}");

// Самый дорогой предмет
var mostExpensiveItem = inventory.OrderByDescending(item => item.Value).FirstOrDefault();
Console.WriteLine($"Самый дорогой предмет: {mostExpensiveItem?.Name} - {mostExpensiveItem?.Value}");

// Группировка по типу
var groupedByType = inventory.GroupBy(item => item.Type);
foreach (var group in groupedByType)
{
    Console.WriteLine($"Тип: {group.Key}");
    foreach (var item in group)
        Console.WriteLine($"  {item.Name}");
}

// Средняя стоимость по типам
var avgValueByType = inventory
    .GroupBy(item => item.Type)
    .Select(g => new { Type = g.Key, AverageValue = g.Average(i => i.Value) });
foreach (var group in avgValueByType)
    Console.WriteLine($"{group.Type}: {group.AverageValue}");

// Предметы с ценой выше средней всего инвентаря
var avgValueAll = inventory.Average(i => i.Value);
var expensiveItems = inventory.Where(i => i.Value > avgValueAll);
Console.WriteLine("Предметы дороже средней стоимости:");
foreach (var item in expensiveItems)
    Console.WriteLine($"{item.Name} - {item.Value}");


public class Quest
{
    public string Name { get; set; }
    public int Level { get; set; }
    public int Reward { get; set; }
    public bool IsCompleted { get; set; }
}


public class Hero
{
    public string Name { get; set; }
    public string Class { get; set; }   // воин, маг, лучник
    public int Level { get; set; }
    public int Health { get; set; }
    public int Attack { get; set; }
    public int Defense { get; set; }
}

public class Enemy
{
    public string Name { get; set; }
    public string Type { get; set; }  // обычный, босс
    public int Health { get; set; }
    public int Attack { get; set; }
    public int Defense { get; set; }
}


public class GameSession
{
    public string Player { get; set; }
    public int Level { get; set; }
    public int Kills { get; set; }
    public int Deaths { get; set; }
    public int TimePlayed { get; set; } // в минутах
}


var availableQuests = quests.Where(q => q.Level <= 5 && !q.IsCompleted);

