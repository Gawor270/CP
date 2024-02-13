#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1202
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
const ll INF = 1e18;
const ld EPS = 1e-9;

vector<ar<ll,2>> adj[MAX_N];
ar<ll,4> stats[MAX_N];
int n,m;

void dijkstra(){
    priority_queue<ar<ll,3>, vector<ar<ll,3>>, greater<ar<ll,3>>> pq;
    for(int i=1; i<=n; i++)stats[i] = {INF,0,INF,0};
    stats[1] = {0,1,0,0};
    pq.push({0,0,1});
    while(pq.size()){
        ar<ll,3> u = pq.top();
        pq.pop();
        if(stats[u[2]][0] < u[0])continue;
        for(ar<ll,2> v : adj[u[2]]){
            if(stats[v[1]][0] >= stats[u[2]][0] + v[0]){
                if(stats[v[1]][0] > stats[u[2]][0] + v[0]){
                    stats[v[1]] = {stats[u[2]][0] + v[0], stats[u[2]][1], stats[u[2]][2] + 1, stats[u[2]][3] + 1};
                    pq.push({stats[v[1]][0], u[1] + 1, v[1]});
                }else{
                    stats[v[1]][1] = (stats[v[1]][1] + stats[u[2]][1])%MOD;
                    stats[v[1]][2] = min(stats[v[1]][2], stats[u[2]][2] + 1);
                    stats[v[1]][3] = max(stats[v[1]][3], stats[u[2]][3] + 1);
                }
            }
        }
    }
    for(ll x : stats[n])cout << x << " ";
}

void solve() {
    cin >> n >> m;
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
