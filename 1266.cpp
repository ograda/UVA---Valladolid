//Anderson Zudio
//Pedro Felizola
//07/03/2013

#include <iostream>
#inlcude <math.h>

using namespace std;

int c[16][16];

void Zera(int n)
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
				c[i][j]=0;
}
void wrap() {
	if (x>=n) x-=n;
	if (x<0) x+=n;
	if (y>=n) y-=n;
	if (y<0) y+=n;
}

int main(){

    int n, n2, i, j, max, x, y, teste;
    teste = 0;
while(cin>>n)
	{
	    if(teste) cout<<endl; else teste = 1;

    Zera(int n);
    s = 0;
    n2 = n*n;
    while(n2>0)
	{
		n2/=10;
		max++;
	}
    cin.get();
    x = (n/2); y = 0; i = 1;
    /*while(i<=n*n) {
			qm[x][y] = i;
			x++;
			y--;
			wrap();
			if(qm[x][y]>0) {
				y+=2; x--; wrap();
			}
			i++;
		}*/

		for(x=0;x<n;x++) s+=qm[x][0];

		cout<<"n="<<n<<", sum="<<s<<endl;
		for(y=0;y<n;y++) {
			for(x=0;x<n;x++) {
				cout<<string(maxl-getlength(qm[x][y])+1,' ')<<qm[x][y];
			}
			cout<<endl;
		}
	}
	return 0;
}
