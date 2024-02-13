#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1679
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool vis[MAX_N];
vi adj[MAX_N];
vi order;

int n,m;

void dfs(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u])dfs(u);
    }
    order.push_back(v);
}

void toposort(){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(ALL(order));
}
void solve() {
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    toposort();
    fill(vis, vis + n  +1, false);
    for(int x : order){
        vis[x] = true;
        for(int u : adj[x]){
            if(vis[u]){
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
    }
    for(int x : order)cout << x << " ";
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
