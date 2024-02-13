#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1673
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

const int MAX_M = 5e3 + 5;
const int MAX_N = 3e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n,m;
vector<pair<ll,ll>> adj[MAX_N];
vector<pair<ll,ll>> inv[MAX_N];
ll dist[MAX_N];
bool vis[MAX_N];
int par[MAX_N];
bool c[MAX_N];
vi order;

void toposort(int v){
    vis[v] = true;
    for(auto& uc : adj[v]){
        if(!vis[uc.first])toposort(uc.first);
    }
    order.push_back(v);
}

bool check(int v){
    if(c[v])return true;
    bool res = false;
    vis[v] = true;
    for(auto&p : inv[v]){
        if(!vis[p.first])res |= check(p.first);
    }
    return res;
}
void solve(){
    cin >> n >> m;
    for(int i=0; i<m;i ++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        inv[b].push_back({a,c});
    }
    toposort(1);
    fill(dist, dist + n + 1, -1e18);
    dist[1] = 0;
    reverse(ALL(order));
    fill(vis, vis + n + 1, false);
    for(int u : order){
        vis[u] =  true;
        for(auto v : adj[u]){
            if(dist[v.first] < dist[u] + v.second){
                c[v.first] = vis[v.first];
                dist[v.first] = dist[u] + v.second;
            }
        }
    }
    fill(vis, vis + n + 1, false);
    cout << (check(n) ? -1 : dist[n]);
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
