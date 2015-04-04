#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int i,j,n,r,c,qualquer, T[101][101]={{-1}}, M[101][101]={{-1}};
string nome;

int Snowboards(int x, int y){
	if ( T[x][y] != -1 ) {
		int maiores=0;
		if (y==0) {
			++maiores;
			if (M[x][y+1] > M[x][y]) ++maiores;	

		} else if (y==c-1) {
			++maiores;			
			if (M[x][y-1] > M[x][y]) ++maiores;
		} else {
			if (M[x][y+1] > M[x][y]) ++maiores;
			if (M[x][y-1] > M[x][y]) ++maiores;
		}

		if (x==0) { 
			++maiores;			
			if (M[x+1][y] > M[x][y]) ++maiores;

		} else if (x==r-1) {
			++maiores;
			if (M[x-1][y] > M[x][y]) ++maiores;
		} else {
			if (M[x+1][y] > M[x][y]) ++maiores;
			if (M[x-1][y] > M[x][y]) ++maiores;
		}

		if (maiores==4) { T[x][y]=0; cout<<"Achei caso infantil em ("<<x<<","<<y<<")."<<endl;}
		else { //recursão!
			
			int maiorT=0;
			
			if (y==0) {
				if (T[x][y+1] > maiorT) maiorT = T[x][y+1];	

			} else if (y==c-1) {
				if (T[x][y-1] > maiorT) maiorT = T[x][y-1];
	
			} else {
				if (T[x][y+1] > maiorT) maiorT = T[x][y+1];	
				if (T[x][y-1] > maiorT) maiorT = T[x][y-1];
			}

			if (x==0) {
				if (T[x+1][y] > maiorT) maiorT = T[x+1][y];	

			} else if (x==r-1) {
				if (T[x-1][y] > maiorT) maiorT = T[x-1][y];
	
			} else {
				if (T[x+1][y] > maiorT) maiorT = T[x+1][y];	
				if (T[x-1][y] > maiorT) maiorT = T[x-1][y];
			}
			
			T[x][y] = maiorT+1;
			return T[x][y];
		}
	} else { //Já está preenchido em T
		return T[x][y];
	}

/*	if ((q<0)||(p==0)){
	return 0;}
    else{
		if (q==0) {
			return 1;}
		else{	
    	if (T[p][q]!=-1){
		    return T[p][q];}
		else{	 
   			T[p][q]= Moedas(p, q-V[p])+Moedas(p-1,q);
        	return T[p][q];}}}
*/
/*	Se       (q < 0) Ou (p = 0) Então Retornar 0
    Senão Se (q = 0) Então Retornar 1
	Senão Se (T[p,q] <> -1) Então Retornar T[p,q]
    Senão
        T[p,q] <- Moedas(p, q-V[p])+Moedas(p-1,q);
        Retornar T[p,q];
    Fs;
*/
}
int main(){
	cin>>n;
    	while(n){
		cin>>nome;
		cin>>r>>c;
		for(i=0;i<r;++i) 
			for(j=0;j<c;++j) cin>>M[i][j];

        	qualquer = Snowboards(0,0);
		cout<<nome<<": "<<qualquer<<endl;

		--n;
	}
	return 0;
}
