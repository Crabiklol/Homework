#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void task1() {
    vector<int> A(10);
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; ++i) cin >> A[i];
    
    int sum = 0;
    for (int x : A) sum += x;
    cout << "Sum: " << sum << endl;
}

void task2() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    double avg = 0.0;
    for (int x : A) avg += x;
    avg /= N;
    cout << "Average: " << avg << endl;
}

void task3() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int sum = 0;
    for (int x : A) if (x % 2 == 0) sum += x;
    cout << "Sum of even: " << sum << endl;
}

void task4() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int sum = 0;
    for (int i = 0; i < N; i += 2) sum += A[i];
    cout << "Sum of odd positions: " << sum << endl;
}

void task5() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int sum = 0;
    for (int x : A) if (x > 0) sum += x;
    cout << "Sum of positive: " << sum << endl;
}

void task6() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    bool found = false;
    for (int x : A) if (x == X) { found = true; break; }
    cout << (found ? "X found" : "X not found") << endl;
}

void task7() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    int idx = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] == X) { idx = i; break; }
    }
    if (idx != -1) cout << "Index: " << idx << endl;
    else cout << "X not found" << endl;
}

void task8() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    int count = 0;
    for (int x : A) if (x == X) ++count;
    cout << "Occurs once: " << count << endl;
}

void task9() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int min_val = A[0], min_idx = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i] < min_val) { min_val = A[i]; min_idx = i; }
    }
    cout << "Min: " << min_val << ", index: " << min_idx << endl;
}

void task10() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int max_val = A[0], max_idx = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i] > max_val) { max_val = A[i]; max_idx = i; }
    }
    cout << "Max: " << max_val << ", Index: " << max_idx << endl;
}


void task11() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Sorted array: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    bool found = binary_search(A.begin(), A.end(), X);
    cout << (found ? "X found" : "X not found") << endl;
}

void task12() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Sorted array: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    auto it = lower_bound(A.begin(), A.end(), X);
    if (it != A.end() && *it == X) {
        cout << "index: " << (it - A.begin()) << endl;
    } else {
        cout << "X not found" << endl;
    }
}

void task13() {
    int N, X;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Sorted array: ";
    for (int& x : A) cin >> x;
    cout << "X: "; cin >> X;
    
    auto it = lower_bound(A.begin(), A.end(), X);
    cout << "Index to insert: " << (it - A.begin()) << endl;
}


void task14() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i] < A[min_idx]) min_idx = i;
        if (A[i] > A[max_idx]) max_idx = i;
    }
    
    int start = min(min_idx, max_idx);
    int end = max(min_idx, max_idx);
    int sum = 0;
    for (int i = start; i <= end; ++i) sum += A[i];
    cout << "Amount between min and max: " << sum << endl;
}

void task15() {
    int N;
    cout << "N: "; cin >> N;
    vector<int> A(N);
    cout << "Elements: ";
    for (int& x : A) cin >> x;
    
    bool duplicate = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1);
    }
}
