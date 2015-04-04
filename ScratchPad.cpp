//Anderson Zudio de Moraes
//Victor Cracel Messner
//BOCA AC em 06/04/2014
#include <iostream>
using namespace std;
int T;
long long int n;
int primos[10] = {2,3,5,7,11,13,17,19,23,29};

int PotMod(int a, int b, int n){
    long long int m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++){
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
        //cout << rb[j] << " " << c << " " << d <<endl;
    }
    return (int) d;
}

int main(){
    bool achei;
    cin >> T;
    while(T--){
        cin >> n;
        achei = true;
        for(int i = 0; i < 10; i++)
        {
            if(PotMod(primos[i], n, n) != primos[i])
            {
                cout << "N" << endl;
                achei = false;
                break;
            }
        }
        if(achei) cout << "S" << endl;

    }
    return 0;
}
