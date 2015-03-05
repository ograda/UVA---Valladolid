#include <cstdio>
#include <iostream>
using namespace std;
 
int  a, c;
 
int MDC(int a, int b) {
    if (b) return MDC(b, a % b);
    return a;
}
 
int MMC(int a, int b){
        return ( a * b ) / MDC(a, b);
}
 
int main(){
        int n,b,i,mdc;
        cin >> n;
        while( n-- ) {
                cin >> a >> c;
                b = c / a;
                if ( c % a )
                        cout << "NO SOLUTION" << endl;
                else {
                        for ( i = b; i <= c; i += b )
               if (MMC(a,b) == c)
                    break;
                        cout << i << endl;
                }
        }
        return 0;
}
