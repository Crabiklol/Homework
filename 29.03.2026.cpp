// 1

#include <iostream>
using namespace std;

// Абстрактный класс Transport
class Transport {
public:
    virtual void move() = 0; // Чистый виртуальный метод
    virtual ~Transport() {} // Виртуальный деструктор
};

// Класс Car, наследуется от Transport
class Car : public Transport {
public:
    void move() override {
        cout << "Машина едет по трассе." << endl;
    }
};

// Класс Bike, наследуется от Transport
class Bike : public Transport {
public:
    void move() override {
        cout << "Мотик гоняет на драгрессиге." << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем указатели на базовый класс
    Transport* t1 = new Car();
    Transport* t2 = new Bike();

    // Вызов методов через указатели
    t1->move();
    t2->move();

    // Освобождение памяти
    delete t1;
    delete t2;

    return 0;
}




// 2

#include <iostream>
using namespace std;

// Абстрактный класс Animal
class Animal {
public:
    virtual void sound() = 0; // Чистый виртуальный метод
    virtual ~Animal() {} // Виртуальный деструктор
};

// Класс Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Собака говорит пепе, шнейне, ватафа!" << endl;
    }
};

// Класс Cow
class Cow : public Animal {
public:
    void sound() override {
        cout << "Корова говорит му му му " << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем указатели на базовый класс
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cow();

    // Вызов методов через указатели
    animal1->sound();
    animal2->sound();

    // Освобождение памяти
    delete animal1;
    delete animal2;

    return 0;
}



// 3


#include <iostream>
using namespace std;

// Абстрактный класс Shape
class Shape {
public:
    virtual double area() const = 0; // Чистый виртуальный метод
    virtual ~Shape() {} // Виртуальный деструктор
};

// Класс Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

// Класс Triangle
class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем указатели на базовый класс
    Shape* shape1 = new Square(5.0);
    Shape* shape2 = new Triangle(4.0, 3.0);

    // Вызов методов через указатели
    cout << "Square area: " << shape1->area() << endl;
    cout << "Triangle area: " << shape2->area() << endl;

    // Освобождение памяти
    delete shape1;
    delete shape2;

    return 0;
}



// 4
#include <iostream>
using namespace std;

// Абстрактный класс Device
class Device {
public:
    virtual void turnOn() = 0; // Чистый виртуальный метод
    virtual ~Device() {} // Виртуальный деструктор
};

// Класс Phone
class Phone : public Device {
public:
    void turnOn() override {
        cout << "телефон только включился" << endl;
    }
};

// Класс Laptop
class Laptop : public Device {
public:
    void turnOn() override {
        cout << "Ноутбук только вкючился" << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем указатели на базовый класс
    Device* device1 = new Phone();
    Device* device2 = new Laptop();

    // Вызов функции через указатели
    device1->turnOn();
    device2->turnOn();

    // Освобождение памяти
    delete device1;
    delete device2;

    return 0;
}

//5



#include <iostream>
using namespace std;

// Абстрактный класс Drink
class Drink {
public:
    virtual void prepare() = 0; // Чистый виртуальный метод
    virtual ~Drink() {} // Виртуальный деструктор
};

// Класс Tea
class Tea : public Drink {
public:
    void prepare() override {
        cout << "готвим чай" << endl;
    }
};

// Класс Coffee
class Coffee : public Drink {
public:
    void prepare() override {
        cout << "готовим кофе." << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем указатели на базовый класс
    Drink* drink1 = new Tea();
    Drink* drink2 = new Coffee();
    
    // Вызов методов через указатели
    drink1->prepare();
    drink2->prepare();
    
    // Освобождение памяти
    delete drink1;
    delete drink2;
    
    return 0;
}


//6

 #include <iostream>
using namespace std;

// Абстрактный класс Payment
class Payment {
public:
    virtual void pay() = 0; // Чистый виртуальный метод
    virtual ~Payment() {} // Виртуальный деструктор
};

// Класс Card
class Card : public Payment {
public:
    void pay() override {
        cout << "Оплата через карту" << endl;
    }
};

// Класс Cash
class Cash : public Payment {
public:
    void pay() override {
        cout << "Оплата наличкой" << endl;
    }
};

// Класс Crypto
class Crypto : public Payment {
public:
    void pay() override {
        cout << "Оплата криптой" << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаем массив указателей на Payment
    Payment* payments[3];

    payments[0] = new Card();
    payments[1] = new Cash();
    payments[2] = new Crypto();

    // Вызываем pay() для каждого
    for (int i = 0; i < 3; ++i) {
        payments[i]->pay();
    }

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) {
        delete payments[i];
    }

    return 0;
}


//7

#include <iostream>
using namespace std;

// Абстрактный класс Employee
class Employee {
public:
    virtual double salary() const = 0; // Чистый виртуальный метод
    virtual ~Employee() {} // Виртуальный деструктор
};

// Класс Manager
class Manager : public Employee {
public:
    double salary() const override {
        return 8000.0; // пример фиксированной зарплаты менеджера
    }
};

// Класс Developer
class Developer : public Employee {
public:
    double salary() const override {
        return 6000.0; // пример фиксированной зарплаты разработчика
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Создаём массив указателей на Employee
    Employee* employees[2];

    employees[0] = new Manager();
    employees[1] = new Developer();

    // Вызов salary() для каждого сотрудника
    for (int i = 0; i < 2; ++i) {
        cout << "Employee " << i+1 << " salary: " << employees[i]->salary() << endl;
    }

    // Освобождаем память
    for (int i = 0; i < 2; ++i) {
        delete employees[i];
    }

    return 0;
}



//8


#include <iostream>
using namespace std;

// Абстрактный класс File
class File {
public:
    virtual void open() = 0; // Чистый виртуальный метод
    virtual ~File() {} // Виртуальный деструктор
};

// Класс TextFile
class TextFile : public File {
public:
    void open() override {
        cout << "Открываем текстовый файл  " << endl;
    }
};

// Класс ImageFile
class ImageFile : public File {
public:
    void open() override {
        cout << "Открываем файл картинки" << endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russia");
    // Массив указателей на File
    File* files[2];

    files[0] = new TextFile();
    files[1] = new ImageFile();

    // Вызов метода open() для каждого файла
    for (int i = 0; i < 2; ++i) {
        files[i]->open();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete files[i];
    }

    return 0;
}

//9


#include <iostream>
using namespace std;

// Абстрактный класс Message
class Message {
public:
    virtual void send() = 0; // Чистый виртуальный метод
    virtual ~Message() {} // Виртуальный деструктор
};

// Класс Email
class Email : public Message {
public:
    void send() override {
        cout << "Sending email..." << endl;
    }
};

// Класс SMS
class SMS : public Message {
public:
    void send() override {
        cout << "Sending SMS..." << endl;
    }
};

int main() {
    // Массив указателей на Message
    Message* messages[2];

    messages[0] = new Email();
    messages[1] = new SMS();

    // Вызов метода send() для каждого сообщения
    for (int i = 0; i < 2; ++i) {
        messages[i]->send();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete messages[i];
    }

    return 0;
}


//10
#include <iostream>
using namespace std;

// Абстрактный класс Enemy
class Enemy {
public:
    virtual void attack() = 0; // Чистый виртуальный метод
    virtual ~Enemy() {} // Виртуальный деструктор
};

// Класс Zombie
class Zombie : public Enemy {
public:
    void attack() override {
        cout << "Zombie attacks with a bite!" << endl;
    }
};

// Класс Alien
class Alien : public Enemy {
public:
    void attack() override {
        cout << "Alien attacks with its rays!" << endl;
    }
};

int main() {
    // Массив указателей на Enemy
    Enemy* enemies[2];

    enemies[0] = new Zombie();
    enemies[1] = new Alien();

    // Вызов attack() для каждого врага
    for (int i = 0; i < 2; ++i) {
        enemies[i]->attack();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete enemies[i];
    }

    return 0;
}


//11

#include <iostream>
using namespace std;

// Абстрактный класс Account
class Account {
public:
    virtual double calculateInterest() const = 0; // Чистый виртуальный метод
    virtual ~Account() {} // Виртуальный деструктор
};

// Класс SavingsAccount
class SavingsAccount : public Account {
    double balance;
public:
    SavingsAccount(double bal) : balance(bal) {}
    double calculateInterest() const override {
        // Например, 5% годовых
        return balance * 0.05;
    }
};

// Класс FixedDeposit
class FixedDeposit : public Account {
    double depositAmount;
    int durationMonths; // срок вклада в месяцах
public:
    FixedDeposit(double amount, int months) : depositAmount(amount), durationMonths(months) {}
    double calculateInterest() const override {
        // Например, 7% в год, учитываем длительность
        double annualInterestRate = 0.07;
        // Переводим месяцы в годы
        double years = durationMonths / 12.0;
        return depositAmount * annualInterestRate * years;
    }
};

int main() {
    // Создаем массив указателей на счета
    Account* accounts[2];
    accounts[0] = new SavingsAccount(10000); // баланс 10,000
    accounts[1] = new FixedDeposit(5000, 24); // вклад 5000 на 2 года

    // Выводим рассчитанную прибыль
    for (int i = 0; i < 2; ++i) {
        cout << "Interest for account " << i+1 << ": " << accounts[i]->calculateInterest() << endl;
    }

    // Освобождаем память
    for (int i = 0; i < 2; ++i) {
        delete accounts[i];
    }

    return 0;
}



//12

#include <iostream>
#include <cmath> // Для M_PI
using namespace std;

// Абстрактный класс Shape
class Shape {
public:
    virtual double area() const = 0;      // Мнимая площадь
    virtual double perimeter() const = 0; // Мнимая периметр
    virtual ~Shape() {}                   // Виртуальный деструктор
};

// Класс Rectangle
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
};

// Класс Circle
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

int main() {
    // Массив указателей на Shape
    Shape* shapes[2];
    shapes[0] = new Rectangle(3.0, 4.0);
    shapes[1] = new Circle(5.0);

    // Вывод результатов
    for (int i = 0; i < 2; ++i) {
        cout << "Shape " << i+1 << " area: " << shapes[i]->area() << endl;
        cout << "Shape " << i+1 << " perimeter: " << shapes[i]->perimeter() << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}


//13

#include <iostream>
using namespace std;

// Абстрактный класс Media
class Media {
public:
    virtual void play() = 0; // Чистый виртуальный метод
    virtual ~Media() {} // Виртуальный деструктор
};

// Класс Audio
class Audio : public Media {
public:
    void play() override {
        cout << "Playing audio..." << endl;
    }
};

// Класс Video
class Video : public Media {
public:
    void play() override {
        cout << "Playing video..." << endl;
    }
};

int main() {
    // Массив указателей на Media
    Media* medias[2];

    medias[0] = new Audio();
    medias[1] = new Video();

    // Вызов метода play()
    for (int i = 0; i < 2; ++i) {
        medias[i]->play();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete medias[i];
    }

    return 0;
}

//14


#include <iostream>
using namespace std;

// Абстрактный класс Notification
class Notification {
public:
    virtual void notify() = 0; // Чистый виртуальный метод
    virtual ~Notification() {} // Виртуальный деструктор
};

// Класс Push
class Push : public Notification {
public:
    void notify() override {
        cout << "Sending push notification..." << endl;
    }
};

// Класс EmailNotification
class EmailNotification : public Notification {
public:
    void notify() override {
        cout << "Sending email notification..." << endl;
    }
};

int main() {
    // Массив указателей на Notification
    Notification* notifications[2];

    notifications[0] = new Push();
    notifications[1] = new EmailNotification();

    // Вызов notify() для каждого уведомления
    for (int i = 0; i < 2; ++i) {
        notifications[i]->notify();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete notifications[i];
    }

    return 0;
}


//15

#include <iostream>
using namespace std;

// Абстрактный класс Robot
class Robot {
public:
    virtual void work() = 0; // Чистый виртуальный метод
    virtual ~Robot() {}      // Виртуальный деструктор
};

// Класс CleanerRobot
class CleanerRobot : public Robot {
public:
    void work() override {
        cout << "CleanerRobot is cleaning the room." << endl;
    }
};

// Класс BuilderRobot
class BuilderRobot : public Robot {
public:
    void work() override {
        cout << "BuilderRobot is constructing a building." << endl;
    }
};

int main() {
    // Массив указателей на Robots
    Robot* robots[2];
    robots[0] = new CleanerRobot();
    robots[1] = new BuilderRobot();

    // Вызов work() для каждого робота
    for (int i = 0; i < 2; ++i) {
        robots[i]->work();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete robots[i];
    }

    return 0;
}

//16

#include <iostream>
using namespace std;

// Интерфейс Flyable
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {} // Виртуальный деструктор
};

// Интерфейс Swimmable
class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() {}
};

// Класс Duck, реализующий оба интерфейса
class Duck : public Flyable, public Swimmable {
public:
    void fly() override {
        cout << "Утка летает " << endl;
    }

    void swim() override {
        cout << "Утка плавает " << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russia");
    Duck duck;

    duck.fly();  // Вызов метода fly()
    duck.swim(); // Вызов метода swim()

    return 0;
}

//17

#include <iostream>
#include <fstream>
using namespace std;

// Абстрактный класс Logger
class Logger {
public:
    virtual void log(const string& message) = 0; // Чистый виртуальный метод
    virtual ~Logger() {}
};

// Класс FileLogger
class FileLogger : public Logger {
    ofstream logFile;
public:
    FileLogger(const string& filename) {
        logFile.open(filename, ios::app);
        if (!logFile.is_open()) {
            cerr << "Failed to open log file." << endl;
        }
    }
    void log(const string& message) override {
        if (logFile.is_open()) {
            logFile << message << endl;
        }
    }
    ~FileLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

// Класс ConsoleLogger
class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        cout << "Console log: " << message << endl;
    }
};

int main() {
    // Создаём логеры
    Logger* fileLogger = new FileLogger("log.txt");
    Logger* consoleLogger = new ConsoleLogger();

    // Логируем сообщение
    fileLogger->log("Logging to a file.");
    consoleLogger->log("Logging to console.");

    // Освобождаем память
    delete fileLogger;
    delete consoleLogger;

    return 0;
}

//18

#include <iostream>
using namespace std;

// Абстрактный класс Delivery
class Delivery {
public:
    virtual void deliver() = 0; // Чистый виртуальный метод
    virtual ~Delivery() {}
};

// Класс Courier
class Courier : public Delivery {
public:
    void deliver() override {
        cout << "Courier is delivering the package on foot." << endl;
    }
};

// Класс Drone
class Drone : public Delivery {
public:
    void deliver() override {
        cout << "Drone is delivering the package by air." << endl;
    }
};

int main() {
    // Массив указателей на Delivery
    Delivery* deliveries[2];

    deliveries[0] = new Courier();
    deliveries[1] = new Drone();

    // Вызов deliver()
    for (int i = 0; i < 2; ++i) {
        deliveries[i]->deliver();
    }

    // Освобождение памяти
    for (int i = 0; i < 2; ++i) {
        delete deliveries[i];
    }

    return 0;
}



//19

#include <iostream>
using namespace std;

// Абстрактный класс Course
class Course {
public:
    virtual void start() = 0; // Чистый виртуальный метод
    virtual ~Course() {}       // Виртуальный деструктор
};

// Онлайн-курс
class OnlineCourse : public Course {
public:
    void start() override {
        cout << "Онлайн-курс начат." << endl;
    }
};

// Офлайн-курс
class OfflineCourse : public Course {
public:
    void start() override {
        cout << "Офлайн-курс начат." << endl;
    }
};

int main() {
    // Создаем объекты
    Course* online = new OnlineCourse();
    Course* offline = new OfflineCourse();

    // Запускаем курсы
    online->start();
    offline->start();

    // Освобождаем память
    delete online;
    delete offline;

    return 0;
}


// 20


#include <iostream>
#include <vector>
using namespace std;

// Абстрактный класс Product
class Product {
public:
    virtual double getPrice() const = 0; // Чистый виртуальный метод
    virtual ~Product() {}
};

// Класс Book
class Book : public Product {
    double price;
public:
    Book(double p) : price(p) {}
    double getPrice() const override {
        return price;
    }
};

// Класс Electronics
class Electronics : public Product {
    double price;
public:
    Electronics(double p) : price(p) {}
    double getPrice() const override {
        return price;
    }
};

// Класс Clothing
class Clothing : public Product {
    double price;
public:
    Clothing(double p) : price(p) {}
    double getPrice() const override {
        return price;
    }
};

int main() {
    // Создаем массив указателей на базовый класс, содержащий разные товары
    vector<Product*> products;

    // Заполняем массив товарами
    products.push_back(new Book(12.99));
    products.push_back(new Electronics(199.99));
    products.push_back(new Clothing(39.50));
    products.push_back(new Book(7.49));
    products.push_back(new Electronics(549.00));
    products.push_back(new Clothing(89.99));

    // 1. Вывод цен всех товаров
    cout << "Цены товаров:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        cout << "Товар " << i+1 << ": " << products[i]->getPrice() << " рублей" << endl;
    }

    // 2. Подсчет общей суммы
    double total = 0;
    for (size_t i = 0; i < products.size(); ++i) {
        total += products[i]->getPrice();
    }

    cout << "Общая сумма: " << total << " рублей" << endl;

    // Очистка памяти
    for (size_t i = 0; i < products.size(); ++i) {
        delete products[i];
    }

    return 0;
}

