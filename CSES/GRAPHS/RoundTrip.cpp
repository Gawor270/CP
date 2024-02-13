#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1669

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
vi graph[MAX_N];
vi sol;

int dfs(int v, int p = -1){
    vis[v] = true;
    int val = -1;
    for(int u : graph[v]){
        if(sol.size() && val == -1)return -1;
        if(!vis[u]){
            val = dfs(u,v);
            if(val != -1){
                sol.push_back(v);
                if(val == v)return -1;
                return val; 
            }
        }
        else if(p != u){
            sol.push_back(u);
            sol.push_back(v);
            return u;
        }
    }
    return val;
}

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        dfs(i);
        if(sol.size()){
            cout << sol.size() << "\n";
            for(int x : sol)cout << x << ' ';
            return;
        }
    }
    cout << "IMPOSSIBLE";
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
