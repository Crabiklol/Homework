//1
#include <iostream>
using namespace std;


void printEvenNumbers(int n) {
    
    if (n < 2) return;

  
    cout << n << " ";

  
    printEvenNumbers(n - 2);
}

int main() {
    int N;
    cout << "Введите число N: ";
    cin >> N;

    cout << "Чётные числа от 1 до " << N << ": ";
    printEvenNumbers(N);

    return 0;
}

//2
#include <iostream>
using namespace std;


int sumOfDigits(int number) {
    
    if (number < 10) {
        return number;
    }
        return (number % 10) + sumOfDigits(number / 10);
}

int main() {
    int num;
    cout << "Введите число: ";
    cin >> num;

    
    cout << "Сумма цифр числа " << num << " равна " << sumOfDigits(num) << endl;

    return 0;
}
//3
#include <iostream>
using namespace std;


int countZeros(int number) {
   
    if (number < 10) {
        return 0;
    }


    int lastDigit = number % 10;

   
    if (lastDigit == 0) {
        return 1 + countZeros(number / 10);
    }
    else {
      
        return countZeros(number / 10);
    }
}

int main() {
    int num;
    cout << "Введите число: ";
    cin >> num;

    cout << "Количество нулей в числе: " << countZeros(num) << endl;
    return 0;
}

//4
#include <iostream>
using namespace std;


void reverseArray(int arr, int size) {
    
    if (size <= 0) {
        return;
    }

    
    cout << arr[size - 1] << " ";

    
    reverseArray(arr, size - 1);
}

int main() {
    int arr = { 1, 2, 3, 4, 5 }; 
    int size = sizeof(arr) / sizeof(arr); 

    cout << "Элементы массива в обратном порядке: ";
    reverseArray(arr, size);

    return 0;
}
//5
#include <iostream>
using namespace std;


bool isPowerOfTwo(int n) {
    
    if (n == 1)
        return true;

   
    if (n % 2 != 0)
        return false;

  
    return isPowerOfTwo(n / 2);
}

int main() {
    int number;
    cout << "Введите число: ";
    cin >> number;

    if (isPowerOfTwo(number))
        cout << number << " является степенью двойки" << endl;
    else
        cout << number << " не является степенью двойки" << endl;

    return 0;
}
//6
#include <iostream>
using namespace std;


int findMin(int arr, int n) {
   
    if (n == 1)
        return arr;

  
    int min_rest = findMin(arr, n - 1);
    return (arr[n - 1] < min_rest) ? arr[n - 1] : min_rest;
}

int main() {
    int arr = { 3, 5, 7, 2, 8, 1 };
    int size = sizeof(arr) / sizeof(arr);

    cout << "Минимальный элемент: " << findMin(arr, size) << endl;
    return 0;
}
//7
#include <iostream>
using namespace std;

int countPositive(int arr, int size, int index = 0) {
   
    if (index >= size) {
        return 0;
    }

    
    int result = (arr[index] > 0) ? 1 : 0;

  
    return result + countPositive(arr, size, index + 1);
}

int main() {
    int arr = { -1, 2, -3, 4, 5, -6 };
    int size = sizeof(arr) / sizeof(arr);

    cout << "Количество положительных элементов: " << countPositive(arr, size) << endl;
    return 0;
}
//8
#include <iostream>
using namespace std;


bool isDescending(int arr, int n) {
 
    if (n <= 1)
        return true;

    
    if (arr[n - 1] <= arr[n - 2])
        return false;

    
    return isDescending(arr, n - 1);
}

int main() {
    int arr = { 10, 9, 8, 7, 6, 5 };  
    int size = sizeof(arr) / sizeof(arr);

    if (isDescending(arr, size))
        cout << "Массив отсортирован по убыванию" << endl;
    else
        cout << "Массив не отсортирован по убыванию" << endl;

    return 0;
}
//9
#include <iostream>
using namespace std;


void replaceNegative(int arr, int size) {
 
    if (size <= 0) return;

    
    if (arr[size - 1] < 0) {
        arr[size - 1] = 0;
    }

 
    replaceNegative(arr, size - 1);
}

int main() {
    int arr = { 3, -2, 5, -7, 0, -1 };
    int size = sizeof(arr) / sizeof(arr);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    replaceNegative(arr, size);

    cout << "Массив после замены: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
//10
#include <iostream>
using namespace std;


int recursiveSearch(int arr, int size, int target, int currentIndex = 0) {

    if (currentIndex >= size) {
        return -1; 
    }

    if (arr[currentIndex] == target) {
        return currentIndex;
    }

 
    return recursiveSearch(arr, size, target, currentIndex + 1);
}

int main() {
    int array = { 3, 5, 7, 9, 11 };
    int target = 7;
    int index = recursiveSearch(array, sizeof(array) / sizeof(array), target);

    if (index != -1) {
        cout << "Элемент найден на позиции: " << index << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }

    return 0;
}
//11
#include <iostream>
#include <string>


int countChars(const std::string& str) {
   
    if (str.empty()) {
        return 0;
    }

  
    return 1 + countChars(str.substr(1));
}

int main() {
    std::string input;

    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    int length = countChars(input);
    std::cout << "Количество символов в строке: " << length << std::endl;

    return 0;
}
//12
#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(const string& str, int start, int end) {
   
    if (start >= end)
        return true;

  
    if (str[start] != str[end])
        return false;

    
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    if (isPalindrome(input, 0, input.length() - 1))
        cout << "Строка является палиндромом" << endl;
    else
        cout << "Строка не является палиндромом" << endl;

    return 0;
}
//13
#include <iostream>
#include <string>
using namespace std;


bool isVowel(char ch) {
   
    ch = tolower(ch);
    return ch == 'а' || ch == 'е' || ch == 'ё' ||
        ch == 'и' || ch == 'о' || ch == 'у' ||
        ch == 'ы' || ch == 'э' || ch == 'ю' || ch == 'я';
}


int countVowels(const string& str, int index = 0) {
    if (index >= str.length()) {
        return 0;  
    }

    int count = 0;
    if (isVowel(str[index])) {
        count++;
    }
    return count + countVowels(str, index + 1);
}

int main() {
    string text = "Привет, мир!";
    cout << "Количество гласных: " << countVowels(text) << endl;
    return 0;
}
//14
#include <iostream>
#include <string>


std::string copyString(const std::string& original, int index = 0) {
  
    if (index >= original.length()) {
        return "";
    }

   
    return original[index] + copyString(original, index + 1);
}

int main() {
    std::string original = "Привет, мир!";
    std::string copied = copyString(original);

    std::cout << "Исходная строка: " << original << std::endl;
    std::cout << "Скопированная строка: " << copied << std::endl;

    return 0;
}

