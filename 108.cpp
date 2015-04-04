//AC em
// SCSM (Sequência Consecutiva de Soma Máxima),
//Anderson Zudio
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int S[150], n, M[150][150], soma, aux;


int SCSM(int X[150], int x){
    int sm, ss;
	sm=0;
	ss=0;
	for (int k=1; k<=x; k++){
		if ((ss + X[k]) >= 0){
			ss=ss + X[k];
			if (ss > sm){
                sm=ss;
            }
        }
		else{
			ss=0;
        }
	}
	return sm;
}


int main()
{   cin >> n;
    aux = 0;
    for (int g=1; g<=n; g++){
    for (int j=1; j<=n; j++)
    {
        cin >> M[g][j];
    }
    }

    for(int z = 1; z<=n; z++)
    {
        for(int y=1;y<=n;y++){ S[y] = 0;}

        for(int i=z;i<=n;i++)
        {
         for(int j=1;j<=n;j++)
          {
            S[j] = S[j] + M[i][j];
          }

          aux = SCSM(S,n);
          if(aux > soma) soma = aux;

        }

    }

    cout << soma << endl;
    return 0;
}
