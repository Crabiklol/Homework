#include <iostream>
using namespace std;

int square(int num) {
    return num * num;
}

bool isEven(int num) {
    return num % 2 == 0;
}

void printHello() {
    cout << "Hello, world!" << endl;
}

int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

double averageOfThree(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

void printNumbers(int N) {
    for (int i = 1; i <= N; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

int sumToN(int N) {
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }
    return sum;
}

void multiplicationTable(int num) {
    for (int i = 1; i <= 10; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int minElement(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countNegative(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void addArrays(int arr1[], int arr2[], int result[], int size) {
    for (int i = 0; i < size; ++i) {
        result[i] = arr1[i] + arr2[i];
    }
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int diagonalSum(int matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

void transposeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {

    cout << "Square of 5: " << square(5) << endl;

    cout << "Is 4 even? " << (isEven(4) ? "Yes" : "No") << endl;

    printHello();

    cout << "Max of 10 and 15: " << maxOfTwo(10, 15) << endl;

    cout << "Average of 1, 2, 3: " << averageOfThree(1, 2, 3) << endl;

    printNumbers(5);

    cout << "Sum from 1 to 5: " << sumToN(5) << endl;

    multiplicationTable(7);

    int arr1[] = { 1, 2, 3, 4, 5 };
    int size1 = 5;
    cout << "Sum of array {1,2,3,4,5}: " << sumArray(arr1, size1) << endl;

    int arr2[] = { 5, 2, 8, 1, 9 };
    int size2 = 5;
    cout << "Min element in {5,2,8,1,9}: " << minElement(arr2, size2) << endl;

    int arr3[] = { 10, 20, 30, 40 };
    int size3 = 4;
    cout << "Array {10,20,30,40}: ";
    printArray(arr3, size3);

    int arr4[] = { -1, 2, -3, 4, -5 };
    int size4 = 5;
    cout << "Negative elements in {-1,2,-3,4,-5}: " << countNegative(arr4, size4) << endl;

    int x = 10, y = 20;
    swapNumbers(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    int arr5[] = { 1, 2, 3 };
    int arr6[] = { 4, 5, 6 };
    int result[3];
    int size5 = 3;
    addArrays(arr5, arr6, result, size5);
    cout << "Sum of {1,2,3} and {4,5,6}: ";
    printArray(result, size5);

    cout << "5! = " << factorial(5) << endl;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Diagonal sum of 3x3 matrix: " << diagonalSum(matrix) << endl;

    const int size6 = 3;
    int** dynamicMatrix = new int* [size6];
    for (int i = 0; i < size6; ++i) {
        dynamicMatrix[i] = new int[size6];
    }

    dynamicMatrix[0][0] = 1; dynamicMatrix[0][1] = 2; dynamicMatrix[0][2] = 3;
    dynamicMatrix[1][0] = 4; dynamicMatrix[1][1] = 5; dynamicMatrix[1][2] = 6;
}
