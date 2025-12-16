#include <iostream>
#include <vector>

int main() {
    std::vector<char> sequence = { 'T', 'N', 'T', 'T', 'N', 'N', 'T', 'N', 'T' };
    int correct_always = 0, incorrect_always = 0;
    int correct_1bit = 0, incorrect_1bit = 0;
    int state_1bit = 1;
    std::vector<int> state_2bit = { 1, 1 };
    int correct_2bit = 0, incorrect_2bit = 0;

    std::cout << "Always Taken Predictor:\n";
    for (int i = 0; i < sequence.size(); ++i) {
        char predicted = 'T';
        char actual = sequence[i];
        if (predicted == actual) {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> OK\n";
            correct_always++;
        }
        else {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> MISS\n";
            incorrect_always++;
        }
    }
    std::cout << "Correct = " << correct_always << "\nIncorrect = " << incorrect_always << "\n\n";

    std::cout << "1-bit Predictor:\n";
    for (int i = 0; i < sequence.size(); ++i) {
        char predicted = (state_1bit == 1) ? 'T' : 'N';
        char actual = sequence[i];
        if (predicted == actual) {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> OK\n";
            correct_1bit++;
        }
        else {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> MISS\n";
            incorrect_1bit++;
            state_1bit = 1 - state_1bit;
        }
    }
    std::cout << "Correct = " << correct_1bit << "\nIncorrect = " << incorrect_1bit << "\n\n";

    std::cout << "2-bit Saturating Counter Predictor:\n";
    for (int i = 0; i < sequence.size(); ++i) {
        int counter = state_2bit[0] * 2 + state_2bit[1];
        char predicted = (counter >= 2) ? 'T' : 'N';
        char actual = sequence[i];

        if (predicted == actual) {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> OK\n";
            correct_2bit++;
            if (counter < 3) {
                if (counter == 0) state_2bit = { 0, 1 };
                else if (counter == 1) state_2bit = { 1, 0 };
                else if (counter == 2) state_2bit = { 1, 1 };
            }
        }
        else {
            std::cout << "Access " << (i + 1) << ": predicted = " << predicted << ", actual = " << actual << " -> MISS\n";
            incorrect_2bit++;
            if (counter > 0) {
                if (counter == 3) state_2bit = { 1, 0 };
                else if (counter == 2) state_2bit = { 0, 1 };
                else if (counter == 1) state_2bit = { 0, 0 };
            }
        }
    }
    std::cout << "Correct = " << correct_2bit << "\nIncorrect = " << incorrect_2bit << "\n";

    std::cout << "\nSummary:\n";
    std::cout << "Always Taken: " << correct_always << "/" << sequence.size() << " (" << (correct_always * 100.0 / sequence.size()) << "%)\n";
    std::cout << "1-bit: " << correct_1bit << "/" << sequence.size() << " (" << (correct_1bit * 100.0 / sequence.size()) << "%)\n";
    std::cout << "2-bit: " << correct_2bit << "/" << sequence.size() << " (" << (correct_2bit * 100.0 / sequence.size()) << "%)\n";

    return 0;
} 
