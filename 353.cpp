//Anderson Zudio, Beatriz Tantow
//AC em 19/01/2013
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;

char P[1000001];
int n, m, F[1000001], R[256], aux[256], N, t, aux2[81];
string T, G;


set <string> V;
set <string>::iterator it;


bool palindrome(int a, int b)
{
    int u =a; int w=b;
    while(u <= w)
    {
      if (T[u] != T[w])
         {
            return 0;
         }
       w--; u++;
    }
   return 1;
}

int main()
{
    while(cin >> T)
    {
        V.clear();
        n = T.size();
        for(int i =0; i < n; i++)
        {
             for(int j =i; j < n; j++)
             {
                  if (T[i] == T[j])
                  {
                    if(palindrome(i,j))
                    {
                        G = "";
                          for(int k = i; k <= j; k++ ) G += T[k];
                        V.insert(G);
                    }
                  }
             }
        }
        cout << "The string '" << T << "' contains " << V.size() << " palindromes." << endl;
    }
}
