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

vector<ll> tree;


int build(int v, int n){
    bool state = 0;
    if(2*v >= n){
        tree[v] = tree[2*v] | tree[2*v+1];
        return 1;
    }
    state = build(2*v,n)^1;
    build(2*v+1,n);
    if(state){
        tree[v] = tree[2*v] | tree[2*v+1];
        return state;
    }
    else{
        tree[v] = tree[2*v]^tree[2*v+1];
        return state;
    }

}

int update(int v,int tl, int tr, int p, int b){
    if(tl == tr){
        tree[v] = b;
        return 0;
    }
    int tm = (tl + tr)/2;
    bool state;
    if(tm < p){
        state = update(2*v+1, tm+1, tr, p, b)^1;
    }
    else{
        state = update(2*v, tl, tm, p, b)^1;
    }
    if(state){
        tree[v] = tree[2*v] | tree[2*v+1];
        return state;
    }
    else{
        tree[v] = tree[2*v]^tree[2*v+1];
        return state;
    }
}

void solve() {
    int exp,m;
    cin >> exp >> m;
    int n = (int)pow(2,exp);
    tree.resize(2*n);
    for(int i=n; i<2*n; i++)cin >> tree[i];

    build(1,n);

    while(m--){
        ll p,b;
        cin >> p >> b;
        update(1,0,n-1,--p,b);
        cout << tree[1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
