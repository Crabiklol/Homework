#include <iostream>

int main() {
    
    int arr[4][4];

    int value = 5;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = value;
            value += 5;
        }
    }

    std::cout << "Massiv 4x4:" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum += arr[i][j];
        }
    }

    std::cout << "Sum massiva: " << sum << std::endl;

    return 0;
}
#include <iostream>

int main() {
    const int SIZE = 4;
    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    std::cout << "Elements of the secondary diagonal:" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (i + j == SIZE - 1) {
                std::cout << matrix[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>

int main() {
    const int ROWS = 5;
    const int COLS = 5;
    int matrix[ROWS][COLS] = {
        {1, -2, 3, -4, 5},
        {-6, 7, -8, 9, 10},
        {11, 12, -13, 14, -15},
        {-16, 17, 18, 19, 20},
        {21, 22, 23, -24, 25}
    };

    int negativeCount = 0;
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] < 0) {
                negativeCount++;
            }
        }
    }

    std::cout << "Number of negative elements: " << negativeCount << std::endl;

    return 0;
}

#include <iostream>

int main() {

    const int ROWS = 3;
    const int COLS = 4;
    int array[ROWS][COLS];


    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {

            array[i][j] = (i * COLS + j + 1) * 2;
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << array[i][j] << "\t"; 
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>

int main() {
    const int N = 3;
    const int M = 4;

    int matrix[N][M] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int max_row_sum = -1000;
    int max_row_index = -1;

    for (int i = 0; i < N; ++i) {
        int current_row_sum = 0;
        for (int j = 0; j < M; ++j) {
            current_row_sum += matrix[i][j];
        }

        if (current_row_sum > max_row_sum) {
            max_row_sum = current_row_sum;
            max_row_index = i;
        }
    }

    if (max_row_index != -1) {
        std::cout << "The row with the largest sum of elements: " << max_row_index + 1 << std::endl;
        std::cout << "Sum: " << max_row_sum << std::endl;
    } else {
        std::cout << "The matrix is ​​empty or has not been initialized.." << std::endl;
    }

    return 0;
}
