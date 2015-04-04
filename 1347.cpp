#include<iostream>
#include<cmath>
#include <cstdio>

using namespace std;
typedef struct {double x, y;}Ponto;
typedef struct {Ponto p, q;}Segmento;
Ponto pol[100000];

double DistPontos(Ponto p1, Ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long double a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
}

void Quicksort(int e, int d)
// O ponto 0 fica fixo na ordenação, pois tem o menor x
{  int i,j,k;  Ponto t,r;  long long d0, d1, d2;
   if (d > e)
   {  i=e;  j=d;  t=pol[(e+d)/2];
      d1= pol[0].x-t.x;  d2= pol[0].y-t.y;  d0=d1*d1+d2*d2;
      while(i<=j)
      {  while(1)
         {  k=SentidoPercurso(pol[0],pol[i],t);
            if (k==1) i++;
            else if (k==0)
            {  d1= pol[0].x-pol[i].x;  d2= pol[0].y-pol[i].y;  d1= d1*d1+d2*d2;
               if (d1 < d0) i++;
               else break;
            }
            else break;
         }
         while(1)
         {  k=SentidoPercurso(pol[0],t,pol[j]);
            if (k==1) j--;
            else if (k==0)
            {  d1= pol[0].x-pol[j].x;  d2= pol[0].y-pol[j].y;  d1= d1*d1+d2*d2;
               if (d0 < d1) j--;
               else break;
            }
            else break;
         }
         if (i<=j) {r=pol[i];  pol[i]=pol[j];  pol[j]=r;  i++; j--;}
      }
      Quicksort(e,j);  Quicksort(i,d);
   }
}

void OrdenaPontosx(int tp)
/* Ordena pontos por ângulo, escolhendo como referência o ponto mais à esquerda e mais
   embaixo. */
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++)
      if ((pol[i].x < pol[m].x)||(pol[i].x==pol[m].x)&&(pol[i].y<pol[m].y)) m=i;
   p=pol[0];  pol[0]=pol[m];  pol[m]=p;
   Quicksort(1,tp-1);
}

void CaminhoFechado(int tp)
/* Ordena pontos e, ao final da ordenação, se houver pontos colineares com
   o ponto inicial, no final do vetor, a ordem dos pontos colineares é invertida. */
{  int i,m;  Ponto p;
   OrdenaPontosx(tp);
   i = tp-1;  while ((i>0)&&(SentidoPercurso(pol[0],pol[i-1],pol[i])==0)) i--;
   for (m=i; m<(i+tp)/2;m++) {p=pol[m]; pol[m]=pol[tp-1-m+i]; pol[tp-1-m+i]=p;}
}



int main()
{
    int n, i;
    double dist;
    while(cin >> n)
    {
        dist = 0.045;
        for(i = 1; i <= n;i++)
            cin >> pol[i].x >> pol[i].y;
         CaminhoFechado(n);
         pol[n].x = pol[0].x;  pol[n].y = pol[0].y;
          for(i = 1; i <= n;i++)
             dist += DistPontos(pol[i], pol[i+1]);

          cout.setf(ios_base::fixed);
        cout.precision(2);
         cout << dist << endl;

    }

}

