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


vector<set<char>> tree;

void build(int v, int n){
    if(2*v >= n){
        set_union(tree[2*v].begin(), tree[2*v].end(),
                tree[2*v+1].begin(), tree[2*v+1].end(),
                inserter(tree[v],tree[v].begin()));
    }
    else{
        build(2*v,n);
        build(2*v+1,n);
        set_union(tree[2*v].begin(), tree[2*v].end(),
                tree[2*v+1].begin(), tree[2*v+1].end(),
                inserter(tree[v],tree[v].begin()));
    }
}

void repl(int p, char c, int n){
    int id = n+p;
    int child = id;
    char todel = *(tree[id].begin());
    tree[id].erase(todel);
    tree[id].insert(c);
    id /= 2;
    for(int j=id; j>0; j/=2){
        if(2*j == child){
            if(tree[2*j+1].find(todel) == tree[2*j+1].end())tree[j].erase(todel);
        }
        else{
            if(tree[2*j].find(todel) == tree[2*j].end())tree[j].erase(todel);
        }
        tree[j].insert(c);
        child = j;
    }

}

void query(int v, int tl, int tr, int l, int r,set<char>& res){
    if(tr < l || tl > r)return;
    if(l <= tl && tr <= r){
        //cout << l << " " << r << " " << v << "\n" ;
        for(auto itr : tree[v]){
            res.insert(itr);
        }
        return;
    }
    int tm = (tl+tr)/2;
    query(2*v, tl, tm, l, r, res);
    query(2*v+1, tm+1, tr, l, r, res);
}

void solve() {
    int q, t, l, r, pos;
    set<char> res;
    char c;
    string s;
    cin >> s;
    int n = s.length();
    int m = n;
    while(__builtin_popcount(n) != 1)n++;
    tree.resize(2*n);
    for(int i=n; i<(n + m); i++){
        tree[i].insert(s[i-n]);
    }


    build(1,n);
    cin >> q;
    while(q--){
        cin >> t;
        if(--t){
            cin >> l >> r;
            res.clear();
            query(1,0,n-1,--l,--r,res);
            cout << (int)res.size() << "\n";
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
