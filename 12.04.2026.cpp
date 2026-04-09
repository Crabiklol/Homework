//1
#define PI 3.141592653589793
#include <iostream>

int main() {
    std::cout << "PI = " << PI << std::endl;
    return 0;
}

//2
#define SUM(a, b) ((a) + (b))

int main() {
    std::cout << "Sum 3+4 = " << SUM(3, 4) << std::endl;
}

//3
// Без скобок
#define MULTIPLY(a, b) a * b

int main() {
    int result = MULTIPLY(2+3, 4+1); // Ожидаемое 5 * 5 = 25, но получим 2+3*4+1 = 2+12+1=15
    std::cout << "Result: " << result << std::endl;
}

#define MULTIPLY(a, b) ((a) * (b))

//4
#define SQUARE(x) ((x) * (x))

//5
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//6
#ifdef DEBUG
#define DEBUG_LOG(x) std::cout << "DEBUG: " << x << std::endl
#else
#define DEBUG_LOG(x)
#endif

//7
#ifdef DEBUG
std::cout << "Debug mode ON" << std::endl;
#endif

//8
#ifndef RELEASE
std::cout << "RELEASE is not defined" << std::endl;
#endif

//9
#define VERSION 1

#if VERSION == 1
std::cout << "v1" << std::endl;
#else
std::cout << "other version" << std::endl;
#endif

//10
// файл myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

// содержимое файла

#endif // MYHEADER_H

//11
#define LOG(x) std::cerr << __FILE__ << ":" << __LINE__ << ": " << x << std::endl

//12
#define PRINT(x) std::cout << #x << " = " << x << std::endl

//13
#define CONCATENATE(a, b) a##b
#define CREATE_VAR(name, num) CONCATENATE(name, _##num)

// Пример использования:
int CREATE_VAR(var, 1) = 10; // создаст переменную var_1

//14
#define STRINGIFY(x) #x
// Пример:
const char* str = STRINGIFY(hello); // "hello"

//15
#define CHECK(x) \
    do { \
        if (!(x)) { \
            std::cerr << "Check failed: " << #x << " in " << __FILE__ << ":" << __LINE__ << std::endl; \
        } \
    } while (0)

//16
#define SAFE_DELETE(p) { if (p) { delete p; p = nullptr; } }

