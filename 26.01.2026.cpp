//1
#include <iostream>
using namespace std;


int sum(int a, int b) {
    return a + b;
}


int sum(int a, int b, int c) {
    return a + b + c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Сумма двух чисел: " << sum(2, 3) << endl;  

   
    cout << "Сумма трёх чисел: " << sum(1, 2, 3) << endl; 

    return 0;
}

//2
#include <iostream>
using namespace std;


void print(int number) {
    cout << "Целое число: " << number << endl;
}


void print(double number) {
    cout << "Вещественное число: " << number << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    print(42);


    print(3.14);

    return 0;
}

//3
int max(int num1, int num2) {
    if (num1 > num2)
        return num1;
    return num2;
}


double max(double num1, double num2) {  
    if (num1 > num2)  
        return num1;  
    return num2;  
}  


//4
