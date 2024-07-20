#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// https://cses.fi/problemset/task/1683
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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


vector<vi> adj;

template <typename T>
struct SCC{
    vector<T> ids, low;
    vector<bool> onStack;
    stack<T> stck;
    vector<vector<T>> adj;
    int sz;
    int id = 1;
    int sccCount = 0;

    SCC(const vector<vector<T>>& adj){
        this->adj = adj;
        sz = adj.size();
        ids.resize(sz);
        low.resize(sz);
        onStack.resize(sz);
    }

    vector<T> findSccs(){
        for(int i=1; i<sz; i++){
            if(!ids[i]){
                dfs(i);
            }
        }
        return low;
    }

    void dfs(T v){
        stck.push(v);
        onStack[v] = true;
        ids[v] = low[v] = id++;

        for(T u : adj[v]){
            if(!ids[u])dfs(u);
            if(onStack[u])low[v] = min(low[v], low[u]);
        }

        if(ids[v] == low[v]){
            while(true){
                T u = stck.top();
                stck.pop();
                onStack[u] = false;
                low[u] = ids[v];
                if(u == v)break;
            }
            sccCount++;
        }
    }

};

bool vis[MAX_N];

bool existpath(int s, int t, vector<vi>& adj){
    if(s == t)return true;
    vis[s] = true;
    bool state = false;
    for(int u : adj[s]){
        if(!vis[u])state |= existpath(u,t,adj);
    }
    return state;
}

void solve() {
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    SCC<int> scc(adj);
    vector<int> res = scc.findSccs();
    vi cpy = res;
    sort(all(cpy));
    auto it = unique(all(cpy));
    cpy.resize(distance(cpy.begin(), it));
    map<int,int> mp;
    for(int i =1; i<cpy.size(); i++){
        mp[cpy[i]] = i;
    }
    cout << scc.sccCount << "\n";
    for(int i=1; i<=n; i++){
        cout << mp[res[i]] << " ";
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
