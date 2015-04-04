//AC em 07/12/2012
//Anderson Zudio de Moraes, Robson Eduardo

#include <iostream>
#include <stdio.h>


using namespace std;

int soma(int x){
    int a, b;
    a = x % 10;
    b = ((x - a) / 10) ;
    if (b <= 0) return a;
    else return a + soma(b);

}


int main(){

    unsigned long int m, n, i, j, DDF[10500], DDFnum, k, Resposta[10500], max, temp, cont, z, tempm;


    cont = 0;

    cin >> m >> n;

    while(m != 0 && n != 0)
    {
        cont++;
        max = 0;
        tempm = m;

        for(m; m <= n; m++)
        {
          DDF[0] = m;

          for(j=1;;j++)
          {

           DDFnum = 0   ;
           for(i = DDF[j-1]; i >= 1; i--)
           {
             if(DDF[j-1] % i  == 0) DDFnum = DDFnum + soma(i);
           }

           DDF[j] = DDFnum;
           k = 0;
           z = 0;
           //verifica
           while (k == 0 &&  z < j)
           {
               if (DDF[z] == DDFnum)
               k = 1;
               z++;
           }
           if(k == 1){ temp = j-1; break;}
          }

             if(max < temp)
             {
                 max = temp;
                 for(int y = 0;y <= max;y++)
                 Resposta[y] = DDF[y];
             }

          }

          cout << "Input" << cont << ": " << tempm << " " << n << endl;
          cout << "Output" << cont << " :" ;
          for (int g = 0;g<= max;g++)
	            cout << " " << Resposta[g];
	            cout << endl;

          cin >> m >> n;

}

}
