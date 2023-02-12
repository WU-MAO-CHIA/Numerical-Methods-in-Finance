#include <iostream>
using namespace std;

int main() {
    float interest[2][7];
    for(int j= 0; j < 7; j++){
        interest[0][j] = 0.01;
    }
    interest[1][0] = 0.01075;
    interest[1][1] = 0.01125;
    interest[1][2] = 0.01175;
    interest[1][3] = 0.01225;
    interest[1][4] = 0.01525;
    interest[1][5] = 0.0155;
    interest[1][6] = 0.0155;

    for(int j = 0; j < 7; j++){
        cout << "[" << 0 << "," << j << "] - [ " << 1 << "," << j << "]:"<< interest[0][j] - interest[1][j] << "\t";
    }
    return 0;
}
