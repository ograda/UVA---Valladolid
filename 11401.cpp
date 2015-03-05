#include <math.h>
#include <iostream>
 
using namespace std;
 
unsigned long long Resp[1000001];
 
int main() {
    unsigned long long n;
 
        Resp[3] = 0;
        for(unsigned long long i = 4; i < 1000001; i++) {
            // n impares geram um somatorio par
            // numeros pares geram um somatorio ímpar
                        Resp[i] = (i % 2) ? (1+(i-3)/2)*(i-3)/2 : (1+(i-4)/2)*(i-4)/2 + i/2 - 1;
            Resp[i] += Resp[i-1];
        }
 
        while (cin >> n && n > 2)
            cout << Resp[n] << endl;
 
    return 0;
}
