#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string I1 = "I1 (X=A+B)";
    string I2 = "I2 (Y=X*2)";
    string I3 = "I3 (Z=Y-3)";

 
    string stages[5] = { "IF", "ID", "EX", "MEM", "WB" };


    int posI1 = -1; 
    int posI2 = -1;  
    int posI3 = -1;

 
    bool I1_WB_done = false;
    bool I2_WB_done = false;

    int cycle = 1;

    while (posI1 < 5 || posI2 < 5 || posI3 < 5) {
        cout << "Cycle " << cycle << ":" << endl;

        


        if (posI1 >= 0 && posI1 < 5) {
            posI1++;
        }
        else if (posI1 == -1) {
            posI1 = 0; 
        }

        if (posI2 == -1) {
            if (I1_WB_done) {
                posI2 = 0;  
            }
        }
        else if (posI2 >= 0 && posI2 < 5) {
          
            if (posI2 == 2 && !I1_WB_done) {
              
            }
            else {
                posI2++;
            }
        }

        
        if (posI3 == -1) {
            if (I2_WB_done) {
                posI3 = 0;
            }
        }
        else if (posI3 >= 0 && posI3 < 5) {
        
            if (posI3 == 2 && !I2_WB_done) {
           
            }
            else {
                posI3++;
            }
        }


        if (posI1 >= 0 && posI1 < 5) {
            cout << "  Stage " << posI1 << ": " << I1 << " (" << stages[posI1] << ")" << endl;
        }
        else {
            cout << "  Stage 0: " << I1 << " (completed)" << endl;
        }

      
        if (posI2 == -1) {
            cout << "  Stage 0: " << I2 << " (waiting for I1)" << endl;
        }
        else if (posI2 >= 0 && posI2 < 5) {
            cout << "  Stage " << posI2 << ": " << I2 << " (" << stages[posI2] << ")" << endl;
        }
        else {
            cout << "  Stage 0: " << I2 << " (completed)" << endl;
        }

   
        if (posI3 == -1) {
            cout << "  Stage 0: " << I3 << " (waiting for I2)" << endl;
        }
        else if (posI3 >= 0 && posI3 < 5) {
            cout << "  Stage " << posI3 << ": " << I3 << " (" << stages[posI3] << ")" << endl;
        }
        else {
            cout << "  Stage 0: " << I3 << " (completed)" << endl;
        }

        cout << "-----------------" << endl;


        if (posI1 == 4) {  
            I1_WB_done = true;
        }
        if (posI2 == 4) { 
            I2_WB_done = true;
        }

        cycle++;
    }

    return 0;
}
