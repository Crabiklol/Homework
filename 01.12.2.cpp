#include <iostream>
using namespace std;

int main() {
   
    const int DATA_SIZE = 12;
    int data[DATA_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    const int CACHE_SIZE = 3;
    int cache[CACHE_SIZE] = { -1, -1, -1 };

    const int ACCESS_COUNT = 12;
    int accesses[ACCESS_COUNT] = { 0, 1, 2, 0, 3, 1, 4, 2, 5, 0, 6, 1 };

    int cache_hit = 0;
    int cache_miss = 0;

    
    int head = 0;


    for (int i = 0; i < ACCESS_COUNT; i++) {
        int addr = accesses[i];
        bool hit = false;

        for (int j = 0; j < CACHE_SIZE; j++) {
            if (cache[j] == addr) {
                hit = true;
                break;
            }
        }

        if (hit) {
            cout << "Access " << addr << " -> HIT" << endl;
            cache_hit++;
        }
        else {
            cout << "Access " << addr << " -> MISS" << endl;
            cache_miss++;

        
            cache[head] = addr;
            head = (head + 1) % CACHE_SIZE; 
        }
    }

 
    cout << "Total cache hits: " << cache_hit << endl;
    cout << "Total cache misses: " << cache_miss << endl;

    return 0;
}
