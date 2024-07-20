#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 1e6 + 6;
const int K = 100;
int st[K+1][MAXN];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

bool powerof2(int x){
    return x && !(x & (x-1));
}

int query(int L, int R){
    int length = R-L +1;
    int k = log2_floor(length);
    return __gcd(st[k][L],st[k][R - (1 << k) + 1]);
}

int build(int n){
    for(int i=n; i<2*n; i++)st[0][i] = st[0][i-n];
    int cummgcd = st[0][0];
    st[0][n] = st[0][0];
    for(int i=1; i <n; i++)cummgcd = __gcd(cummgcd, st[0][i]);
    n = 2*n;

    while(!powerof2(n)){
        st[0][n] = cummgcd;
        n++;
    }
    int k = log2_floor(n);
    for(int j=1; j<=k; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            st[j][i] = __gcd(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }
    return cummgcd;
}

bool possible(int n, int k, int cummgcd){
    for(int i=0; i<n; i++){
        if(query(i,i+k) != cummgcd)return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> st[0][i];
    int cummgcd = build(n);

    int lb = -1;
    int ub = n+1;
    while(ub - lb > 1){
        int md = lb + ((ub-lb)>>1);
        if(possible(n,md,cummgcd)){
            ub = md;
        } else{
            lb = md;
        }
    }

    cout << ub << endl;

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}