//Anderson Zudio
//Victor Cracel Messner
//Julio Cesar
//AC em 28/04/2014


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int t, cont, S, P, n, m, K, i, j, k, l, Satual, Patual, g, h, M[110][110];
    cin >> t;
    cont = 0;
    while(t--)
    {

        cin >> n >> m >> K;

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                cin >> M[i][j];

        for(i = 1; i <= n; i++)
            for(j = 2; j <= m; j++)
                 M[i][j] += M[i][j-1];

        S = P = 0;
        for(j = 1; j <= m; j++)
        {
            if(j > 1)
                for(g = 1; g <= n; g++)
                    for(h = j; h <= m; h++)
                        M[g][h] -= M[g][j-1];

            for(k = j; k <= m; k++)
            {
                Satual = Patual = 0;
                for(i = 1, l = 1; i <= n; i++)
                {
                    Patual += M[i][k];
                    if(Patual > K)
                    {
                        while(Patual > K)
                        {
                            Patual -= M[l++][k];
                        }
                    }
                    Satual = (i - l + 1)*(k - j + 1);
                    if(Satual > S)
                    {
                        S = Satual;
                        P = Patual;
                    }
                    else if(Satual == S)
                        if(Patual < P) P = Patual;
                }
            }

        }


        cout << "Case #" << ++cont << ": " << S << " " << P << endl;
    }
    return 0;
}
