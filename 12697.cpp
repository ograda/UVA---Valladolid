//Anderson Zudio Moraes
//Julio Cesar
//Victor Cracel Messner
//AC 02/05/2014

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int S[500005], n, x, tamanho;

void SCSM(){
    long long int ss, sst;
    int atamanho, atamanhot, cs, cst;
	ss = atamanho = cs = 0;

	for( int i = 1; i <= n; i++ ) {
		if( ( ss + S[i] ) >= 0 ) {
			ss += S[i];
			atamanho++;
			if( cs == 0 ) cs=i;
			if( ss >= x ) {
                    sst = ss;
                    atamanhot = atamanho;
                    cst = cs;
                    while(cst <= i)
                    {
                        if(sst >= x)
                        {
                            if(tamanho == -1) tamanho = atamanhot;
                            else tamanho = min(tamanho, atamanhot);
                        }
                        sst -= S[cst++];
                        atamanhot--;
                    }
            }
        }
		else {
			ss = cs = atamanho = 0;
        }
	}
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(int i = 1; i <= n; i++)
            cin >> S[i];

        tamanho = -1;

            SCSM();

        cout << tamanho << endl;
    }
}
