#include <iostream>
#include <string.h>

using namespace std;

int verifica(int i, int j, int val, int a){
    if (j%2){

       int sub=a-j;
       if (sub>=val){
          i-=1;
          j=sub-val+1;}
       else{

          j=val-sub;
       }
    }
    else{
       int sub=a-i;
       if (sub>=val){
          j-=1;
          i=sub-val+1;}
       else{
          i=val-sub;
       }
    }
    cout << i << " " << j << endl;
    }

int main()
{
    int n,i,j,ant;
    cin>> n;
    while (n){
    int aux=0,atual=1;
    for (i=1;atual<n;++i){
          atual+=i*2;}
//    cout << "i = " << i;
//    cout << "atual = " << atual;
    j=i;
    verifica(i,j,n,atual);
    cin>> n;
    }
return 0;
}
