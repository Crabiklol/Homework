#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> instructions = {"I1", "I2", "I3"};
    int numCycles = 5;

    for (int cycle = 1; cycle <= numCycles; ++cycle) {
        std::string IF = ".", EX = ".", WB = ".";
        if (cycle >= 3 && cycle - 2 <= instructions.size()) {
            WB = instructions[cycle - 3];
        }
        if (cycle >= 2 && cycle - 1 <= instructions.size()) {
            EX = instructions[cycle - 2];
        }
        if (cycle <= instructions.size()) {
            IF = instructions[cycle - 1];
        }

        std::cout << "Cycle " << cycle << ": IF=" << IF << ", EX=" << EX << ", WB=" << WB << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int main() {
    std::vector<int> accessSequence = {1, 2, 1, 3, 2, 1};
    int cacheSize = 2;

    std::queue<int> cacheQueue; 
    std::unordered_set<int> cacheSet; 
    int hits = 0, misses = 0;

    for (int addr : accessSequence) {
        if (cacheSet.find(addr) != cacheSet.end()) {

            std::cout << "HIT" << std::endl;
            hits++;
        } else {

            std::cout << "MISS" << std::endl;
            misses++;

            if (cacheQueue.size() >= cacheSize) {
                int oldest = cacheQueue.front();
                cacheQueue.pop();
                cacheSet.erase(oldest);
            }
            cacheQueue.push(addr);
            cacheSet.insert(addr);
        }
    }

    std::cout << "Total hits: " << hits << std::endl;
    std::cout << "Total misses: " << misses << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

void sumRange(const std::vector<int>& arr, size_t start, size_t end, long long& result) {
    result = std::accumulate(arr.begin() + start, arr.begin() + end, 0LL);
}

int main() {
    const size_t size = 1000000;
    std::vector<int> arr(size, 1);

    long long sumSingle = std::accumulate(arr.begin(), arr.end(), 0LL);
    std::cout << "Sum (single thread): " << sumSingle << std::endl;
    long long sumPart1 = 0, sumPart2 = 0;
    std::thread t1(sumRange, std::ref(arr), 0, size / 2, std::ref(sumPart1));
    std::thread t2(sumRange, std::ref(arr), size / 2, size, std::ref(sumPart2));

    t1.join();
    t2.join();

    long long sumMulti = sumPart1 + sumPart2;
    std::cout << "Sum (two threads): " << sumMulti << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    std::vector<char> branchSequence = {'T', 'N', 'T', 'T', 'N'};
    char predictor = 'T';
    int correct = 0, errors = 0;

    for (char actual : branchSequence) {
        if (predictor == actual) {
            correct++;
        } else {
            errors++;
            predictor = (predictor == 'T') ? 'N' : 'T';
        }

        std::cout << "Actual: " << actual << ", Predictor: " << predictor
                 << ", Result: " << (predictor == actual ? "Correct" : "Error") << std::endl;
    }

    std::cout << "Correct predictions: " << correct << std::endl;
    std::cout << "Errors: " << errors << std::endl;

    return 0;
}
