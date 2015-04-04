//Anderson Zudio
//AC em 22/01/2013
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char P[1000100], T[1000100];
int n, F[1000100], cont;


void Resto()
{
   for(int i=cont+1; i < n;i++)
   {
       cout << P[i];
    }
    cout << endl;
}



void KMP2(){
    int i,j,k;
    //Preprocessamento
    F[0] = -1;  j = -1;  i = 0;
    while (i < (n-1)) {
        if (P[i+1] == P[j+1]){ j++; F[++i] = j; }
        else if (j = -1)  F[++i] = -1;
        else j = F[j];
    }
    //Busca
    i=-1;  j=-1;
    while (i <= n){
        while (j < (n-1)){
            if (P[j+1] == T[i+1]){ i++;  j++; cont = j;}
            else break;
        }
        if (j == -1) i++;
        else j = F[j];
    }
}

int main()
{
    int i, j;
    while(cin >> T)
    {
    cont = 0;
    n = strlen(T);
    memset(P, 0 , 1000100);
    for(int i = n-1, j = 0; i >= 0; i--, j++) P[j] = T[i];
    KMP2();
    cout << T;
    Resto();
    }
}
