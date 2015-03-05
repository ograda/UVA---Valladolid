#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int Arr[N];
        int menos = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &Arr[i]);
            int L = 0;
            for (int j = 0; j < i; j++)
                L += (Arr[j] <= Arr[i]);

            menos += L;
        }
        printf("%d\n", menos);
    }
    return 0;
}
