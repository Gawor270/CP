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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define int ll

vi tree[MAX_N];
int sz[MAX_N];
int ans[MAX_N];
int a[MAX_N];
int n;

void dfs1(int v, int p){
    sz[v] = 1;
    for(int u : tree[v]){
        if(u == p)continue;
        dfs1(u,v);
        sz[v] += sz[u];
        ans[0] += (a[v]^a[u])*sz[u];
    }
}

void dfs2(int v, int p){
    for(int u : tree[v]){
        if(u == p)continue;
        ans[u] = ans[v] -(a[u]^a[v])*sz[u] + (n - sz[u])*(a[u]^a[v]);
        dfs2(u,v);
    }
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sz[i] = ans[i] = 0;
        tree[i].clear();
    }
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    for(int i=0; i<n; i++)cout << ans[i] << " ";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
}
