//AC em 12/01/2013
//Anderson Zudio, Robson Eduardo
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
 long int S[100], n, cont, j, MN[100], MP[100];





void SCMM(){
     long int sm;
 sm=0;
 for (int i=1; i<=n; i++){

  if (S[i] > 0)
     {
         if(MP[i-1] != 0){ MP[i] = MP[i-1] * S[i]; if(MP[i] > sm) sm=MP[i];}
         else {MP[i] = S[i]; if(MP[i] > sm) sm=MP[i];}
         if(MN[i-1] != 0) MN[i] = S[i] * MN[i-1];
         else MN[i] = 0;
     }
  else if (S[i] < 0)
  {
     if(MN[i-1] != 0) {MP[i] = fabs(MN[i-1] * S[i]); if(MP[i] > sm) sm=MP[i];}
     else MP[i] = 0;
     if(MP[i-1] != 0) MN[i] = fabs(S[i] * MP[i-1]);
     else MN[i] = fabs(S[i]);
  }
  else {MP[i] = 0; MN[i] = 0;}


        }

        cout << "Case #" << cont << ": The maximum product is " << sm << "." << endl << endl;
}




int main()
{
cont = 0;
MP[0] = 0;
MN[0] = 0;
while(cin>>n){cont++;
    for (j=1; j<=n; j++) cin >> S[j];
    SCMM();
}



return 0;
}
