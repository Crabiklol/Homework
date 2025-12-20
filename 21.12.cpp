//1
#include <iostream>
using namespace std;


auto square(int number) -> int {
    return number * number;
}

int main() {
   
    int num = 5;
    int result = square(num);
    
    cout << "Квадрат числа " << num << " равен: " << result << endl;
    
   
    cout << "Квадрат 7: " << square(7) << endl;
    cout << "Квадрат 10: " << square(10) << endl;
    cout << "Квадрат 12: " << square(12) << endl;
    
    return 0;
}

//2
#include <iostream>
using namespace std;


auto findMin(int a, int b) -> int {
    return (a < b) ? a : b;
}

int main() {
   
    int x = 10, y = 7;

    cout << "Минимальное из " << x << " и " << y << " равно: "
        << findMin(x, y) << endl;

    cout << "Минимальное из 15 и 8: " << findMin(15, 8) << endl;
    cout << "Минимальное из -5 и 3: " << findMin(-5, 3) << endl;
    cout << "Минимальное из 25 и 25: " << findMin(25, 25) << endl;

   
    int num1, num2;

    cout << "\nВведите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Минимальное из " << num1 << " и " << num2
        << " равно: " << findMin(num1, num2) << endl;

    return 0;
}
//3
#include <iostream>
using namespace std;


int global = 10;

void myFunction() {

    int local = 20;
    cout << "Глобальная: " << global << endl;
    cout << "Локальная: " << local << endl;
}

int main() {
   
    myFunction();
    cout << "\nВ main: " << global << endl;
   

    return 0;
}
//4
#include <iostream>
using namespace std;

void counterFunction() {

    static int counter = 0;

    counter++;
    cout << "Функция вызвана " << counter << " раз(а)" << endl;
}

int main() {
    cout << "Вызываем функцию несколько раз:\n" << endl;

    counterFunction(); 
    counterFunction(); 
    counterFunction();
    counterFunction(); 
    counterFunction(); 

    return 0;
}
//5
#include <iostream>
using namespace std;


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
   
    int numbers[5] = { 10, 20, 30, 40, 50 };

    cout << "Массив чисел: ";
    printArray(numbers, 5);

    return 0;
}
//6
#include <iostream>
using namespace std;


int sum(int a, int b);

int main() {
    
    int result = sum(5, 3);
    cout << "Сумма: " << result << endl;

    result = sum(10, 20);
    cout << "Сумма: " << result << endl;

    result = sum(100, 200);
    cout << "Сумма: " << result << endl;

    return 0;
}


int sum(int a, int b) {
    return a + b;
}
//7
#include <iostream>
using namespace std;


void print3x3Array(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
 
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Массив 3x3:" << endl;
    print3x3Array(matrix);

    return 0;
}
//8
#include <iostream>
using namespace std;

void increaseByFive(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 5;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[5] = { 10, 20, 30, 40, 50 };

    cout << "Исходный массив: ";
    printArray(numbers, 5);

    
    increaseByFive(numbers, 5);

    cout << "После увеличения на 5: ";
    printArray(numbers, 5);

   
    cout << "\nЕще раз выводим массив: ";
    printArray(numbers, 5);

    return 0;
}
//10
#include <iostream>
using namespace std;


auto arraySum(int arr[], int size) -> int {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
   
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 10, 20, 30, 40, 50 };
    int arr3[] = { -5, 10, -3, 7, 0 };

    cout << "Сумма элементов массива {1,2,3,4,5}: "
        << arraySum(arr1, 5) << endl;

    cout << "Сумма элементов массива {10,20,30,40,50}: "
        << arraySum(arr2, 5) << endl;

    cout << "Сумма элементов массива {-5,10,-3,7,0}: "
        << arraySum(arr3, 5) << endl;

    return 0;
}
//11
#include <iostream>
using namespace std;


int countEvenNumbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {  
            count++;
        }
    }
    return count;
}

int main() {
   
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr2[] = { 11, 13, 15, 17, 19 };  
    int arr3[] = { 2, 4, 6, 8, 10 };       
    int arr4[] = { 0, -2, 5, -8, 10 };     

    cout << "Массив {1,2,3,4,5,6,7,8,9,10}: "
        << countEvenNumbers(arr1, 10) << " чётных" << endl;

    cout << "Массив {11,13,15,17,19}: "
        << countEvenNumbers(arr2, 5) << " чётных" << endl;

    cout << "Массив {2,4,6,8,10}: "
        << countEvenNumbers(arr3, 5) << " чётных" << endl;

    cout << "Массив {0,-2,5,-8,10}: "
        << countEvenNumbers(arr4, 5) << " чётных" << endl;

    return 0;
}
//12
#include <iostream>
using namespace std;


int sumMainDiagonal(int matrix[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += matrix[i][i];  
    }
    return sum;
}

int main() {
    
    int matrix1[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Сумма главной диагонали: " << sumMainDiagonal(matrix1) << endl;

    return 0;
}
//13
#include <iostream>
using namespace std;


double calculateAverage(int arr[], int size);

int main() {
   
    int numbers1[] = { 10, 20, 30, 40, 50 };
    int numbers2[] = { 5, 15, 25, 35, 45, 55 };
    int numbers3[] = { 2, 4, 6, 8, 10, 12, 14 };

   
    cout << "Среднее массива {10,20,30,40,50}: "
        << calculateAverage(numbers1, 5) << endl;

    cout << "Среднее массива {5,15,25,35,45,55}: "
        << calculateAverage(numbers2, 6) << endl;

    cout << "Среднее массива {2,4,6,8,10,12,14}: "
        << calculateAverage(numbers3, 7) << endl;

    return 0;
}


double calculateAverage(int arr[], int size) {
    
    if (size == 0) {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    
    return static_cast<double>(sum) / size;
}
//14
#include <iostream>
using namespace std;


int counter = 0;


void incrementCounter();
void displayCounter();

int main() {
    cout << "=== Программа с глобальным счётчиком ===\n" << endl;

  
    cout << "Начальное значение: ";
    displayCounter();

  
    cout << "\nУвеличиваем счетчик 3 раза:" << endl;
    incrementCounter();  
    incrementCounter(); 
    incrementCounter(); 

    
    cout << "После 3 увеличений: ";
    displayCounter();

   
    cout << "\nУвеличиваем еще 2 раза:" << endl;
    incrementCounter(); 
    incrementCounter();  

    
    cout << "После 5 увеличений: ";
    displayCounter();

   
    cout << "\nПрямой доступ из main: counter = " << counter << endl;

    return 0;
}


void incrementCounter() {
    counter++;
    cout << "Счетчик увеличен. Новое значение: " << counter << endl;
}


void displayCounter() {
    cout << "Текущее значение счетчика: " << counter << endl;
}
//15
#include <iostream>
using namespace std;


void fillArray(int(&arr)[6]) {
    
    for (int i = 0; i < 6; i++) {
        arr[i] = i + 1; 
    }
}

int main() {
    int myArray[6];  

    cout << "До вызова функции: ";
    for (int i = 0; i < 6; i++) {
        cout << myArray[i] << " ";  
    }

    
    fillArray(myArray);

    cout << "\nПосле вызова функции: ";
    for (int i = 0; i < 6; i++) {
        cout << myArray[i] << " ";
    }

    return 0;
}
//16
#include <iostream>
using namespace std;


void zeroBelowDiagonal(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > j) {  
                arr[i][j] = 0;
            }
        }
    }
}


void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Исходная матрица 3x3:" << endl;
    printMatrix(matrix);

  
    zeroBelowDiagonal(matrix);

    cout << "\nПосле замены элементов ниже диагонали на 0:" << endl;
    printMatrix(matrix);

    return 0;
}
//17
#include <iostream>
using namespace std;


auto findMaxIndex(int arr[], int size) -> int {
    if (size <= 0) return -1;  

    int maxIndex = 0;  

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i; 
        }
    }

    return maxIndex;
}

int main() {

    int arr1[] = { 5, 9, 3, 7, 2 };
    int arr2[] = { -10, -5, -20, -1, -8 };
    int arr3[] = { 100, 200, 150, 300, 250 };
    int arr4[] = { 7 };  

    cout << "Массив {5,9,3,7,2}: ";
    cout << "Индекс максимального: " << findMaxIndex(arr1, 5)
        << " (значение: " << arr1[findMaxIndex(arr1, 5)] << ")" << endl;

    cout << "Массив {-10,-5,-20,-1,-8}: ";
    cout << "Индекс максимального: " << findMaxIndex(arr2, 5)
        << " (значение: " << arr2[findMaxIndex(arr2, 5)] << ")" << endl;

    cout << "Массив {100,200,150,300,250}: ";
    cout << "Индекс максимального: " << findMaxIndex(arr3, 5)
        << " (значение: " << arr3[findMaxIndex(arr3, 5)] << ")" << endl;

    cout << "Массив {7}: ";
    cout << "Индекс максимального: " << findMaxIndex(arr4, 1)
        << " (значение: " << arr4[findMaxIndex(arr4, 1)] << ")" << endl;

    return 0;
}
//18
#include <iostream>
using namespace std;

// Глобальная переменная
int value = 100;

// Функция с локальной переменной того же имени
void demonstrateConflict() {
    // Локальная переменная с тем же именем, что и глобальная
    int value = 50;
    
    cout << "=== Внутри функции demonstrateConflict() ===" << endl;
    cout << "Локальная переменная value: " << value << endl;
    cout << "Глобальная переменная value: " << ::value << endl;
    
    // Изменяем локальную переменную
    value = 75;
    cout << "\nПосле изменения локальной переменной:" << endl;
    cout << "Локальная переменная value: " << value << endl;
    cout << "Глобальная переменная value: " << ::value << endl;
    
    // Изменяем глобальную переменную
    ::value = 200;
    cout << "\nПосле изменения глобальной переменной:" << endl;
    cout << "Локальная переменная value: " << value << endl;
    cout << "Глобальная переменная value: " << ::value << endl;
}

int main() {
    cout << "=== Начало программы ===" << endl;
    cout << "Глобальная переменная value в main: " << value << endl;
    
    // Вызываем функцию
    demonstrateConflict();
    
    cout << "\n=== Снова в main() ===" << endl;
    cout << "Глобальная переменная value: " << value << endl;
    // Локальная переменная value здесь недоступна
    
    return 0;
}
//19
#include <iostream>
using namespace std;


void transposeMatrix(int matrix[3][3]) {
 
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
          
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Исходная матрица 3x3:" << endl;
    printMatrix(matrix);

   
    transposeMatrix(matrix);

    cout << "\nТранспонированная матрица:" << endl;
    printMatrix(matrix);

    return 0;
}
//20
#include <iostream>
using namespace std;


auto countAboveAverage(int arr[], int size) -> int;

int main() {
   
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arr2[] = { 10, 20, 30, 40, 50 };
    int arr3[] = { 5, 5, 5, 5, 5 };  
    int arr4[] = { 100, 1, 2, 3, 4 };  

    cout << "Массив {1,2,3,4,5,6,7,8,9,10}:" << endl;
    cout << "Элементов выше среднего: " << countAboveAverage(arr1, 10) << "\n" << endl;

    cout << "Массив {10,20,30,40,50}:" << endl;
    cout << "Элементов выше среднего: " << countAboveAverage(arr2, 5) << "\n" << endl;

    cout << "Массив {5,5,5,5,5}:" << endl;
    cout << "Элементов выше среднего: " << countAboveAverage(arr3, 5) << "\n" << endl;

    cout << "Массив {100,1,2,3,4}:" << endl;
    cout << "Элементов выше среднего: " << countAboveAverage(arr4, 5) << endl;

    return 0;
}


auto countAboveAverage(int arr[], int size) -> int {
    if (size <= 0) return 0;

    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

   
    double average = static_cast<double>(sum) / size;

    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > average) {
            count++;
        }
    }

    return count;
}
