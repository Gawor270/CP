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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


vector<ar<int,26>> segtree;

void build(int v, int n){
    if(2*v >= n){
        for(int i=0; i<26; i++){
            segtree[v][i] += segtree[2*v+1][i];
            segtree[v][i] += segtree[2*v][i];
        }
    }
    else{
        build(2*v,n);
        build(2*v+1,n);
        for(int i=0; i<26; i++){
            segtree[v][i] += segtree[2*v+1][i];
            segtree[v][i] += segtree[2*v][i];
        }
    }
}

void repl(int p, char c, int n){
    int id = n+p;
    int child = id;
    ar<int, 26> add = {};   
    for(int i=0; i<26; i++)add[i] -= segtree[id][i];
    add[c - 'a']++;
    for(int j=id; j>0; j/=2){
        for(int i=0; i<26; i++)segtree[j][i] += add[i];
        child = j;
    }

}

void query(int v, int tl, int tr, int l, int r, ar<int,26>& res){
    if(tr < l || tl > r)return;
    if(l <= tl && tr <= r){
        for (int i=0; i<26; i++){
            res[i] += segtree[v][i];
        }
        return;
    }
    int tm = (tl+tr)/2;
    query(2*v, tl, tm, l, r, res);
    query(2*v+1, tm+1, tr, l, r, res);
}

void solve() {
    int q, t, l, r, pos;
    char c;
    string s;
    cin >> s;
    ar<int, 26> res;
    int n = s.length();
    int m = n;
    while(__builtin_popcount(n) != 1)n++;
    segtree.resize(2*n);
    for(int i=n; i<(n + m); i++){
        segtree[i][s[i-n] - 'a']++;
    }


    build(1,n);
    cin >> q;
    while(q--){
        cin >> t;
        if(--t){
            cin >> l >> r;
            fill(all(res), 0);
            query(1,0,n-1,--l,--r, res);
            int ret = 0;
            for(int i=0; i<26; i++)ret += (res[i] > 0);
            cout << ret << "\n";
        }
        else{
            cin >> pos >> c;
            repl(--pos, c, n);
        }
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