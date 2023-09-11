#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll unsigned long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
ll poss[MAX_N];
int vis[MAX_N];
int token = 0;

ll bfs(int v, vector<vector<int>> &tree){
    vis[v] = token;
    
    bool flag= true;
    for(int u : tree[v]){
        if(vis[u] != token){
            flag = false;
            poss[v] += bfs(u,tree);
        }
    }
    return flag ? poss[v]=1 : poss[v];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1);
    memset(poss,0,(n+1)*sizeof(ll));
    while(--n){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    token++;
    bfs(1,tree);
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        ll ans = poss[x]*poss[y];
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
