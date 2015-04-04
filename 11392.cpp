#include <iostream>
#include <string.h>

using namespace std;

int limite[2000001];

int main() {
    int n, tamanho, i, j;
    while(cin >> n, n) {
        if (n == 3 || n == 1)
            cout << "1 1 0" << endl;
        else {
            memset(limite, 0, n*4); // zera vetor limite
            i = 2; // n de digitos
            j = 3 % n; // n de casas necessárias para representar o resto do numero
            limite[j] = 2; // qts de 0 + 1
            limite[0] = 1; // finaliza a condição (quando o resto da divisão é 0
            while(i++) {
                //cout << "i = " << i << " j = " << j << " (n=" << n << ")" << endl;
                j = ((10*j)+3) % n;
                if(limite[j]) {
                    cout << (i-1) << " " << i-limite[j] << " " << limite[j]-1 << endl;
                    break;
                }
                limite[j] = i;
            }
        }
    }
    return 0;
}