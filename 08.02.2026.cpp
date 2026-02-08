//1
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int number;

    number = 42;

    int* ptr = &number;  
    cout << "Значение переменной: " << number << endl;
    cout << "Адрес переменной: " << ptr << endl;

    return 0;
}

//2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int value = 10;           
    int* ptr = &value;     

    cout << "Исходное значение: " << value << endl;

    *ptr = 25;            
    cout << "Новое значение: " << value << endl;     

    return 0;
}

//3
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int value = 10;

   
    int* ptr1 = &value;  
    int* ptr2 = &value; 

 
    cout << "Начальное значение (через ptr1): " << *ptr1 << endl;
    cout << "Начальное значение (через ptr2): " << *ptr2 << endl;
    cout << "Значение переменной value: " << value << endl;

 
    *ptr1 = 25;

   
    cout << "\nПосле изменения через ptr1:" << endl;
    cout << "Значение через ptr2: " << *ptr2 << endl;
    cout << "Значение переменной value: " << value << endl;

    return 0;
}

//4
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int* ptr = nullptr;

  
    if (ptr != nullptr) {
      
        cout << "Значение по указателю: " << *ptr << endl;
    }
    else {
        cout << "Указатель равен nullptr — разыменование недопустимо!" << endl;
    }

   
    int value = 42;
    ptr = &value;

   
    if (ptr != nullptr) {
        cout << "Теперь значение по указателю: " << *ptr << endl;
    }
    else {
        cout << "Указатель снова равен nullptr!" << endl;
    }

    return 0;
}

//5
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);  


   
    int* ptr = arr;  ;

    cout << "Адреса элементов массива (через арифметику указателей):" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Элемент [" << i << "]: адрес = " << (ptr + i) << endl;
    }

    return 0;
}

//6
#include <iostream>
using namespace std;


void multiplyByThree(int* ptr) {
    if (ptr != nullptr) { 
        *ptr = *ptr * 3;
    }
 
}

int main() {
    setlocale(LC_ALL, "Russian");
    int value = 7;

    cout << "Исходное значение: " << value << endl;

    multiplyByThree(&value); 

    cout << "После умножения на 3: " << value << endl;

    return 0;
}

//7
#include <iostream>
using namespace std;


void swapValues(int* a, int* b) {
    int temp = *a;    
    *a = *b;       
    *b = temp;      
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 10;
    int y = 20;

    cout << "До обмена: x = " << x << ", y = " << y << endl;

    swapValues(&x, &y);  

    cout << "После обмена: x = " << x << ", y = " << y << endl;

    return 0;
}

//8
#include <iostream>
using namespace std;


int arraySum(const int* arr, int size) {
    const int* ptr = arr;          
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += *ptr;                
        ptr++;                  
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 1, 3, 5, 7, 9 };
    int n = sizeof(data) / sizeof(data[0]); 

    int result = arraySum(data, n);

    cout << "Сумма элементов массива: " << result << endl;

    return 0;
}

//9
#include <iostream>
using namespace std;


int findMax(const int* arr, int size) {
    if (size <= 0) return 0; 


    const int* ptr = arr;        
    int max = *ptr;       


    for (int i = 1; i < size; ++i) {
        ptr++;                 
        if (*ptr > max) {
            max = *ptr;    
        }
    }

    return max;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 3, 7, 2, 9, 1, 8 };
    int n = sizeof(data) / sizeof(data[0]);

    int maximum = findMax(data, n);
    cout << "Максимальный элемент: " << maximum << endl;

    return 0;
}

//10

#include <iostream>
using namespace std;


void replaceNegativesWithZero(int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return;  
    }

    int* ptr = arr;          
    int* end = arr + size; 

    while (ptr < end) {
        if (*ptr < 0) {     
            *ptr = 0;       
        }
        ptr++;            
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { -5, 3, -1, 0, 7, -8, 4 };
    int size = sizeof(data) / sizeof(data[0]);

    cout << "До обработки: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    
    replaceNegativesWithZero(data, size);

    cout << "После обработки: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

//11
#include <iostream>
using namespace std;


int countEvenElements(const int* arr, int size) {
  
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    const int* ptr = arr;        
    const int* end = arr + size; 
    int evenCount = 0;        

   
    while (ptr < end) {
        if (*ptr % 2 == 0) {  
            evenCount++;
        }
        ptr++;  
    }

    return evenCount;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 1, 4, 7, 8, 3, 12, 5, 6 };
    int size = sizeof(data) / sizeof(data[0]);

    int evenNum = countEvenElements(data, size);

    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Количество чётных элементов: " << evenNum << endl;

    return 0;
}

//12
#include <iostream>
using namespace std;


int findMinElement(const int* arr, int size) {
   
    if (arr == nullptr || size <= 0) {
        throw invalid_argument("Массив пуст или указатель null");
      
    }

    const int* ptr = arr;           
    const int* end = arr + size;  
    int minVal = *ptr;           


    
    ptr++; 
    while (ptr < end) {
        if (*ptr < minVal) {
            minVal = *ptr;  
        }
        ptr++;  
    }

    return minVal;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 5, -3, 8, 1, -7, 4, 0 };
    int size = sizeof(data) / sizeof(data[0]);

    try {
        int minElement = findMinElement(data, size);
        cout << "Массив: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "Минимальный элемент: " << minElement << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

//13
#include <iostream>
using namespace std;

void printReverse(const int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        cout << "Массив пуст или указатель null" << endl;
        return;
    }

    
    const int* ptr = arr + size - 1;

 
    while (ptr >= arr) {
        cout << *ptr << " ";
        ptr--; 
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "В обратном порядке: ";
    printReverse(data, size);

    return 0;
}

//14
#include <iostream>
using namespace std;


void modifyValue(int** doublePtr) {
    if (doublePtr == nullptr) {
        cout << "Ошибка: doublePtr равен nullptr!" << endl;
        return;
    }

    
    
    **doublePtr = 42;  
}

int main() {
    setlocale(LC_ALL, "Russian");
    int value = 10;
    int* ptr = &value;     
    int** doublePtr = &ptr; 

    cout << "Исходное значение: " << value << endl;


   
    modifyValue(doublePtr);


    cout << "После изменения: " << value << endl;

    return 0;
}


//15
#include <iostream>
using namespace std;


void nullifyPointer(int*& ptr) {
    ptr = nullptr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int value = 42;
    int* myPtr = &value;

    cout << "Адрес до обнуления: " << myPtr << endl;
    cout << "Значение до обнуления: " << *myPtr << endl;

    nullifyPointer(myPtr);


    if (myPtr == nullptr) {
        cout << "Указатель обнулён (nullptr)" << endl;
    }
    else {
        cout << "Указатель всё ещё действителен: " << myPtr << endl;
    }

    return 0;
}

