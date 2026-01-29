//1

template<typename T>
T square(T value) {
    return value * value;
}


int main() {

    int result1 = square<int>(5); 

 
    double result2 = square<double>(3.14);  

  
    auto result3 = square(4.5);  

    return 0;
}

//2
#include <iostream>


template <typename T>
T compareAndReturnGreater(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int intResult = compareAndReturnGreater(5, 10);  
    double doubleResult = compareAndReturnGreater(3.14, 2.71); 
    char charResult = compareAndReturnGreater('a', 'b');  

    std::cout << "Целое число: " << intResult << std::endl;
    std::cout << "Вещественное число: " << doubleResult << std::endl;
    std::cout << "Символ: " << charResult << std::endl;

    return 0;
}
//3
#include <iostream>


template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int main() {
   
    print(42);         
    print("hello!");   
    print(3.14);        

    return 0;
}
//4

#include <iostream>
template <typename T>
void swap(T& a, T& b) {
    T temp = a; 
    a = b;       
    b = temp;    
}


int main() {
    int x = 5;
    int y = 10;

    std::cout << "Do obmena:\nx = " << x << ", y = " << y << std::endl;
    swap(x, y);  

    std::cout << "Posle obmena:\nx = " << x << ", y = " << y << std::endl;
    return 0;
}
//5
#include <iostream>


template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int intMin = min(5, 10);        
    double doubleMin = min(3.14, 2.71);  
    char charMin = min('a', 'b');     

    std::cout << "Минимальное целое: " << intMin << std::endl;
    std::cout << "Минимальное вещественное: " << doubleMin << std::endl;
    std::cout << "Минимальный символ: " << charMin << std::endl;

    return 0;
}
//7
#include <iostream>
using namespace std;


template<typename T, size_t N>
size_t countElements(const T (&arr)[N]) {
    return N; 
}

int main() {
   
    int arr1 = {1, 2, 3, 4, 5};
    double arr2 = {3.14, 2.71, 1.41};
    char arr3 = {'a', 'b', 'c', 'd'};
    
    cout << "Количество элементов в int массиве: " 
         << countElements(arr1) << endl;
    cout << "Количество элементов в double массиве: "
         << countElements(arr2) << endl;
    cout << "Количество элементов в char массиве: "
         << countElements(arr3) << endl;

    return 0;
}
//8
#include <iostream>
using namespace std;


template<typename T>
T sumArray(const T* arr, int size) {
    T result = 0; 
    for (int i = 0; i < size; i++) {
        result += arr[i]; 
    }
    return result;
}

int main() {
  
    int intArray = { 1, 2, 3, 4, 5 };
    double doubleArray = { 1.5, 2.5, 3.5 };

    cout << "Сумма целых чисел: " << sumArray(intArray, 5) << endl;
    cout << "Сумма дробных чисел: " << sumArray(doubleArray, 3) << endl;

    return 0;
}
//9
template <typename T>
int findElement(const T* array, int size, const T& element) {
    
    for (int i = 0; i < size; ++i) {
       
        if (array[i] == element) {
            return i;  
        }
    }
    return -1;
}
//10
#include <iostream>


template<typename T>
bool areEqual(const T& a, const T& b) {
    return a == b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Сравнение целых чисел: "
        << (areEqual(5, 5) ? "равны" : "не равны") << std::endl;

    std::cout << "Сравнение вещественных чисел: "
        << (areEqual(3.14, 3.14) ? "равны" : "не равны")
        << std::endl;

    std::cout << "Сравнение строк: "
        << (areEqual("Hello", "Hello") ? "равны" : "не равны")
        << std::endl;

    return 0;
}
//11
#include <iostream>
using namespace std;

// Шаблонная функция для поиска максимального элемента
template<typename T>
T findMax(T arr, int size) {
    // Проверяем, что массив не пустой
    if (size <= 0) {
        throw invalid_argument("Размер массива должен быть положительным");
    }

    // Инициализируем максимум первым элементом
    T max = arr;

    // Проходим по всем элементам массива
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
//12
#include <iostream>
using namespace std;

// Шаблонная функция для поиска максимального элемента
template<typename T>
T findMax(T arr, int size) {
    // Проверяем, что массив не пустой
    if (size <= 0) {
        throw invalid_argument("Размер массива должен быть положительным");
    }

    // Инициализируем максимум первым элементом
    T max = arr;

    // Проходим по всем элементам массива
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int intArray = { 3, 5, 7, 2, 8, 1 };
    double doubleArray = { 1.5, 2.7, 3.9, 4.2 };

    cout << "Максимальный элемент целочисленного массива: "
        << findMax(intArray, 6) << endl;
    cout << "Максимальный элемент вещественного массива: "
        << findMax(doubleArray, 4) << endl;

    return 0;
}
//14
#include <iostream>
using namespace std;


template <typename T>
void bubbleSort(T arr, int size) {

    for (int i = 0; i < size - 1; i++) {
      
        for (int j = 0; j < size - i - 1; j++) {
         
            if (arr[j] > arr[j + 1]) {
                
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr1 = { 64, 34, 25, 12, 22, 11, 90 };
    int size1 = sizeof(arr1) / sizeof(arr1);

    cout << "Исходный массив: ";
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    bubbleSort(arr1, size1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    return 0;
}


