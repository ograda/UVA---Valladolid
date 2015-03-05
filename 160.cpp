#include <iostream>
#include <cstdio>
using namespace std;
int prime[10005];
int use[4005];
int main (){
    int x=0;
    for(int i=2;i<4005;i++){
        if(use[i] == 0){
            prime[x] = i;
            x++;
            for(int j=i+i;j<4005;j+=i)use[j] = 1;
        }
    }
    int Z,a,b,c;
    //cin >> Z;
    scanf("%d",&Z);
    while(Z--){
        //cin >> a >> c;
        scanf("%d%d",&a,&c);
        if(c % a != 0){
            //cout << "NO SOLUTION\n";
            printf("NO SOLUTION\n");
            continue;
        }
        b = 1;
        int cnt1,cnt2;
        for(int i=0;i<x;i++){
            cnt1 = 0;
            cnt2 = 0;
            if(a == 1)break;
            while(a % prime[i] == 0){
                cnt1++;
                a/=prime[i];
            }
            while(c % prime[i] == 0){
                cnt2++;
                c/=prime[i];
            }
            if(cnt1 < cnt2){
                for(int j=0;j<cnt2;j++)b *= prime[i];
            }
        }
        b*=c/a;
        //cout << b << "\n";
        printf("%d\n",b);
    }
    return 0;
}
