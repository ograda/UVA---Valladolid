#include <math.h>
#include <iostream>
 
using namespace std;
 
unsigned long long Pow(unsigned long long n, int x){
    unsigned long long ret = 1, b = n;
 
    for (int b=0; b<x; b++)
        ret *= n;
 
    return ret;
}
 
int main() {
    unsigned long long n;
        // http://en.wikipedia.org/wiki/Burnside's_lemma
        while (cin >> n, n)
            cout << (Pow(n,6) + 3*Pow(n,4) + 12*Pow(n,3) + 8*Pow(n,2))/24 << endl;
 
    return 0;
}
