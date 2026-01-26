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
#include <iostream>

inline int sumElements(const int* arr, int index1, int index2) {
   
    return arr[index1] + arr[index2];
}


int main() {
    const int size = 5;
    int array[size] = { 1, 2, 3, 4, 5 };

    
    int result = sumElements(array, 0, 2); 
    std::cout << "Сумма элементов: " << result << std::endl; 

    return 0;
}

//15
#include <iostream>
using namespace std;


inline int absInt(int x) {
    return (x < 0) ? -x : x;
}


inline double absDouble(double x) {
    return (x < 0) ? -x : x;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int number1 = -42;
    cout << "Модуль числа " << number1 << " равен " << absInt(number1) << endl;

   
    double number2 = -3.14159;
    cout << "Модуль числа " << number2 << " равен " << absDouble(number2) << endl;

    return 0;
}

//16
#include <iostream>


inline double maxOfThree(double a, double b, double c) {
    return (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double num1 = 5.5;
    double num2 = 8.2;
    double num3 = 3.7;

    double result = maxOfThree(num1, num2, num3);
    std::cout << "Максимальное число: " << result << std::endl;

    return 0;
}

//17
#include <iostream>


inline double squareArea(double side) {
    return side * side; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    double side = 5.0;
    double area = squareArea(side);

    std::cout << "Площадь квадрата со стороной " << side << " равна " << area << std::endl;

    return 0;
}

//18
#include <iostream>


inline bool isInRange(int number, int start, int end) {
    return (number >= start && number <= end);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num = 10;
    int rangeStart = 5;
    int rangeEnd = 15;

    if (isInRange(num, rangeStart, rangeEnd)) {
        std::cout << "Число " << num << " находится в диапазоне [" << rangeStart << ", " << rangeEnd << "]\n";
    }
    else {
        std::cout << "Число " << num << " не находится в диапазоне\n";
    }

    return 0;
}


