1
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
