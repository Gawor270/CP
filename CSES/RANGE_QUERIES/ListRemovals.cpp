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

vector<int> tree;

int query(int i,int n){
    int j = (n+i)/2;
    for(; j>=1;  j/=2){
        i += tree[j];
    }
    return i;
}

void update(int v, int tl, int tr, int l){
    if(tr < l)return;
    if(tl >= l){
        tree[v] += 1;
        return;
    }
    int md = (tl + tr)/2;
    update(2*v, tl, md, l);
    update(2*v+1, md+1, tr, l);
}

void solve() {
    int n;
    cin >> n;
    vi x(n);
    for(auto& a : x )cin >> a;

    while(__builtin_popcount(n) != 1)n++;
    tree.resize(2*n);
    for(int i=0; i<(int)x.size();i++){
        tree[n + i] = 1;
    }

    vi res;
    int t = (int)x.size();
    while(t--){
        int p;
        cin >> p;
        p--;
        int newi = query(p,n);
        res.push_back(x[newi]);
        update(1,0,n-1,p);
    }
    
    for(int el : res)cout << el << " ";
    cout << "\n";

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
