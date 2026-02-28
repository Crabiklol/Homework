//1
#include <iostream>

int main() {
    int value = 42;
    int* ptr = &value;

    if (ptr != nullptr && *ptr > 0) {
        std::cout << "Указатель не нулевой, значение положительное: " << *ptr << std::endl;
    } else {
        std::cout << "Условие не выполнено" << std::endl;
    }

    return 0;
}
//2
int* ptr = nullptr;
if (ptr != nullptr && *ptr > 0) {  // *ptr не будет разыменовано!
    std::cout << *ptr << std::endl;
}
//3
#include <iostream>

int main() {
    int a = 5, b = -3, c = 10;
    int* arr[] = {&a, nullptr, &b, &c, nullptr};
    int size = 5;

    for (int i = 0; i < size; ++i) {
        if (arr[i] != nullptr && *arr[i] > 0) {
            std::cout << *arr[i] << " ";
        }
    }
    std::cout << std::endl;  // Выведет: 5 10

    return 0;
}
//4
int* ptr = nullptr;
if (ptr != nullptr & *ptr > 0) {  // ОШИБКА: *ptr будет разыменовано!
    std::cout << *ptr << std::endl;
}
//5
#include <iostream>

void changeByValue(int x) {
    x = 100;  // Изменяется локальная копия
    std::cout << "Внутри функции: " << x << std::endl;
}

int main() {
    int num = 42;
    changeByValue(num);
    std::cout << "После вызова: " << num << std::endl;  // 42 (не изменилось)
    return 0;
}
//6
void changeByReference(int& x) {
    x = 100;
}
void changeByPointer(int* x) {
    *x = 100;
}
//7
int main() {
    int num = 42;

    changeByValue(num);           // num = 42
    changeByReference(num);       // num = 100
    changeByPointer(&num);        // num = 100

    std::cout << num << std::endl;  // 100
    return 0;
}
 //8
void incrementArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]++;
    }
}

void incrementArrayRef(int (&arr)[5]) {  // Размер фиксирован
    for (int& elem : arr) {
        elem++;
    }
}

int data[5] = {1, 2, 3, 4, 5};
incrementArray(data, 5);        // Через указатель
incrementArrayRef(data);     // Через ссылку

//9
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//10
void tryToModify(const int* arr) {
    // arr[0] = 10;  // ОШИБКА компиляции!
    // *arr = 10;     // ОШИБКА компиляции!
}

//11

int (*funcPtr)(int, int);

//12
int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

//13
funcPtr = max;
std::cout << funcPtr(5, 3) << std::endl;  // 5

funcPtr = min;
std::cout << funcPtr(5, 3) << std::endl;  // 3

//14
int compareAndReturn(int a, int b, int (*cmp)(int, int)) {
    return cmp(a, b);
}

// Использование:
std::cout << compareAndReturn(10, 5, max) << std::endl;  // 10
std::cout << compareAndReturn(10, 5, min) << std::endl;  // 5

//15
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}

using FuncType = int(*)(int, int);  // Тип указателя на функцию
FuncType operations[4] = {add, subtract, multiply, divide};

//16
int calculate(int a, int b, int opIndex) {
    if (opIndex < 0 || opIndex > 3) {
        throw std::out_of_range("Invalid operation index!");
    }
    return operations[opIndex](a, b);
}

// Использование:
std::cout << calculate(10, 2, 0) << std::endl;  // 12 (add)
std::cout << calculate(10, 2, 3) << std::endl;  // 5 (divide)

//17
typedef int(*Operation)(int);

Operation getOperation(bool increase) {
    if (increase) {
        return [](int x) -> int { return x + 1; };
    } else {
        return [](int x) -> int { return x - 1; };
    }
}

// Использование:
Operation op = getOperation(true);
std::cout << op(5) << std::endl;  // 6

//18
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    // auto автоматически выводит тип указателя на функцию
    auto funcPtr = add;
    
    std::cout << funcPtr(3, 4) << std::endl;  // 7

    return 0;
}

//19
#include <iostream>
#include <vector>
#include <functional>

// Функция, которая применяет переданную операцию к каждому элементу вектора
void applyOperation(
    std::vector<int>& data,
    std::function<int(int)> operation  // Можно использовать std::function
) {
    for (auto& elem : data) {
        elem = operation(elem);
    }
}

// Пример операции: удвоение числа
int doubleValue(int x) {
    return x * 2;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Передаём указатель на функцию doubleValue
    applyOperation(numbers, doubleValue);

    for (int num : numbers) {
        std::cout << num << " ";  // 2 4 6 8 10
    }
    std::cout << std::endl;

    return 0;
}

applyOperation(numbers, [](int x) { return x + 1; });

//20
#include <iostream>
#include <vector>

// Прототипы функций меню
void showHelp() {
    std::cout << "Доступные команды:\n";
    std::cout << "  0 — Помощь\n";
    std::cout << "  1 — Сложить два числа\n";
    std::cout << "  2 — Вычесть два числа\n";
    std::cout << "  3 — Умножить два числа\n";
    std::cout << "  4 — Выйти\n";
}

void addNumbers() {
    int a, b;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;
    std::cout << "Сумма: " << (a + b) << std::endl;
}

void subtractNumbers() {
    int a, b;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;
    std::cout << "Разность: " << (a - b) << std::endl;
}

void multiplyNumbers() {
    int a, b;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;
    std::cout << "Произведение: " << (a * b) << std::endl;
}

void exitProgram() {
    std::cout << "До свидания!" << std::endl;
}

// Тип указателя на функцию меню
using MenuFunc = void(*)();

// Массив функций меню
std::vector<MenuFunc> menuFunctions = {
    showHelp,
    addNumbers,
    subtractNumbers,
    multiplyNumbers,
    exitProgram
};

int main() {
    int choice;

    do {
        std::cout << "\nВыберите действие (0–4): ";
        std::cin >> choice;

        if (choice >= 0 && choice < menuFunctions.size()) {
            menuFunctions[choice]();  // Вызов функции по индексу
        } else {
            std::cout << "Неверный ввод. Попробуйте снова." << std::endl;
        }

    } while (choice != 4);  // Выход при выборе 4

    return 0;
}

