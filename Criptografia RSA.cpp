//Anderson Zudio de Moraes
//Victor Cracel Messner
//BOCA

#include <iostream>
#include <math.h>
using namespace std;

typedef struct ret { int d; int x; int y;};
int a, b; ret r;


int MDC(int a, int b)
{   if (b == 0) return a;
    else return MDC(b, a % b);
}

ret MDCE(int a, int b, ret ra)
{   int xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else
    {   ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }
    return ra;
}

int main()
{

    int t, p, q, e , d, i;
    long long int n, phi;
    cin >> t;



    while (t--)
    {
        cin >> p >> q;
        n = p*q;
        phi = (p-1)*(q-1);
        for(i = 2; i < phi; i++)
        {
            if(MDC(phi,i) == 1)
            {
                e = i;
                break;
            }
        }

        r = MDCE(e, phi, r);
        if(r.x < 0) d = phi+r.x;
        else d = r.x;
        cout << e << " " << d << " " << n << endl;


    }
    return 0;
}
