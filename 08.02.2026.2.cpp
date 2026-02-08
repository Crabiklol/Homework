//1
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int* ptr = nullptr;

    if (ptr != nullptr) {
      
        cout << "Значение по указателю: " << *ptr << endl;
    }
    else {
       
        cout << "Ошибка: указатель равен nullptr, разыменование недопустимо!" << endl;
    }

 
    int value = 42;
    ptr = &value;  


    if (ptr != nullptr) {
        cout << "Теперь указатель валиден. Значение: " << *ptr << endl;
    }
    else {
        cout << "Указатель неожиданно стал nullptr!" << endl;
    }

    return 0;
}

//2
#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    int arr[5] = { 10, 20, 30, 40, 50 };


   
    cout << "Адрес первого элемента (через имя массива): " << arr << endl;

   
    cout << "Адрес первого элемента (через &arr[0]): " << &arr[0] << endl;


   
    int* ptr = arr;  
    cout << "Адрес через указатель ptr: " << ptr << endl;


    return 0;
}

//3
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);  



    int* ptr = arr;  



    cout << "Элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
       
        cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    }

    return 0;
}

///4
#include <iostream>
using namespace std;

void foo(int) { cout << "Вызван foo(int)" << endl; }
void foo(int*) { cout << "Вызван foo(int*)" << endl; }

int main() {
    setlocale(LC_ALL, "Russian");
    foo(NULL);    
   
    foo(nullptr);  
    return 0;
}

//5
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);  


    
    int* ptr1 = &arr[1];  
    int* ptr2 = &arr[3];  


   
    cout << "ptr1 указывает на arr[1] = " << *ptr1 << ", адрес: " << ptr1 << endl;
    cout << "ptr2 указывает на arr[3] = " << *ptr2 << ", адрес: " << ptr2 << endl;


    
    cout << "\nРезультаты сравнения:\n";
    cout << "ptr1 == ptr2: " << (ptr1 == ptr2) << endl;  
    cout << "ptr1 != ptr2: " << (ptr1 != ptr2) << endl; 
    cout << "ptr1 <  ptr2: " << (ptr1 < ptr2) << endl; 
    cout << "ptr1 >  ptr2: " << (ptr1 > ptr2) << endl;  
    cout << "ptr1 <= ptr2: " << (ptr1 <= ptr2) << endl; 
    cout << "ptr1 >= ptr2: " << (ptr1 >= ptr2) << endl; 


    
    int distance = ptr2 - ptr1;  
    cout << "\nРасстояние между ptr1 и ptr2 (в элементах): " << distance << endl;

    cout << "Это соответствует разнице индексов: 3 - 1 = " << (3 - 1) << endl;


    
    if (ptr1 < ptr2) {
        cout << "\nptr1 действительно указывает на элемент, расположенный раньше ptr2 в массиве." << endl;
    }
    else {
        cout << "\nptr1 не указывает на элемент перед ptr2." << endl;
    }


    return 0;
}

//6
#include <iostream>
using namespace std;


int countPositive(const int* arr, int size) {
   
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    int positiveCount = 0;  

 
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {  
            positiveCount++;
        }
    }

    return positiveCount;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { -5, 3, 0, 7, -2, 4, -1, 6 };
    int size = sizeof(data) / sizeof(data[0]);


    int result = countPositive(data, size);


    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Количество положительных элементов: " << result << endl;

    return 0;
}

//7
#include <iostream>
using namespace std;


int findMax(const int* arr, int size) {
   
    if (arr == nullptr || size <= 0) {
        throw invalid_argument("Массив пуст или указатель nullptr");
    }

    const int* current = arr;        
    const int* end = arr + size; 
    int maxValue = *current;       


   
    ++current;  
    while (current < end) {
        if (*current > maxValue) {
            maxValue = *current; 
        }
        ++current;  
    }

    return maxValue;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 3, -7, 12, 5, -2, 8, 0 };
    int size = sizeof(data) / sizeof(data[0]);

    try {
        int max = findMax(data, size);
        cout << "Максимальный элемент массива: " << max << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

//9
#include <iostream>
using namespace std;


void reverseTraverse(const int* arr, int size) {
   
    if (arr == nullptr || size <= 0) {
        cout << "Массив пуст или указатель nullptr" << endl;
        return;
    }

  
    const int* ptr = arr + size - 1;  


    cout << "Обратный обход массива: ";

   
    for (int i = 0; i < size; ++i) {
        cout << *ptr << " ";  
        --ptr;           
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(data) / sizeof(data[0]);


   
    reverseTraverse(data, size);


    return 0;
}

//10

#include <iostream>
using namespace std;


bool isPointerInArray(const int* arr, int size, const int* ptr) {
   
    if (arr == nullptr || size <= 0 || ptr == nullptr) {
        return false;
    }

    
    const int* begin = arr;
    const int* end = arr + size;


    
    return (ptr >= begin) && (ptr < end);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int data[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(data) / sizeof(data[0]);


   
    const int* p1 = &data[2];      
    const int* p2 = &data[0];    
    const int* p3 = &data[size - 1]; 
    const int* p4 = data + size;   
    const int* p5 = data - 1;    
    const int* p6 = nullptr;     


    cout << boolalpha; 


    cout << "p1 в массиве: " << isPointerInArray(data, size, p1) << endl; 
    cout << "p2 в массиве: " << isPointerInArray(data, size, p2) << endl; 
    cout << "p3 в массиве: " << isPointerInArray(data, size, p3) << endl; 
    cout << "p4 в массиве: " << isPointerInArray(data, size, p4) << endl; 
    cout << "p5 в массиве: " << isPointerInArray(data, size, p5) << endl; 
    cout << "p6 в массиве: " << isPointerInArray(data, size, p6) << endl; 


    return 0;
}

//11
#include <iostream>
using namespace std;


void safePrint(const int* ptr, int defaultValue = 0) {
    if (ptr == nullptr) {
        cout << "Указатель равен nullptr. Выводим значение по умолчанию: " << defaultValue << endl;
    }
    else {
        cout << "Значение по указателю: " << *ptr << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int value = 42;
    int* validPtr = &value;   
    int* nullPtr = nullptr;  

   
    safePrint(validPtr);

    
    safePrint(nullPtr);

   
    safePrint(nullPtr, -1);


    return 0;
}

//12
#include <iostream>
using namespace std;


bool copyArray(const int* source, int* dest, int size) {
    
    if (source == nullptr || dest == nullptr || size <= 0) {
        return false;
    }

   
    const int* srcPtr = source;   
    int* dstPtr = dest;        


    
    for (int i = 0; i < size; ++i) {
        *dstPtr = *srcPtr;  
        ++srcPtr;          
        ++dstPtr;        
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int src[] = { 10, 20, 30, 40, 50 };
    int srcSize = sizeof(src) / sizeof(src[0]);


   
    int dst[5];

    
    if (copyArray(src, dst, srcSize)) {
        cout << "Копирование успешно. Содержимое целевого массива: ";
        for (int i = 0; i < srcSize; ++i) {
            cout << dst[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ошибка при копировании массива" << endl;
    }

    return 0;
}

//13
#include <iostream>
using namespace std;

/**
 * Меняет местами минимальный и максимальный элементы массива
 * @param arr - указатель на первый элемент массива
 * @param size - количество элементов в массиве
 * @return true, если обмен выполнен, false при ошибках (пустой массив и т.п.)
 */
bool swapMinMax(int* arr, int size) {
    // Проверка входных данных
    if (arr == nullptr || size <= 1) {
        return false;  // не хватает элементов для обмена
    }

    // Инициализация указателей на мин. и макс. элементы
    int* minPtr = arr;   // указатель на минимальный элемент
    int* maxPtr = arr;  // указатель на максимальный элемент


    // Проходим по массиву, начиная со второго элемента
    int* current = arr + 1;  // указатель на текущий элемент (начинаем с arr[1])
    const int* end = arr + size;  // указатель на конец массива


    while (current < end) {
        if (*current < *minPtr) {
            minPtr = current;  // обновляем указатель на минимум
        }
        if (*current > *maxPtr) {
            maxPtr = current;  // обновляем указатель на максимум
        }
        ++current;  // переходим к следующему элементу
    }

    // Меняем значения местами через разыменование указателей
    int temp = *minPtr;
    *minPtr = *maxPtr;
    *maxPtr = temp;

    return true;
}

int main() {
    int data[] = {3, -7, 12, 5, -2, 8, 0};
    int size = sizeof(data) / sizeof(data[0]);


    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    if (swapMinMax(data, size)) {
        cout << "После обмена min и max: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Ошибка: не удалось выполнить обмен" << endl;
    }

    return 0;
}



//14
#include <iostream>
using namespace std;
int countEvenElements(const int* arr, int size) {
   
    if (arr == nullptr || size <= 0) {
        return 0;
    }

    int evenCount = 0;         
    const int* current = arr;  
    const int* end = arr + size; 

    
    while (current < end) {
        if (*current % 2 == 0) {  
            evenCount++;
        }
        ++current;  
    }

    return evenCount;
}

int main() {
    
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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


