#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int K = 25;

int st[K+1][MAXN];
// Using sparse table
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

int query(int L, int R){
    int len = R - L + 1;
    int k = log2_floor(len);
    return min(st[k][L], st[k][R - (1<<k) + 1]);
}

void solve() {
    int n,q;
    cin >> n >> q;
    for(int i=0; i<n; i++)cin >> st[0][i];
    preprocess();
    while(q--){
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << query(a,b) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
