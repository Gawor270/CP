#include <bits/stdc++.h>
#include <iostream>
//https://codeforces.com/problemset/problem/514/D
using namespace std;

const int MAXN = 1e6 + 6;
const int K = 100;
int st[K+1][MAXN];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int query(int L, int R){
    int length = R-L +1;
    int k = log2_floor(length);
    return gcd(st[k][L],st[k][R - (1 << k) + 1]);
}

bool check(int n,int level){
    for(int i=1; i<n; i++){
        if(st[level][i] != st[level][i-1])return false;
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> st[0][i];
    if(check(n,0)){
        cout << 0 << "\n";
        return;
    }

    for(int i=1; i<=K; i++){
        for(int j=0; j<n; j++){
            st[i][j] = gcd(st[i-1][j],st[i-1][(j+1)%n]);
        }
        if(check(n,i)){
            cout << i << "\n";
            return;
        }
    }

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

