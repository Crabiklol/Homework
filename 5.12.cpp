#include <iostream>
#include <algorithm>
using namespace std;

void task1() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
}

void task2() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int sum = 0;
    for (int i = 0; i < 10; i++) sum += arr[i];
    cout << sum << endl;
}

void task3() {
    int arr[8] = { 5,2,8,1,9,3,7,4 };
    int min = arr[0], max = arr[0];
    for (int i = 1; i < 8; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    cout << "Min: " << min << ", Max: " << max << endl;
}

void task4() {
    int arr[6] = { 1,2,3,4,5,6 };
    for (int i = 0; i < 6; i++) if (arr[i] % 2 != 0) cout << arr[i] << " ";
    cout << endl;
}

void task5() {
    int arr[12] = { -1,2,-3,4,-5,6,-7,8,-9,10,-11,12 };
    int count = 0;
    for (int i = 0; i < 12; i++) if (arr[i] < 0) count++;
    cout << count << endl;
}

void task6() {
    int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    for (int i = 0; i < 3; i++) cout << arr[i][i] << " ";
    cout << endl;
}

void task7() {
    int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    int sum = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) sum += arr[i][j];
    cout << sum << endl;
}

void task8() {
    int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    for (int i = 0; i < 3; i++) cout << arr[i][3] << " ";
    cout << endl;
}

void task9() {
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int target, index = -1;
    cin >> target;
    for (int i = 0; i < 10; i++) if (arr[i] == target) { index = i; break; }
    cout << index << endl;
}

void task10() {
    int arr[15] = { 3,1,4,1,5,9,2,6,5,3,5,8,9,7,9 };
    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < 15; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
        if (arr[i] > arr[max_idx]) max_idx = i;
    }
    swap(arr[min_idx], arr[max_idx]);
    for (int i = 0; i < 15; i++) cout << arr[i] << " ";
    cout << endl;
}

void task11() {
    int arr[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
    int sum = 0;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++) sum += arr[i][j];
    cout << sum << endl;
}

void task12() {
    int arr[4][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };
    for (int j = 0; j < 5; j++) {
        double sum = 0;
        for (int i = 0; i < 4; i++) sum += arr[i][j];
        cout << sum / 4 << " ";
    }
    cout << endl;
}

void task13() {
    int arr[12] = { 64,34,25,12,22,11,90,5,77,88,1,3 };
    for (int i = 0; i < 11; i++) {
        int min_idx = i;
        for (int j = i + 1; j < 12; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
    for (int i = 0; i < 12; i++) cout << arr[i] << " ";
    cout << endl;
}

void task14() {
    int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    double avg = 0;
    for (int i = 0; i < 20; i++) avg += arr[i];
    avg /= 20;
    int count = 0;
    for (int i = 0; i < 20; i++) if (arr[i] > avg) count++;
    cout << count << endl;
}

void task15() {
    int arr[3][3] = { {1,2,3},{2,4,5},{3,5,6} };
    bool symmetric = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != arr[j][i]) {
                symmetric = false;
                break;
            }
        }
    }
    cout << "Is symmetric: " << (symmetric ? "Yes" : "No") << endl;
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();
    task13();
    task14();
    task15();
    return 0;
}
