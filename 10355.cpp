#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define QZERO 0.0000000001
#define ABS(a,b) ((a) >= (b)) ? a-b : b-a
#define PI acos(-1)
 
using namespace std;
   
int main() {
char city[10];
int x1, y1, z1, x2, y2 , z2;
int Px,Py,Pz, rad;
int rs, a, b , c;
double T1, T2;
cout.setf(ios::fixed);
    while(cin >> city >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> rs) {
        // parametrização (x-x0)² + (y-y0)² + (z - z0)² = R²
        // At² + Bt + C = 0
        // delta < = 0 sem interceptação delta
        // t > 1 intercepta depois do caminho
        // t < 0 intercepta antes
        //  0 <= t <= 1 area de interceptação
        double delta, pctg;
        double A,B,C;
        pctg = 0.0;
        while (rs--) {
            cin >> Px >> Py >> Pz >> rad;
            a = (x2-x1);
            b = (y2-y1);
            c = (z2-z1);
            A = (a*a) + (b*b) + (c*c);
            B = 2*((a*(x1-Px)) + (b*(y1-Py)) + (c*(z1-Pz)));
            C = (x1*(x1-(2*Px))) + (y1*(y1-2*Py)) + (z1*(z1-2*Pz)) + (Px*Px) + (Py*Py) + (Pz*Pz) - (rad*rad);
       //     cout << "a = " << a << "b = " << b << "c = " << c << endl;
       //      cout << "A = " << A << "B = " << B << "C = " << C << endl;
        //  B = (2*a*x1) - (2*Px*a) + (2*b*y1) - (2*Py*b) + (2*c*z1) - (2*Pz*c)
        //  C = (x1*x1) - (2*Px*x1) + (y1*y1) - (2*Py*y1) + (z1*z1) - (2*Pz*z1) + (Px*Px) + (Py*Py) + (Pz*Pz) - (rad*rad)
           // (x1*x1) + 2*a"T" - 2*a*"T"*x1 - 2*rad*(x1+a"T") + (rad*rad)
           delta = (B*B) - 4*A*C;
          // cout << "delta = " << delta << endl;
           if (delta > 0) {
              delta = sqrt(delta);
              T1 = (-B + delta)/(2*A);
              T1 = min(max(T1,0.0),1.0);
              T2 = (-B - delta)/(2*A);
              T2 = min(max(T2,0.0),1.0);
              pctg += 100*((T1>T2) ? (T1-T2) : (T2-T1));
              cout.precision(4);
          //    cout << "delta = " << delta << " t1 = " << T1 << " t2 = " << T2 << " pctg = " << pctg << endl;
           }
        }
        cout.precision(2);
        cout << city << endl << pctg << endl;
       
      //  cout << "teste pos " << x1 << " - " << y1 << " - " << z1 << " - " << x2 << " - " << y2 << " - " << z2 << " - " << rs << endl;
       
       /*
        x = acos(  (l2*l2 - l1*l1 - l3*l3)  /(((-2) * l1 * l3)));
        y = acos(  (l1*l1 - l2*l2 - l3*l3)  /(((-2) * l2 * l3)));
        z = acos(  (l3*l3 - l1*l1 - l2*l2)  /(((-2) * l1 * l2)));
        */
    }
   
    return 0;
}
