//1
using System;
using System.Collections.Generic;
using System.Linq;

public class GameObject : IDisposable
{
    public string Name { get; set; }
    public int Id { get; private set; }
    public bool IsActive { get; set; }
    private bool disposed = false;
    private static int nextId = 1;

    private List<string> components;
    
    private IntPtr unmanagedResource;

    public GameObject(string name)
    {
        Id = nextId++;
        Name = name;
        IsActive = true;
        components = new List<string>();
        
        Console.WriteLine($"[{Id}] Создан объект: {Name}");
        components.Add("Transform");
        components.Add("Renderer");
        
        unmanagedResource = new IntPtr(Id * 1000);
        Console.WriteLine($"[{Id}] Выделены ресурсы для: {Name}");
    }

    public void AddComponent(string component)
    {
        if (disposed)
            throw new ObjectDisposedException(Name);
        
        components.Add(component);
        Console.WriteLine($"[{Id}] Компонент '{component}' добавлен к {Name}");
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                // Освобождаем управляемые ресурсы
                Console.WriteLine($"[{Id}] Освобождение управляемых ресурсов объекта: {Name}");
                components.Clear();
                components = null;
            }

            // Освобождаем неуправляемые ресурсы
            if (unmanagedResource != IntPtr.Zero)
            {
                Console.WriteLine($"[{Id}] Освобождение неуправляемых ресурсов объекта: {Name}");
                unmanagedResource = IntPtr.Zero;
            }

            disposed = true;
            Console.WriteLine($"[{Id}] Объект {Name} полностью освобожден");
        }
    }

    public void CheckAlive()
    {
        if (disposed)
            Console.WriteLine($"[{Id}] Объект {Name} уничтожен");
        else
            Console.WriteLine($"[{Id}] Объект {Name} активен");
    }

    ~GameObject()
    {
        Dispose(false);
        Console.WriteLine($"[{Id}] Финализатор вызван для {Name}");
    }
}

public class GameObjectManager : IDisposable
{
    private Dictionary<int, GameObject> gameObjects = new Dictionary<int, GameObject>();
    private bool disposed = false;

    public void AddObject(GameObject gameObject)
    {
        if (disposed)
            throw new ObjectDisposedException("GameObjectManager");
        
        gameObjects[gameObject.Id] = gameObject;
        Console.WriteLine($"Менеджер: Добавлен объект [{gameObject.Id}] {gameObject.Name}");
    }

    public bool RemoveObject(int id)
    {
        if (gameObjects.TryGetValue(id, out GameObject obj))
        {
            gameObjects.Remove(id);
            obj.Dispose();
            Console.WriteLine($"Менеджер: Удален объект [{id}] {obj.Name}");
            return true;
        }
        return false;
    }

    public GameObject GetObject(int id)
    {
        return gameObjects.TryGetValue(id, out GameObject obj) ? obj : null;
    }

    public void Clear()
    {
        foreach (var obj in gameObjects.Values.ToList())
        {
            obj.Dispose();
        }
        gameObjects.Clear();
        Console.WriteLine("Менеджер: Все объекты удалены");
    }

    public void PrintActiveObjects()
    {
        Console.WriteLine($"\nАктивные объекты ({gameObjects.Count}):");
        foreach (var obj in gameObjects.Values)
        {
            Console.WriteLine($"  - [{obj.Id}] {obj.Name}");
        }
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                Clear();
            }
            disposed = true;
            Console.WriteLine("Менеджер: Освобожден");
        }
    }

    ~GameObjectManager()
    {
        Dispose(false);
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("=== Тестирование системы управления объектами ===\n");

        using (GameObjectManager manager = new GameObjectManager())
        {
            // Создаем и добавляем объекты
            var player = new GameObject("Игрок");
            player.AddComponent("Health");
            player.AddComponent("Inventory");
            manager.AddObject(player);

            var enemy1 = new GameObject("Враг 1");
            enemy1.AddComponent("AI");
            manager.AddObject(enemy1);

            var enemy2 = new GameObject("Враг 2");
            enemy2.AddComponent("AI");
            enemy2.AddComponent("Patrol");
            manager.AddObject(enemy2);

            manager.PrintActiveObjects();

            // Удаляем одного врага
            Console.WriteLine("\n--- Удаляем Врага 1 ---");
            manager.RemoveObject(enemy1.Id);

            manager.PrintActiveObjects();

            // Пытаемся использовать удаленный объект
            Console.WriteLine("\n--- Проверка удаленного объекта ---");
            try
            {
                enemy1.AddComponent("Test");
            }
            catch (ObjectDisposedException ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }

            // Добавляем временный объект в блок
            Console.WriteLine("\n--- Создаем временный объект ---");
            using (var tempObject = new GameObject("Временный"))
            {
                manager.AddObject(tempObject);
                manager.PrintActiveObjects();
            } 

            manager.PrintActiveObjects();
            } 
        Console.WriteLine("\n=== Принудительный вызов сборщика мусора ===");
        GC.Collect();
        GC.WaitForPendingFinalizers();
        
        Console.WriteLine("\nПрограмма завершена");
    }
}


//2
using System;
using System.Collections.Generic;

public class Sound : IDisposable
{
    public string Name { get; set; }
    private bool disposed = false;

    public Sound(string name)
    {
        Name = name;
        Console.WriteLine($"Загружен звук: {Name}");
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                // Освобождаем управляемые ресурсы (в реальном приложении — закрытие потоков, освобождение буферов и т.п.)
                Console.WriteLine($"Освобожден звук: {Name}");
            }

            // Здесь бы освобождали неуправляемые ресурсы, если бы они были.

            disposed = true;
        }
    }

    ~Sound()
    {
        Dispose(false);
    }
}

public class SoundManager
{
    private readonly Dictionary<string, Sound> sounds = new Dictionary<string, Sound>();

    public Sound LoadSound(string name)
    {
        if (!sounds.ContainsKey(name))
        {
            sounds[name] = new Sound(name);
        }
        return sounds[name];
    }

    public void UnloadSound(string name)
    {
        if (sounds.TryGetValue(name, out Sound sound))
        {
            sound.Dispose();
            sounds.Remove(name);
            Console.WriteLine($"Выгружен звук: {name}");
        }
    }

    public void Clear()
    {
        foreach (var sound in sounds.Values)
        {
            sound.Dispose();
        }
        sounds.Clear();
        Console.WriteLine("Все звуки выгружены");
    }
}

class Program
{
    static void Main()
    {
        SoundManager soundManager = new SoundManager();

        // 1. Загружаем звуки
        soundManager.LoadSound("Музыка");
        soundManager.LoadSound("Эффект 1");
        soundManager.LoadSound("Эффект 2");

        // 2. Выгружаем один звук
        soundManager.UnloadSound("Эффект 1");

        // 3. Очищаем все звуки
        soundManager.Clear();

        // 4. Проверяем работу финализаторов
        GC.Collect();
        GC.WaitForPendingFinalizers();
    }
}
//3
using System;
using System.Collections.Generic;

public class Texture : IDisposable
{
    public string Name { get; set; }
    private bool disposed = false;

    public Texture(string name)
    {
        Name = name;
        Console.WriteLine($"Загружена текстура: {Name}");
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this); // сообщаем GC, что финализатор можно не вызывать
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                // Освобождаем управляемые ресурсы (если бы они были, кроме Name)
                Console.WriteLine($"Освобождена текстура: {Name}");
            }

            // Здесь освобождали бы неуправляемые ресурсы (если есть)

            disposed = true;
        }
    }

    ~Texture()
    {
        // На случай, если Dispose не был вызван вручную
        Dispose(false);
    }
}

public class TextureManager
{
    private readonly Dictionary<string, Texture> textures = new Dictionary<string, Texture>();

    // Загрузка текстуры (если уже есть — возвращаем существующую)
    public Texture LoadTexture(string name)
    {
        if (!textures.ContainsKey(name))
        {
            textures[name] = new Texture(name);
        }
        return textures[name];
    }

    // Выгрузка конкретной текстуры
    public void UnloadTexture(string name)
    {
        if (textures.TryGetValue(name, out Texture texture))
        {
            texture.Dispose();
            textures.Remove(name);
            Console.WriteLine($"Выгружена текстура: {name}");
        }
    }

    // Полная очистка всех текстур
    public void Clear()
    {
        foreach (var texture in textures.Values)
        {
            texture.Dispose();
        }
        textures.Clear();
        Console.WriteLine("Все текстуры выгружены");
    }
}

class Program
{
    static void Main()
    {
        TextureManager textureManager = new TextureManager();

        // 1. Загружаем текстуры
        textureManager.LoadTexture("Дерево");
        textureManager.LoadTexture("Камень");
        textureManager.LoadTexture("Трава");

        // 2. Выгружаем одну текстуру
        textureManager.UnloadTexture("Камень");

        // 3. Очищаем все оставшиеся текстуры
        textureManager.Clear();

        // 4. Проверка работы финализаторов (на случай, если где-то забыли Dispose)
        GC.Collect();
        GC.WaitForPendingFinalizers();

        Console.WriteLine("Работа с текстурами завершена.");
        Console.ReadLine();
    }
}
