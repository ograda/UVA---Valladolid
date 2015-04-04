#include <iostream>
using namespace std;

long long int MDC(long long int a, long long int b) {
    if (b) return MDC(b, a % b);
    return a;
}

long long int MMC(long long int a, long long int b){
	return ( a * b ) / MDC(a, b);
}

int main(){
	int n;
	long long int a,b,c,i;
	cin >> n;
	while( n-- ) {
		cin >> a >> c;
		if ( c % a )
			cout << "NO SOLUTION" << endl;
		else {
            b = c / a;
			for ( i = b; i <= c; i += b )
               if (MMC(a,i) == c) break;
			cout << i << endl;
		}
	}
	return 0;
}
