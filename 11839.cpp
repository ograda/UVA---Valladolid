//Anderson Zudio de Moraes
//AC 25/11/2012

#include<iostream>
#include<string>
using namespace std;

int N, i, y, E;
bool p[260][7];

int main(){ cin >> N;

   for(;N!=0;)
    {
         //Entrada
         for (i=1;i<=N;i++)
         {
            for (y=1;y<=5;y++)
            {
                cin >> E;
                if (E < 128)
                 p[i][y] = 1;
                else
                 p[i][y] = 0;
            }

         }
         //Saída
         for (i=1;i<=N;i++)
         {
             if ((p[i][1] + p[i][2] + p[i][3] + p[i][4] + p[i][5]) == 1)
             {
              if (p[i][1] == 1)
               cout << "A" << endl;
              else if (p[i][2] == 1)
               cout << "B" << endl;
              else if (p[i][3] == 1)
               cout << "C" << endl;
              else if (p[i][4] == 1)
               cout << "D" << endl;
              else
               cout << "E" << endl;
             }
             else
              cout << "*" << endl;
         }

          cin >> N;
        }
        return 0;
    }
