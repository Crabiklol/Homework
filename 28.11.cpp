
num 1.

#include <iostream>
using namespace std;

int main() {
  
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int sum = 0;  
    
   
    for (int i = 0; i < 10; i++) {
        sum += arr[i];  
    }
    
    
    cout << "Summ: " << sum << endl;
    
    return 0;
}

num 2

#include <iostream>
using namespace std;

int main() {
    const int N = 5;  
    int arr[N];
    double sum = 0.0;
    
    
    cout << "Vvedite " << N << " chisel:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    
    cout << "Masiv: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    double average = sum / N;
    cout << "Srednee arifmeticheskoe: " << average << endl;
    
    return 0;
}

num 3.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 0, -3, 0, 5, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);  
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            ++count;
        }
    }

    cout << "Kol-vo elementov: " << count << endl;
    return 0;
}

num 4.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {-3, 5, -1, 0, -7, 2, -4, 8, -9, 1};
    int count = 0;

    for (int num : arr) {
        if (num < 0) {
            count++;
        }
    }

    cout << "kol-vo minimalnix elementov: " << count << endl;
    return 0;
}


num 5.

#include <iostream>

int main() {
    int n;
    std::cout << "Vvedit kol-vo elementov: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Vvedit elementi massiva ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

   
    int min_value = arr[0];

   
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_value) {
            min_value = arr[i];  
        }
    }

    std::cout << Minimalniy element : " << min_value << std::endl;

    return 0;
}


num 6.


#include <iostream>

int main() {
    int arr[] = {3, 7, 2, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_index = 0;  
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[max_index]) {
            max_index = i;  
        }
    }

    std::cout << "The index of the maximum element: " << max_index << std::endl;
    return 0;
}


num 7.

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};

   
    for (int i = 0; i < SIZE; i++) {
        arr[i] *= 2;
    }

   
    cout << "Result: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

num 8.
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;  
    int arr[SIZE] = {-3, 4, -1, 0, -7};

   
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            arr[i] = 0; 
        }
    }

    
    cout << "Result: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

num 9.
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 40, 50};
    int X;

    cout << "Vvedite chislo X: ";
    cin >> X;

    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == X) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Число " << X << " Vstrechaetsiya v massive" << endl;
    } else {
        cout << "Число " << X << " Ne vstrechaetsa v massive." << endl;
    }

    return 0;
}


num 10.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




