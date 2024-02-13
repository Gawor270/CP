#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1197
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

const int MAX_N = 2.5e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

ll dist[MAX_N];
vector<tuple<int,int,int>> edges;
int par[MAX_N];


void solve() {
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});

    };
    fill(par, par + n + 1, -1);
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    int x=-1;
    for(int i=0; i< n; i++){
        x = -1;
        for(auto e : edges){
            ll a,b,w;
            tie(a,b,w) = e;
            if(dist[a] + w < dist[b]){
                dist[b] = max(-INF, dist[a] + w);
                par[b] = a;
                x = b;
            }
        }
    }
    if(x == -1){
        cout << "NO" << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            x = par[x];
        }

        vi cycle;
        for(int v = x ;; v = par[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1)break;
        }
        reverse(ALL(cycle));

        cout << "YES\n";
        for(int v : cycle){
            cout << v << " ";
        }
        cout << "\n";
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
