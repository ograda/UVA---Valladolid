#include <iostream>
#include <math.h>

using namespace std;

int C[100001], P[1000001], F[50], D[1000], n, q, nf, np, nd;
bool teste;

void GeraCrivo (int n)
{    int i, rq, t, d;
     for (i=1; i<=n; i++)   C[i] = i;
     for (i=2; i<=n; i+=2)  C[i] = 2;
     rq = sqrt(n);
     for (i=3; i<=rq; i+=2)
     {   if (C[i] == i)
         {   t = i*i;  d = i+i;
             while(t<=n)
             {   if (C[t] == t) C[t] = i;
                 t = t+d;
             }
         }
     }
}
void GeraPrimos (int n)
{    np=0;
     for (int i=2; i<=n; i++)
         if (C[i]==i)  P[++np]= i;
}

bool TestaPrimo (int q)
{    return (C[q] == q);
}

void Fatora (int q)
{    nf = 0;
     while(q != 1)
     {   F[++nf] = C[q];  q = q/C[q];
     }
}

void Divisores(int q)
{    int nda, k;
     F[0] = 1;  nd = 1;  D[1] = 1;  nda = 1;
     for (int i=1; i<=nf; i++)
     {   if (F[i] == F[i-1]) k = k*F[i];
         else
         {    nda = nd;  k = F[i];
         }
         for (int j=1; j<=nda; j++)
             D[++nd] = k*D[j];
     }
}

int main() {
n = 47000;
GeraCrivo(n);
GeraPrimos(n);
int qtd,a,b,c_flag,c_count;

    while (cin >> a, a) {
        cin >> b;
        qtd = 0;
        for (int i=a; i <= b; i++)
            if (TestaPrimo(i))
                    qtd++;
            else {
                Fatora(i);
                c_flag = 0;
                c_count = 0;
                for (int j=1; j<=nf; j++)
                    if (c_flag != F[j]) {
                        c_flag = F[j];
                        c_count += c_flag;
                    }
                if (TestaPrimo(c_count))
                    qtd++;
            }
        cout << qtd << endl;
    }

    return 0;
}
