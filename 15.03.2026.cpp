//1
#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;
};

int main() {
    setlocale(LC_ALL, "Russian");
    Book myBook;
    myBook.title = "1984";
    myBook.author = "George Orwell";
    myBook.pages = 328;

    cout << "Книга: " << myBook.title << endl;
    cout << "Автор: " << myBook.author << endl;
    cout << "Страниц: " << myBook.pages << endl;

    return 0;
}

//2
#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    void displayInfo() {
        cout << "Книга: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Страниц: " << pages << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Book myBook;
    myBook.title = "1984";
    myBook.author = "George Orwell";
    myBook.pages = 328;

    myBook.displayInfo();
    return 0;
}

//3
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
public:
    Student(const string& n, int a) : name(n), age(a) {}

    void display() {
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Student student("Иван", 20);
    student.display();
    return 0;
}

//4
#include <iostream>

using namespace std;

class Car {
private:
    int speed;
public:
    void setSpeed(int s) {
        if (s >= 0)
            speed = s;
        else
            cout << "Некорректная скорость" << endl;
    }
    int getSpeed() {
        return speed;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Car myCar;
    myCar.setSpeed(60);
    cout << "Моя скорость: " << myCar.getSpeed() << endl;

    myCar.setSpeed(-10); // Некорректный случай
    return 0;
}
//5
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}
    void display() {
        cout << "Имя: " << name << ", Возраст: " << age << endl;
    }
};

class Employee : public Person {
private:
    string position;
public:
    Employee(const string& n, int a, const string& pos)
        : Person(n, a), position(pos) {
    }

    void display() {
        Person::display();
        cout << "Должность: " << position << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Employee emp("Иван", 30, "Программист");
    emp.display();
    return 0;
}

//7
#include <iostream>

using namespace std;

class Point {
public:
    int x, y;

    Point() : x(0), y(0) {} // конструктор по умолчанию

    void display() const {
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Point p;
    p.display();
    return 0;
}

//8
#include <iostream>

using namespace std;

class Point {
public:
    int x, y;
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
    void display() const {
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Point p(5, 10);
    p.display();
    return 0;
}

//9
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int balance;
    string accountNumber;
public:
    BankAccount(const string& accNum, int initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
    }

    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Недостаточно средств или неправильная сумма!" << endl;
    }

    void display() const {
        cout << "Счёт: " << accountNumber << ", Баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    BankAccount myAccount("12345678", 1000);
    myAccount.deposit(500);
    myAccount.withdraw(300);
    myAccount.display();
    return 0;
}

//10
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;
};

void changeName(Student& s, const string& newName) {
    s.name = newName;
}

int main() {
    setlocale(LC_ALL, "RUssian");
    Student s1, s2;
    s1.name = "Ivan";
    s2.name = "Anna";

    changeName(s1, "Alex");
    cout << "Имя первого студента: " << s1.name << endl;

    return 0;
}

//11
#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(const string& n) : name(n) {}
    void display() const {
        cout << "Имя животного: " << name << endl;
    }
};

class Dog : public Animal {
private:
    string breed;
public:
    Dog(const string& n, const string& br) : Animal(n), breed(br) {}
    void display() const {
        Animal::display();
        cout << "Порода: " << breed << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Dog myDog("ТЯПО", "Мальтийская болонка");
    myDog.display();
    return 0;
}

//12
#include <iostream>

using namespace std;

class Rectangle {
public:
    double length;
    double width;

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Rectangle rect;
    rect.length = 5;
    rect.width = 3;

    cout << "Площадь: " << rect.area() << endl;
    cout << "Периметр: " << rect.perimeter() << endl;

    return 0;
}

//13
#include <iostream>

using namespace std;

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}
    void increment() { count++; }
    int getCount() const { return count; }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Counter c;
    c.increment();
    c.increment();
    c.increment();
    cout << "Значение счетчика: " << c.getCount() << endl;
    return 0;
}

//14
#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
public:
    virtual void fuelEfficiency() const {
        cout << "Общая эффективность топлива" << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void fuelEfficiency() const override {
        cout << "Легковая машина: расход 8 литров на 100 км" << endl;
    }
};

class Truck : public Vehicle {
public:
    void fuelEfficiency() const override {
        cout << "Грузовик: расход 20 литров на 100 км" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car());
    vehicles.push_back(new Truck());

    for (auto v : vehicles) {
        v->fuelEfficiency();
    }

    // Освобождение памяти
    for (auto v : vehicles) {
        delete v;
    }

    return 0;
}

//15
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    Book(const string& t, const string& a, int p)
        : title(t), author(a), pages(p) {
    }
    void display() const {
        cout << "Книга: " << title << ", Автор: " << author << ", Страниц: " << pages << endl;
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void showBooks() const {
        for (const auto& b : books) {
            b.display();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Library lib;
    lib.addBook(Book("1984", "George Orwell", 328));
    lib.addBook(Book("Brave New World", "Aldous Huxley", 268));

    cout << "Все книги в библиотеке:" << endl;
    lib.showBooks();

    return 0;
}
