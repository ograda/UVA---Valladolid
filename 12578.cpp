//Anderson Zudio
//02/03/2013

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    int t, i, L;
    double r, H, a, ac;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> L;
        H = (L*60)/100; r = (L*20)/100;
        ac = acos(-1)*r*r;
        a = (L*H) - ac;
        cout.setf(ios_base::fixed);
        printf("%.2f %.2f\n", ac, a );
    }
}
