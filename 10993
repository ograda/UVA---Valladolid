#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
int resto[100001];
char output[100001];
char str[11];
int  dig[11], lim, n;
 
typedef struct dataVector {
    char digito;
    int resto;
    int idgerador;
} Trio;
 
std::vector <Trio> solution(10000);
 
void organizar(int n) {
    int x,y, aux;
 
    while(str[lim] != '\0') {
        dig[lim] = str[lim] - '0';
        lim++;
    }
 
    for( x = 0; x < lim; x++ )
        for( y = x + 1; y < lim; y++ )
           if (dig[x] > dig[y]) {
             aux = dig[x]; dig[x] = dig[y]; dig[y] = aux;
          }
}
 
void procurar(int id_fila) {
    int i, r, s;
    Trio T,New;
 
    while ( id_fila < solution.size() ) {
        T = solution.at(id_fila);
        for( i = 0; i < lim; i++ ) {
            New.digito = dig[i];
            New.idgerador = id_fila;
            r = (dig[i]+(T.resto*10)) % n;
            New.resto = r;
                if (!resto[r]++)
                        solution.push_back(New);
                        if (!r) return ;
        }
        id_fila++;
    }
}
 
char *rev_str(char *s) {
  char *last=s, *first=s, temp;
 
  while(*last) ++last;
 
  for(last--; first<last; ++first, --last) {
        *first ^= *last ^= *first ^= *last;
  }
 
  return s;
}
 
int main() {
    int i=0, r;
    Trio vetor;
 
    while(scanf("%s %i", str,&n) == 2 && n) {
        memset(dig, 0, 11*sizeof(int));
        lim = 0;
        organizar(n);
        if (lim < 10 && !(lim == 1 && dig[0] == 0)) {
            memset(resto, 0, n*sizeof(int));
            for( i = 0; i < lim; i++ ) {
                if (!dig[i]) continue;
                vetor.digito = dig[i];
                vetor.idgerador = -1;
                r = dig[i] % n;
                vetor.resto = r;
                if (!resto[r]++)
                    solution.push_back(vetor);
                    if (!r) break;
            }
 
            if (resto[0])
                printf("%d\n",vetor.digito);
            else {
                procurar(0);
                vetor = solution.back();
                if (vetor.resto) printf("impossible\n");
                else {
                    output[i=0] = vetor.digito + '0';
                    while (vetor.idgerador >= 0) {
                       vetor = solution.at(vetor.idgerador);
                       output[++i] = vetor.digito + '0';
                    }
                    output[++i] = '\0';
                    printf("%s\n",rev_str(output));
                }
            }
 
        if (!solution.empty())
            solution.erase(solution.begin(),solution.end());
 
        }
        else
            if (lim == 1 )
                printf("impossible\n");
            else
                printf("%d\n", n);
    }
    return 0;
}
