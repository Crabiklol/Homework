//1 2 3
#include <iostream>
#include <string>

enum class AnimalType { Dog, Cat, Bird };

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
};

class Dog : public Animal { public: void speak() const override { std::cout << "Woof!\n"; } };
class Cat : public Animal { public: void speak() const override { std::cout << "Meow!\n"; } };
class Bird : public Animal { public: void speak() const override { std::cout << "Tweet!\n"; } };

class AnimalFactory {
public:
    static Animal* create(AnimalType type) {
        switch (type) {
        case AnimalType::Dog:  return new Dog();
        case AnimalType::Cat:  return new Cat();
        case AnimalType::Bird: return new Bird(); // Задание 3
        default: return nullptr;
        }
    }
};
int main() {
    Animal* a = AnimalFactory::create(AnimalType::Dog);
    if (a) {
        a->speak();   // Задание 2
        delete a;     // Освобождение памяти (в Задании 20 заменим на unique_ptr)
    }
}

//4

Animal* createManually(int t) {
    if (t == 0) return new Dog();
    if (t == 1) return new Cat();
    return nullptr;
}

//5
Animal* ptr = AnimalFactory::create(static_cast<AnimalType>(99));
if (ptr) {
    ptr->speak();
    delete ptr;
} else {
    std::cerr << "Ошибка: неизвестный тип животного\n";
}


//6
class Transport { public: virtual ~Transport() = default; virtual void move() const = 0; };
class Car : public Transport { public: void move() const override { std::cout << "Driving\n"; } };
class Bike : public Transport { public: void move() const override { std::cout << "Pedaling\n"; } };

class TransportFactory {
public:
    static Transport* create(const std::string& type) {
        if (type == "car") return new Car();
        if (type == "bike") return new Bike();
        return nullptr;
    }
};

//7
class Payment { public: virtual ~Payment() = default; virtual void pay(double) const = 0; };
class Card : public Payment { public: void pay(double) const override { std::cout << "Card paid\n"; } };
class Cash : public Payment { public: void pay(double) const override { std::cout << "Cash paid\n"; } };

class PaymentFactory {
public:
    static Payment* create(const std::string& method) {
        return method == "card" ? new Card() : (method == "cash" ? new Cash() : nullptr);
    }
};

//8
class Document { public: virtual ~Document() = default; virtual void open() const = 0; };
class PdfDoc : public Document { public: void open() const override { std::cout << "PDF opened\n"; } };
class DocDoc : public Document { public: void open() const override { std::cout << "DOC opened\n"; } };

class DocFactory {
public:
    static Document* create(const std::string& ext) {
        if (ext == "pdf") return new PdfDoc();
        if (ext == "doc") return new DocDoc();
        return nullptr;
    }
};

//9
class LogicObj { public: virtual ~LogicObj() = default; virtual void exec() const = 0; };
class A : public LogicObj { public: void exec() const override { std::cout << "Range A\n"; } };
class B : public LogicObj { public: void exec() const override { std::cout << "Range B\n"; } };

class LogicFactory {
public:
    static LogicObj* create(int val) {
        if (val < 10) return new A();
        if (val == 10) return new B();
        return nullptr; // или выбросить std::invalid_argument
    }
};

//10
class Unit { public: virtual ~Unit() = default; virtual void status() const = 0; };
class Basic : public Unit { public: void status() const override { std::cout << "Basic\n"; } };
class Elite : public Unit { public: void status() const override { std::cout << "Elite\n"; } };

class UnitFactory {
public:
    static Unit* create(int type, int level) {
        if (type == 1 && level >= 10) return new Elite();
        return new Basic();
    }
};

//11 12
class Product { public: virtual ~Product() = default; virtual void action() const = 0; };
class DogP : public Product { public: void action() const override { std::cout << "Dog action\n"; } };
class CatP : public Product { public: void action() const override { std::cout << "Cat action\n"; } };

class Creator {
public:
    virtual ~Creator() = default;
    virtual Product* create() const = 0; // Чистый виртуальный метод
};

class DogFactory : public Creator {
public: Product* create() const override { return new DogP(); }
};
class CatFactory : public Creator {
public: Product* create() const override { return new CatP(); }
};

//13
std::unique_ptr<Creator> factory = std::make_unique<DogFactory>();
std::unique_ptr<Product> prod(factory->create());
prod->action();

//14

class BirdP : public Product { public: void action() const override { std::cout << "Bird action\n"; } };
class BirdFactory : public Creator {
public: Product* create() const override { return new BirdP(); }
};


//16
class Enemy { public: virtual ~Enemy() = default; virtual void attack() const = 0; };
class Zombie : public Enemy { public: void attack() const override { std::cout << "Bite\n"; } };
class Vampire : public Enemy { public: void attack() const override { std::cout << "Drain life\n"; } };

//17
class Widget { public: virtual ~Widget() = default; virtual void render() const = 0; };
class Button : public Widget { public: void render() const override { std::cout << "[Button]\n"; } };
class TextBox : public Widget { public: void render() const override { std::cout << "[_TextBox]\n"; } };

//18
class Message { public: virtual ~Message() = default; virtual void send(const std::string& to) const = 0; };
class Email : public Message { public: void send(const std::string&) const override { std::cout << "📧 Sent\n"; } };
class SMS : public Message { public: void send(const std::string&) const override { std::cout << "📱 Sent\n"; } };

//19
class IContainer {
public:
    virtual ~IContainer() = default;
    virtual void add(int val) = 0;
    virtual void print() const = 0;
};

class VectorWrap : public IContainer {
    std::vector<int> data;
public:
    void add(int v) override { data.push_back(v); }
    void print() const override { for (int x : data) std::cout << x << ' '; std::cout << '\n'; }
};

class ListWrap : public IContainer {
    std::list<int> data;
public:
    void add(int v) override { data.push_back(v); }
    void print() const override { for (int x : data) std::cout << x << ' '; std::cout << '\n'; }
};

class ContainerFactory {
public:
    static std::unique_ptr<IContainer> create(const std::string& type) {
        if (type == "vector") return std::make_unique<VectorWrap>();
        if (type == "list")   return std::make_unique<ListWrap>();
        return nullptr;
    }
};

//20
#include <memory>

class AnimalFactoryModern {
public:
    static std::unique_ptr<Animal> create(AnimalType type) {
        switch (type) {
            case AnimalType::Dog:  return std::make_unique<Dog>();
            case AnimalType::Cat:  return std::make_unique<Cat>();
            case AnimalType::Bird: return std::make_unique<Bird>();
            default: return nullptr;
        }
    }
};

// Использование:
auto animal = AnimalFactoryModern::create(AnimalType::Cat);
animal->speak(); 
