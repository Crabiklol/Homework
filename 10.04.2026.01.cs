//1
using System;
using System.IO;

public class Logger
{
    private readonly string logDirectory = AppDomain.CurrentDomain.BaseDirectory;
    private readonly string logFileName = "app.log";
    private readonly long maxSizeBytes = 1 * 1024 * 1024; // 1MB
    private int fileIndex = 0;
    private string currentLogFilePath;

    private readonly object lockObj = new object();

    public Logger()
    {
        currentLogFilePath = Path.Combine(logDirectory, logFileName);
    
        RotateLogFileIfNeeded();
    }

    public void Info(string message)
    {
        Log("INFO", message);
    }

    public void Warning(string message)
    {
        Log("WARNING", message);
    }

    public void Error(string message)
    {
        Log("ERROR", message);
    }

    private void Log(string level, string message)
    {
        lock (lockObj)
        {
            RotateLogFileIfNeeded();

            string logEntry = $"[{DateTime.Now:yyyy-MM-dd HH:mm:ss}] [{level}] {message}";
            File.AppendAllText(currentLogFilePath, logEntry + Environment.NewLine);
        }
    }

    private void RotateLogFileIfNeeded()
    {
        if (File.Exists(currentLogFilePath))
        {
            var info = new FileInfo(currentLogFilePath);
            if (info.Length > maxSizeBytes)
            {
                fileIndex++;
                currentLogFilePath = Path.Combine(logDirectory, $"app_{fileIndex}.log");
            }
        }
        else
        {
            // Файл еще не создан
        }
    }
}



//2
using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Linq;

public class User
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Age { get; set; }
}

public class UserManager
{
    private readonly string filePath = "users.json";
    private List<User> users;

    public UserManager()
    {
        Load();
    }

    public void Load()
    {
        try
        {
            if (!File.Exists(filePath))
            {
                users = new List<User>();
                Save();
            }
            else
            {
                string json = File.ReadAllText(filePath);
                users = JsonSerializer.Deserialize<List<User>>(json) ?? new List<User>();
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка загрузки: {ex.Message}");
            users = new List<User>();
        }
    }

    public void Add(User user)
    {
        if (users.Any(u => u.Id == user.Id))
        {
            Console.WriteLine("Пользователь с таким Id уже существует");
            return;
        }
        users.Add(user);
        Save();
    }

    public void Remove(int id)
    {
        var user = users.FirstOrDefault(u => u.Id == id);
        if (user != null)
        {
            users.Remove(user);
            Save();
        }
    }

    public void Update(User updatedUser)
    {
        var user = users.FirstOrDefault(u => u.Id == updatedUser.Id);
        if (user != null)
        {
            user.Name = updatedUser.Name;
            user.Age = updatedUser.Age;
            Save();
        }
    }

    private void Save()
    {
        try
        {
            string json = JsonSerializer.Serialize(users, new JsonSerializerOptions { WriteIndented = true });
            File.WriteAllText(filePath, json);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка сохранения: {ex.Message}");
        }
    }
}

//3
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class LogAnalyzer
{
    public static void Analyze(string filePath)
    {
        if (!File.Exists(filePath))
        {
            Console.WriteLine("Файл не найден");
            return;
        }

        var counts = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase)
        {
            {"INFO", 0},
            {"WARNING", 0},
            {"ERROR", 0}
        };

        var messages = new List<string>();

        using (var reader = new StreamReader(filePath))
        {
            string line;
            while ((line = reader.ReadLine()) != null)
            {
                if (string.IsNullOrWhiteSpace(line))
                    continue;

                var parts = line.Split(':', 2);
                if (parts.Length < 2)
                    continue;

                string type = parts[0].Trim().ToUpper();

                if (counts.ContainsKey(type))
                {
                    counts[type]++;
                }
                // собираем для поиска самого частого
                messages.Add(type);
            }
        }

        // определяем наиболее часто встречающийся
        string mostCommon = counts.OrderByDescending(c => c.Value).First().Key;

        // сохраняем отчет
        using (var writer = new StreamWriter("report.txt"))
        {
            writer.WriteLine($"INFO: {counts["INFO"]}");
            writer.WriteLine($"WARNING: {counts["WARNING"]}");
            writer.WriteLine($"ERROR: {counts["ERROR"]}");
            writer.WriteLine($"Самый частый: {mostCommon}");
        }
    }
}


//4
using System;
using System.IO;

public class DirectoryBackup
{
    private readonly string sourceDir;
    private readonly string backupDir;
    private readonly Logger logger;

    public DirectoryBackup(string source)
    {
        sourceDir = source;
        string date = DateTime.Now.ToString("yyyyMMdd");
        backupDir = $"backup_{date}";
        logger = new Logger();
    }

    public void CopyDirectory()
    {
        try
        {
            if (!Directory.Exists(sourceDir))
            {
                logger.Error($"Источник {sourceDir} не существует");
                return;
            }

            CopyAll(new DirectoryInfo(sourceDir), new DirectoryInfo(backupDir));
            logger.Info($"Резервное копирование завершено успешно: {backupDir}");
        }
        catch (Exception ex)
        {
            logger.Error($"Ошибка при копировании: {ex.Message}");
        }
    }

    private void CopyAll(DirectoryInfo source, DirectoryInfo target)
    {
        Directory.CreateDirectory(target.FullName);

        foreach (FileInfo fi in source.GetFiles())
        {
            try
            {
                fi.CopyTo(Path.Combine(target.FullName, fi.Name), true);
                logger.Info($"Скопирован файл: {fi.Name}");
            }
            catch (Exception ex)
            {
                logger.Error($"Не удалось скопировать {fi.Name}: {ex.Message}");
            }
        }

        foreach (DirectoryInfo di in source.GetDirectories())
        {
            CopyAll(di, target.CreateSubdirectory(di.Name));
        }
    }
}

//5
using System;
using System.IO;
using System.Text.Json;
using System.Xml.Linq;

public class JsonToXmlConverter
{
    public static void Convert(string jsonFilePath, string xmlFilePath)
    {
        try
        {
            string jsonString = File.ReadAllText(jsonFilePath);
            using (JsonDocument doc = JsonDocument.Parse(jsonString))
            {
                var rootElement = doc.RootElement;

                XElement xml = new XElement("Product");

                foreach (var property in rootElement.EnumerateObject())
                {
                    xml.Add(new XElement(property.Name, property.Value.ToString()));
                }

                xml.Save(xmlFilePath);
                Console.WriteLine($"Конвертация завершена: {xmlFilePath}");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }
}

//6
using System;
using System.IO;

public class FolderWatcher
{
    private readonly string path;
    private readonly Logger logger;

    public FolderWatcher(string folderPath)
    {
        path = folderPath;
        logger = new Logger();
    }

    public void Start()
    {
        var watcher = new FileSystemWatcher(path, "*.txt")
        {
            NotifyFilter = NotifyFilters.FileName | NotifyFilters.LastWrite
        };

        watcher.Created += (s, e) => {
            Console.WriteLine($"Создан файл: {e.Name}");
            logger.Info($"Создан файл: {e.Name}");
        };
        watcher.Deleted += (s, e) => {
            Console.WriteLine($"Удалён файл: {e.Name}");
            logger.Info($"Удалён файл: {e.Name}");
        };
        watcher.Changed += (s, e) => {
            Console.WriteLine($"Изменён файл: {e.Name}");
            logger.Info($"Изменён файл: {e.Name}");
        };

        watcher.EnableRaisingEvents = true;
        Console.WriteLine("Мониторинг запущен...");
        Console.ReadLine(); // чтобы программа не завершилась
    }
}

