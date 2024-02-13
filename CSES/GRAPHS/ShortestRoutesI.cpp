#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1671
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

vector<pi> wgraph[MAX_N];
ll dist[MAX_N];

void dijkstra(int s){
    priority_queue<pair<ll,ll>, std::vector<pair<ll,ll>>, std::greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    dist[s] = 0;
    while(pq.size()){
        pair<ll,ll> u = pq.top();
        pq.pop();
        if(dist[u.second] < u.first)continue;
        for(pi& v : wgraph[u.second]){
            if(dist[v.first] > v.second + u.first){
                dist[v.first] = v.second + u.first;
                pq.push({dist[v.first],v.first});
            }
        }
    }
}


void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        wgraph[a].push_back({b,c});
    }
    fill(dist, dist + n + 1, 1e18);
    dijkstra(1);
    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
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
