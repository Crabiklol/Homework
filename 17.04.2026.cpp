//1
#include <iostream>

class Singleton {
private:
    Singleton() {} // закрытый конструктор
public:
    Singleton(const Singleton&) = delete; // запрет копирования
    Singleton& operator=(const Singleton&) = delete; // запрет присваивания

    static Singleton& getInstance() {
        static Singleton instance; // статическая переменная
        return instance;
    }

    void print() const {
        std::cout << "Singleton instance at: " << this << std::endl;
    }
};

//2
int main() {
    auto& obj1 = Singleton::getInstance();
    auto& obj2 = Singleton::getInstance();

    std::cout << "Адрес первого: " << &obj1 << std::endl;
    std::cout << "Адрес второго: " << &obj2 << std::endl;

    if (&obj1 == &obj2) {
        std::cout << "Это один и тот же объект." << std::endl;
    }
}

//3
int main() {
    auto& instance = Singleton::getInstance();
    instance.print();
    instance.print();
}

//4
#include <iostream>

class CounterSingleton {
private:
    int count = 0;
    CounterSingleton() {}
public:
    CounterSingleton(const CounterSingleton&) = delete;
    CounterSingleton& operator=(const CounterSingleton&) = delete;

    static CounterSingleton& getInstance() {
        static CounterSingleton instance;
        return instance;
    }

    void increment() {
        ++count;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    auto& cnt = CounterSingleton::getInstance();
    cnt.increment();
    cnt.increment();
    std::cout << "Вызовов: " << cnt.getCount() << std::endl;
}

//5
#include <string>
#include <iostream>

class App {
private:
    std::string appName;
    App(const std::string& name) : appName(name) {}
public:
    App(const App&) = delete;
    App& operator=(const App&) = delete;

    static App& getInstance() {
        static App instance("MyApplication");
        return instance;
    }

    void printName() const {
        std::cout << "Приложение: " << appName << std::endl;
    }
};

int main() {
    auto& app = App::getInstance();
    app.printName();
}

//6
#include <mutex>

class Config {
private:
    int volume = 50; // по умолчанию
    Config() {}
public:
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    static Config& getInstance() {
        static Config instance;
        return instance;
    }

    void setVolume(int v) {
        volume = v;
    }

    int getVolume() const {
        return volume;
    }
};

//7
void functionA() {
    auto& cfg = Config::getInstance();
    cfg.setVolume(75);
}

void functionB() {
    auto& cfg = Config::getInstance();
    std::cout << "Текущий volume: " << cfg.getVolume() << std::endl;
}

int main() {
    functionA();
    functionB(); // увидите 75
}

//8
#include <iostream>
#include <string>

class Logger {
private:
    Logger() {}
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

//9

void functionX() {
    auto& logger = Logger::getInstance();
    logger.log("Вызов из функции X");
}

void functionY() {
    auto& logger = Logger::getInstance();
    logger.log("Вызов из функции Y");
}

int main() {
    functionX();
    functionY();
}

//10
#include <map>
#include <string>

class DataManager {
private:
    std::map<std::string, int> data;
    DataManager() {}
public:
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    static DataManager& getInstance() {
        static DataManager instance;
        return instance;
    }

    void addValue(const std::string& key, int value) {
        data[key] = value;
    }

    int getValue(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return 0; // или выбросить исключение
    }
};

int main() {
    auto& dm = DataManager::getInstance();
    dm.addValue("item1", 100);
    std::cout << "item1: " << dm.getValue("item1") << std::endl;
}

