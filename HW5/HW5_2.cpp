#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int i, a, b, j;
    double zerorate[5];
    double forward[6][6];
    for(i= 0; i< 5; i++){
        cout << "type the " << i << "th zero rate:";
        cin >> zerorate[i];
    }
    for(i= 0; i< 5; i++){
        forward[0][i + 1] = zerorate[i];
    }
    for(i= 0; i<= 5; i++){
        forward[i][i] = 0;
    }
    for(a= 1; a< 5; a++){
        for(b= a+ 1; b<= 5; b++){
            forward[a][b] = pow(pow(1 + forward[0][b], b) / pow(1 + forward[0][a], a), 1.0 / (b - a)) - 1;
        }
    }
    for(i= 0; i< 6; i++){
        for(j= i; j< 6; j++){
            printf("f(%d,%d)=%lf\n", i, j, forward[i][j]);
        }
    }
    system("pause");
    return 0;
}
