#include <iostream>
#include <math.h>
using namespace std;

int C[10000001], P[1000001], rq, nf, np, nd;
long long int n, q, F[50], D[10000];

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
void GeraPrimos (int rq)
{    np=0;
     for (int i=2; i<=rq; i++)
         if (C[i]==i)  P[++np]= i;
}

bool TestaPrimo (long long int q)
{    bool primo = true;
     for (int i=1; i<=np; i++)
     {   if ((q % P[i]) == 0)
         {   if (q != P[i]) primo = false;
             break;
         }
     }
     return (primo);
}

int main()
{   rq = 10000000;  n = rq;  n = n*n;
    GeraCrivo(rq);
    GeraPrimos(rq);
	int p;

	while(cin >> n,n) {
        n = (n<0) ? -n:n;
        p=0;
		if ( TestaPrimo(n) )
			cout << "0" << endl;
		else {
            while(P[p] < n )
                p++;
            cout << P[p]-P[p-1] << endl;
		}
	}
	return 0;
}
