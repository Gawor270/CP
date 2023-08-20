#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e7 + 7;
const int K = 25;

int st[K+1][MAXN];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void preprocess(){
    for(int i=1; i<=K; i++){
        for(int j=0; j + (1 << i) <=MAXN; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
    } 
}

int main(){
    int N,Q;
    cin >> N;
    for(int i=0; i<N; i++)cin >> st[0][i];
    preprocess();
    cin >> Q;
    while(Q--){
        int i,j;
        cin >> i >> j;
        int k = log2_floor(j-i+1);
        cout << min(st[k][i],st[k][j - (1<<k)+1]) << "\n";
    }

    return 0;
}

