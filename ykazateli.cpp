#include <iostream>
using namespace std;


// 1. Объявить переменную и указатель, вывести значение и адрес
void task1() {
    int x = 42;
    int* ptr = &x;
    cout << "Значение: " << *ptr << ", адрес: " << ptr << endl;
}

// 2. Изменить значение через указатель
void task2() {
    int x = 10;
    int* ptr = &x;
    *ptr = 25;
    cout << "Новое значение: " << x << endl;
}

// 3. Два указателя на одну переменную
void task3() {
    int x = 5;
    int* p1 = &x;
    int* p2 = &x;
    *p1 = 15;
    cout << "Через p2: " << *p2 << endl; // 15
}

// 4. Указатель = nullptr, проверка перед разыменованием
void task4() {
    int* ptr = nullptr;
    if (ptr) {
        cout << *ptr << endl;
    }
    else {
        cout << "Указатель null" << endl;
    }
}

// 5. Адреса элементов массива через указатель
void task5() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int* ptr = arr;
    for (int i = 0; i < 5; i++) {
        cout << "Элемент " << i << ", адрес: " << (ptr + i) << endl;
    }
}

// 6. Функция: увеличить значение в 3 раза
void triple(int* num) {
    if (num) *num *= 3;
}

// 7. Обмен значений через указатели
void swap(int* a, int* b) {
    if (a && b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// 8. Сумма элементов массива через указатели
int sumArray(int* arr, int size) {
    int sum = 0;
    for (int* p = arr; p < arr + size; p++) {
        sum += *p;
    }
    return sum;
}

// 9. Максимум в массиве через указатели
int maxArray(int* arr, int size) {
    if (size == 0) return 0;
    int maxVal = *arr;
    for (int* p = arr + 1; p < arr + size; p++) {
        if (*p > maxVal) maxVal = *p;
    }
    return maxVal;
}

// 10. Заменить отрицательные на 0
void zeroNegatives(int* arr, int size) {
    for (int* p = arr; p < arr + size; p++) {
        if (*p < 0) *p = 0;
    }
}

// 11. Количество чётных через арифметику указателей
int countEven(int* arr, int size) {
    int count = 0;
    for (int* p = arr; p < arr + size; p++) {
        if ((*p % 2) == 0) count++;
    }
    return count;
}

// 12. Минимум без индексации
int minArray(int* arr, int size) {
    if (size == 0) return 0;
    int minVal = *arr;
    for (int* p = arr + 1; p < arr + size; p++) {
        if (*p < minVal) minVal = *p;
    }
    return minVal;
}

// 13. Вывод массива в обратном порядке
void printReverse(int* arr, int size) {
    for (int* p = arr + size - 1; p >= arr; p--) {
        cout << *p << " ";
    }
    cout << endl;
}

// 14. Функция с указателем на указатель
void changeViaDoublePtr(int** ptr) {
    if (ptr && *ptr) {
        **ptr = 999;
    }
}

// 15. Обнулить указатель
void nullify(int*& ptr) {
    ptr = nullptr;
}

// 16. Проверить равенство значений через указатели
bool areEqual(int* a, int* b) {
    return (a && b && *a == *b);
}

// 17. Копирование массива через указатели
void copyArray(int* src, int* dst, int size) {
    for (int* s = src, *d = dst; s < src + size; s++, d++) {
        *d = *s;
    }
}

// 18. Поменять первый и последний элементы
void swapFirstLast(int* arr, int size) {
    if (size > 1) {
        int temp = *arr;
        *arr = *(arr + size - 1);
        *(arr + size - 1) = temp;
    }
}

// 19. Количество элементов > заданного значения
int countGreater(int* arr, int size, int val) {
    int count = 0;
    for (int* p = arr; p < arr + size; p++) {
        if (*p > val) count++;
    }
    return count;
}

// 20. Разница: указатель на константу vs константный указатель
void constExamples() {
    int a = 10, b = 20;

    
    const int* ptrToConst = &a;
    ptrToConst = &b;      
 

    
    int* const constPtr = &a;
    *constPtr = 30;      
   

    cout << "*ptrToConst: " << *ptrToConst << endl;
    cout << "*constPtr: " << *constPtr << endl;
}


int main() {
    cout << "=== Базовый уровень ===\n";
    task1(); task2(); task3(); task4(); task5();

    cout << "\n=== Средний уровень ===\n";
    int x = 5; triple(&x); cout << "triple: " << x << endl;
    int a = 1, b = 2; swap(&a, &b); cout << "swap: " << a << ", " << b << endl;
    int arr[] = { 1, 2, 3, 4, 5 };
    cout << "sum: " << sumArray(arr, 5) << endl;
    cout << "max: " << maxArray(arr, 5) << endl;
    zeroNegatives(arr, 5);
    cout << "even count: " << countEven(arr, 5) << endl;

    cout << "\n=== Повышенный уровень ===\n";
    cout << "min: " << minArray(arr, 5) << endl;
    printReverse(arr, 5);
    changeViaDoublePtr(&arr); cout << "via double ptr: " << arr[0] << endl;
    int* ptr = &a; nullify(ptr); cout << "nullified: " << (ptr ? "not null" : "null") << endl;

    cout << "\n=== Прикладные задачи ===\n";
    cout << "equal: " << areEqual(&a, &b) << endl;
    int dst[5]; copyArray(arr, dst, 5);
    swapFirstLast(arr, 5); cout << "first-last swapped\n";
    cout << "greater than 3: " << countGreater(arr, 5, 3) << endl;

    cout << "\n=== Пример с const ===\n";
    constExamples();

    return 0;
}
