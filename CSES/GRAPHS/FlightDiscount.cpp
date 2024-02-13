#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1195
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()
#define ar array

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n,m;
vector<ar<ll,2>> adj1[MAX_N]; 
vector<ar<ll,2>> adj2[MAX_N]; 
ll d1[MAX_N], d2[MAX_N];

void dijkstra(ll* dist, vector<ar<ll,2>>* adj, int s){
    fill(dist, dist + n + 1, 1e18);
    dist[s] = 0;
    priority_queue<ar<ll,2>, std::vector<ar<ll,2>>, std::greater<ar<ll,2>>> pq;
    pq.push({0,s});
    while(pq.size()){
        array<ll,2> u = pq.top();
        pq.pop();
        if(u[0] > dist[u[1]])continue;
        for(ar<ll,2> v : adj[u[1]]){
            if(dist[v[0]] > dist[u[1]] + v[1]){
                dist[v[0]] = dist[u[1]] + v[1];
                pq.push({dist[v[0]],v[0]});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }
    dijkstra(d1,adj1,1);
    dijkstra(d2,adj2,n);
    ll res = min(d1[n], d2[1]);
    for(int i = 1; i<=n; i++){
        for(ar<ll,2> j : adj1[i]){
            res = min(res, d1[i] + j[1]/2 + d2[j[0]]);
        }
    }
    cout << res << "\n";
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
