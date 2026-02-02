//1
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    std::cout << max(5, 10) << std::endl;  

    
    std::cout << max(3.14, 2.71) << std::endl; 

    
    std::cout << max("Hello", "World") << std::endl;
    

    return 0;
}

//3
#include <iostream>


template<typename T>
T square(T value) {
    return value * value;
}

int main() {
    
    std::cout << "sqrt 5: " << square(5) << std::endl;    
    std::cout << "sqrt 3.14: " << square(3.14) << std::endl; 

    return 0;
}

//4
#include <iostream>


template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int main() {
   
    print(42);       
    print("hello!"); 
    print(3.14);       
    print(true);        

    return 0;
}

//5
#include <iostream>


template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
  
    int intMin = min(5, 10);      
    double doubleMin = min(3.14, 2.71);  
    char charMin = min('a', 'b');  

    std::cout << "min celoe : " << intMin << std::endl;
    std::cout << "min vesh: " << doubleMin << std::endl;
    std::cout << "min sym: " << charMin << std::endl;

    return 0;
}

//8
#include <iostream>
using namespace std;


template<typename T>
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
//9
#include <iostream>
using namespace std;

// Шаблонная функция для поиска максимума
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

//10
#include <iostream>
using namespace std;


template<typename T>
int countGreaterThan(const T* arr, int size, T value) {
    int count = 0;  

 
    for (int i = 0; i < size; i++) {
        if (arr[i] > value) {  
            count++;  
        }
    }
    return count;  
}

int main() {
   
    int intArray = { 1, 5, 8, 10, 3 };
    double doubleArray = { 2.5, 7.2, 9.1, 4.8 };
    char charArray = { 'a', 'b', 'c', 'd' };

    cout << "Количество элементов больше 5 в целочисленном массиве: "
        << countGreaterThan(intArray, 5, 5) << endl;

    cout << "Количество элементов больше 7.2 в массиве double: "
        << countGreaterThan(doubleArray, 4, 7.2) << endl;

    cout << "Количество символов больше 'b' в массиве char: "
        << countGreaterThan(charArray, 4, 'b') << endl;

    return 0;
}
//11
#include <iostream>
#include <string>


auto getValue(int a, double b) -> std::string {
    return "Результат: " + std::to_string(a) + ", " + std::to_string(b);
}

int main() {
   
    std::cout << getValue(5, 3.14) << std::endl; 

    return 0;
}
//12
#include <iostream>


template<typename T>
T calculate(T a, T b) {
    return a + b;  
}

int main() {
   
    int result1 = calculate(5, 3);   
    double result2 = calculate(2.5, 1.5);  

   
    decltype(calculate(10, 20)) auto result3 = calculate(15, 25);

    std::cout << "Результат 1: " << result1 << std::endl;
    std::cout << "Результат 2: " << result2 << std::endl;
    std::cout << "Результат 3: " << result3 << std::endl;

    return 0;
}

//14
#include <iostream>


template<typename T, size_t N>
T average(const T arr, size_t n) {
    
    if (n == 1) {
        return arr;
    }

  
    return arr[n - 1] + average(arr, n - 1);
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    size_t size = sizeof(numbers) / sizeof(numbers);

    std::cout << "sr arifm: " << average(numbers, size) << std::endl;

    return 0;
}




