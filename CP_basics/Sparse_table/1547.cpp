#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// doesn't work

const int MAXN = 1e6 + 6;
const int K = 20;
int st[K+1][MAXN];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void preprocess(int N){
    int K = log2_floor(N);
    int g = st[0][0];
    for(int i=1; i<N; i++){
        g = gcd(g,st[0][i]);
    }
    for(int i=0; i<N; i++)st[0][i]/=g;

    // initialize sprarse table for every type of detail
    for(int i=1; i<=K; i++){
        for(int j=0; j + (1 << i) <=MAXN; j++){
            st[i][j] = gcd(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
    } 
}

int query(int L, int R){
    int length = R-L +1;
    int k = log2_floor(length);
    return gcd(st[k][L],st[k][R - (1 << k) + 1]);
}



void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> st[0][i];

    preprocess(n);

    int mx= 0;
    int i =0, j=0;
    while(j<n){
        if(query(i,j) > 1){
            j++;
            mx = max(mx,j-i+1);
        }
        else{
            i++;
            j = max(i,j);
        }
    }


    cout << mx << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

