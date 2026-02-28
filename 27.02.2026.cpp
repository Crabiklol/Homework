//1
#include <iostream>

int sumDigits(int n) {
    // Базовый случай: если число однозначное
    if (n < 10) {
        return n;
    }
    // Рекурсивный случай: последняя цифра + сумма цифр оставшейся части
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int number = 12345;
    std::cout << "Сумма цифр: " << sumDigits(number) << std::endl;  // 15
    return 0;
}

//2
#include <iostream>

int countEven(const int* arr, int size) {
    // Базовый случай: массив пуст
    if (size == 0) {
        return 0;
    }
    // Рекурсивный случай: проверяем последний элемент и рекурсивно обрабатываем остаток
    int isEven = (arr[size - 1] % 2 == 0) ? 1 : 0;
    return isEven + countEven(arr, size - 1);
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    std::cout << "Чётных чисел: " << countEven(data, size) << std::endl;  // 3
    return 0;
}

//4
#include <iostream>
#include <cstdarg>

double average(int count, ...) {
    va_list args;
    va_start(args, count);

    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, double);
    }

    va_end(args);
    return sum / count;
}

int main() {
    std::cout << "Среднее: " << average(4, 1.5, 2.5, 3.0, 4.0) << std::endl;  // 2.75
    return 0;
}

//6
int main() {
    int value = 42;
    int* ptr = &value;  // Присваиваем адрес переменной
    *ptr = 100;       // Меняем значение через указатель
    std::cout << value << std::endl;  // 100
    return 0;
}

//7
int a = 10;
int* p = &a;
(*p)++;
std::cout << a;  // Выведет: 11

//9
void f(int) { /* ... */ }
void f(char*) { /* ... */ }

f(NULL);  // Ошибка: неоднозначный вызов!
f(nullptr); // Вызов f(char*)

//10
int arr[3] = {1, 2, 3};
int* p = arr;
std::cout << *(p + 1);  // Выведет: 2

//12
const int* p1 = &x; p1++; // OK, *p1 = 5; // Ошибка
int* const p2 = &x; p2++; // Ошибка, *p2 = 5; // OK
const int* const p3 = &x; // Ни p3, ни *p3 менять нельзя

//13
#include <iostream>

int main() {
    int size = 5;
    int* arr = new int[size];  // Выделение памяти


    // Заполнение массива
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    // Вывод
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;  // Освобождение памяти
    return 0;
}

//15
// Передача по значению
void incByValue(int x) {
    x++;  // Изменяется локальная копия
}

// Передача по ссылке
void incByReference(int& x) {
    x++;  // Изменяется исходная переменная
}

// Передача по указателю
void incByPointer(int* x) {
    (*x)++;  // Изменяется значение по адресу
}

//16
int main() {
    int value = 5;

    incByValue(value);      // value = 5 (не изменилось)
    incByReference(value); // value = 6 (изменилось)
    incByPointer(&value);   // value = 7 (изменилось)

    std::cout << value << std::endl;  // 7
    return 0;
}

//17
// Синтаксис: тип_возврата (*имя_указателя)(параметры)
double (*operation)(double, double);

//18
#include <iostream>

double add(double a, double b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

int main() {
    double (*op)(double, double);

    op = add;
    std::cout << "5 + 3 = " << op(5, 3) << std::endl;  // 8


    op = multiply;
    std::cout << "5 * 3 = " << op(5, 3) << std::endl;  // 15

    return 0;
}

//19
#include <iostream>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}

int main() {
    // Массив указателей на функции
    double (*operations[4])(double, double) = {add, subtract, multiply, divide};

    double x = 10, y = 2;
    char signs[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; ++i) {
        try {
            std::cout << x << " " << signs[i] << " " << y << " = " 
                     << operations[i](x, y) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}

//20
#include <iostream>
#include <vector>

// Тип указателя на функцию обработки элемента
using ElementProcessor = void(*)(int&);

// Функция применяет processor к каждому элементу массива
void processArray(int* arr, int size, ElementProcessor processor) {
    for (int i = 0; i < size; ++i) {
        processor(arr[i]);
    }
}

// Примеры операций
void square(int& x) {
    x = x * x;
}

void increment(int& x) {
    x++;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = 5;

    // Увеличиваем каждый элемент на 1
    processArray(data, size, increment);
    // Теперь data = {2, 3, 4, 5, 6}

    // Возводим в квадрат
    processArray(data, size, square);
    // Теперь data = {4, 9, 16, 25, 36}

    // Вывод результата
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;  // 4 9 16 25 36

    return 0;
}
