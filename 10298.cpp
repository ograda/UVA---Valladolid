//Algoritmos de Busca em String: Knuth-Morris-Pratt, Boyer-Moore, Rabin-Karp
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char P[1000001], T[1000001];
int n, m, F[1000001], R[256];

int KMP(){
    int i,j,k, soma = 0;
    //Preprocessamento
    F[0] = -1;  j = -1;  i = 0;
    while (i < (m-1)) {
        if (P[i+1] == P[j+1]){ j++; F[++i] = j; }
        else if (j = -1)  F[++i] = -1;
        else j = F[j];
    }
    //Busca
    i=-1;  j=-1;
    while ((i-j) <= (n-m)){
        while (j < (m-1)){
            if (P[j+1] == T[i+1]){ i++;  j++;}
            else break;
        }
        if (j == (m-1)) {
                soma++;}
        if (j == -1) i++;
        else j = F[j];
    }
    return soma;
}

int main()
{
    int r;
    while(cin >> T, T[0] != '.')
    {
        n = strlen(T);
        P[0] = '\0';
        for(int i = 0, m = 1; i < n/2; i++, m++){
            P[i] = T[i];
            P[i+1] = '\0';
            r = KMP();
            if(r){
                cout << r << endl;
                break;
            }
        }
    }
    return 0;
}
