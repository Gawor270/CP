#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4 + 5;
const int K = 20;

int st[K+1][MAXN];
int bin_log[MAXN];

int query(int L, int R){
    int len = R - L + 1;
    int k = bin_log[len];
    return max(st[k][L],st[k][R - (1<<k) +1]);
}

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void preprocess(int N){
    bin_log[1] = 0;
    for(int i=2; i<=N; i++){
        bin_log[i] = bin_log[i/2]+1;
    }

    for(int i=1; i<=K; i++){
        for(int j=0; j + (1 << i) -1 <N; j++){
            st[i][j] = max(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
    } 
}

int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++)cin >> st[0][i];
    preprocess(N);
    int count = 0;
    while(M--){
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        if(A == B)count++;
        else if(A < B && query(A,B-1) == st[0][A])count++;
        else if(A > B && query(B+1,A) == st[0][A])count++;
    }
    cout << count << "\n";

    return 0;
}

