#include<cmath>
#include<cstdio>
#include<iomanip>
#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> squares;

int prep() {
    for(int i = 0; i < 10000; i++)
        squares.push_back(i * i);
}

int main() {
    prep();
    while(scanf("%d", &N) == 1) {
        for(int i = 0; i < squares.size(); i++) {
            if(squares[i] >= (int) pow(10, N)) break;
            if(pow(squares[i] % (int) pow(10, N / 2) + squares[i] / (int) pow(10, N / 2), 2) == squares[i]) \
                cout << setw(N) << setfill('0') << squares[i] << endl;
        }
    }
}
