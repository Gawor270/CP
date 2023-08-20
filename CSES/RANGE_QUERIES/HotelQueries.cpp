#include <bits/stdc++.h>

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

int update(int v, int x,int n){
    if(tree[v] < x) return 0;
    if(v >= n && tree[v] >= x){
        tree[v] -= x;
        return v - n + 1;
    }
    int ind = 0;
    if(tree[2*v] >= x){
        ind += update(2*v, x, n);
    }
    else{
        ind += update(2*v+1, x, n);
    }
    tree[v] = max(tree[2*v], tree[2*v+1]);
    return ind;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> hotel(n);
    for(int i=0; i<n; i++)cin >> hotel[i];
    while( __builtin_popcount(n) != 1 )n++;
    tree.resize(2*n);

    for(int i=0; i<(int)hotel.size(); i++){
        tree[n+i] = hotel[i];
    }

    // build
    for(int i = n-1; i>=1; i--){
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    vector<int> res;
    while(m--){
        int r;
        cin >> r;
        res.push_back(update(1,r,n));
    }

    for(int h : res)cout << h << " ";
    
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
