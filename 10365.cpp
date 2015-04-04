//Anderson Zudio de Moraes
//AC em 6/12/2012
#include<iostream>
#include <stdio.h>
#define bignum 1000000

using namespace std;

int main(){

    int C, N, area, num, k;


    cin >> C;

    for(int o = 1;o<=C;o++)
    {
        cin >> N;
        num = bignum;

        for(int i=1;i<=N;i++)
        {
           if((N % i) == 0)
           {
           for(int j =1; j<=N/i;j++)
           {
               if((N %(i*j)) == 0)
               {
                  k = N/i/j;
                  if (k < j) break;

                  if(i*j*k == N)
                  {
                      area = ((i*j) + (j*k) + (i*k)) *2;
                      num = area < num ? area : num; //menor área

                  }
               }

           }

        }
      }
      cout << num << endl;
    }
    return 0;
}
