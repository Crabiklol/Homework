//1
#include <iostream>


inline int square(int num) {
    return num * num;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int number = 5;
    std::cout << "Квадрат числа " << number << " равен " << square(number) << std::endl;

    return 0;
}

//2
#include <iostream>

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL ,"Russian");
    int num1 = 10;
    int num2 = 20;

    std::cout << "Максимум из " << num1 << " и " << num2
        << " равен " << max(num1, num2) << std::endl;

    return 0;
}

//3
#include <iostream>


inline int abs_number(int num) {
    return (num < 0) ? -num : num;
}

int main() {
    
    std::cout << abs_number(-5) << std::endl;  
    std::cout << abs_number(10) << std::endl;   
    std::cout << abs_number(0) << std::endl;   

    return 0;
}

//4
#include <iostream>


inline bool isPositive(int number) {
    return number > 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num = 10;

    
    if (isPositive(num)) {
        std::cout << "Число положительное" << std::endl;
    }
    else {
        std::cout << "Число не положительное" << std::endl;
    }

    return 0;
}

//5 
#include <iostream>


inline int sum(int a, int b) {
    return a + b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int result = sum(5, 3);
    std::cout << "Сумма чисел: " << result << std::endl;  // Выведет: 8

    return 0;
}

//6
#include <iostream>


inline double average(double a, double b) {
    return (a + b) / 2.0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double num1 = 5.5;
    double num2 = 10.5;

    std::cout << "Среднее арифметическое: " << average(num1, num2) << std::endl;

    return 0;
}

//7 
#include <iostream>

inline bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num;

    std::cout << "Введите число: ";
    std::cin >> num;

    if (isEven(num)) {
        std::cout << num << " - чётное число\n";
    }
    else {
        std::cout << num << " - нечётное число\n";
    }

    return 0;
}
//8
#include <iostream>


inline int minOfThree(int a, int b, int c) {
   
    return (a <= b && a <= c) ? a :
        (b <= c) ? b : c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num1 = 10;
    int num2 = 5;
    int num3 = 8;


    std::cout << "Минимальный элемент: " << minOfThree(num1, num2, num3) << std::endl;

    return 0;
}
//9
#include <iostream>


inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
  
    int num1 = 10;
    int num2 = 20;

    std::cout << "Большее число: " << max(num1, num2) << std::endl;  

    return 0;
}
//10
#include <iostream>


inline int perimeter(int a, int b) {
    return 2 * (a + b);
}

int main() {
    setlocale(LC_ALL, "Russian");
   
    int side1 = 5;
    int side2 = 7;

    std::cout << "Периметр прямоугольника: " << perimeter(side1, side2) << std::endl;

    return 0;
}
//11
