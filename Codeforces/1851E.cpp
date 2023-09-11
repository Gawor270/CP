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

vector<bool> vis;
vector<vector<int>> graph;
vector<ll> costs;

ll dfs(int v){
    if(vis[v])return costs[v];
   
    vis[v] = true;
    ll count = 0;
    for( int u : graph[v]){
        count += dfs(u);
    }
    
    if(!graph[v].empty())costs[v] = min(costs[v],count);
    return costs[v];
}

void solve() {
    int n, k;
    cin >> n >> k;

    costs.resize(n);
    vis.assign(n,false);
    graph.assign(n,vector<int>(0));

    for(auto&x : costs)cin >> x;
    for(int i=0; i<k; i++){
        int inp;
        cin >> inp;
        costs[--inp] = 0;
    }

    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        graph[i].resize(m);
        for(int& v : graph[i]){
            cin >> v;
            --v;
        }
    }

    for(int i=0; i<n; i++){
        dfs(i);
    }

    for(int x : costs){
        cout << x << " ";
    }
    cout << "\n";

    
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
