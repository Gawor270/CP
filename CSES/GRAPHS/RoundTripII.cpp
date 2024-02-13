#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1678
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

vi adj[MAX_N];
bool vis1[MAX_N];
bool vis2[MAX_N];
int par[MAX_N];
vi order;

void toposort(int v){
    vis1[v] = true;
    for(int u : adj[v]){
        if(!vis1[u])toposort(u);
    }
    order.push_back(v);
}

void solve() {
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i=1; i<=n; i++){
        if(!vis1[i]){
            order.clear();
            toposort(i);
            reverse(ALL(order));
            fill(vis2, vis2 + n + 1, false);
            for(int v : order){
                vis2[v] = true;
                for(int u : adj[v]){
                    if(!vis2[u])par[u] = v;
                    else{
                        par[u] = v;
                        vi res;
                        res.push_back(u);
                        while(v^u){
                            res.push_back(v);
                            v = par[v];
                        }
                        res.push_back(u);
                        reverse(ALL(res));
                        cout << res.size() << "\n";
                        for(int x : res)cout << x << " ";
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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
