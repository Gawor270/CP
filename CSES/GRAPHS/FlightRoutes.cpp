#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1196
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double
#define ar array

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

vector<ar<ll,2>> adj[MAX_N];
vector<ll> dist[MAX_N];

int n,m,k;

void dijkstra(){
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    pq.push({0,1});

    while(pq.size()){
        ar<ll,2> u = pq.top();
        pq.pop();
        if(dist[u[1]].size() >= k)continue;
        dist[u[1]].push_back(u[0]);
        for(ar<ll,2> v : adj[u[1]]){
            pq.push({u[0] + v[0], v[1]});
        }
    }
    for(int i=0; i<k; i++){
        cout << dist[n][i] << " ";
    }
}

void solve() {
    cin >> n >> m >> k;
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    dijkstra();
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
