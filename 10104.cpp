#include<iostream>
#include <stdio.h>

using namespace std;
int a, b, x, y, d;

int mdc(int a, int b, int* x, int* y) {
    int xx, yy, d;
      if(!b) {
        *x=1;
        *y=0;
        return a;
      }

    d = mdc(b, a%b, &xx, &yy);
    *x = yy;
    *y = xx - (a/b)*yy;
  return d;
}

int main() {
    while (scanf("%i %i", &a, &b) == 2) {
        d = mdc(a, b, &x, &y);
        cout << x << " " << y << " " << d << endl;
    }
    return 0;
}