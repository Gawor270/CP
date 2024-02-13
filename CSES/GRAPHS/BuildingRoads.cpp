#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1666
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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


vector<int> g[MAX_N];
bool vis[MAX_N];

void dfs(int v){
    vis[v] = true;
    for(int u : g[v]){
        if(!vis[u])dfs(u);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    vi cities;

    int count = -1;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            count++;
            cities.push_back(i);
            dfs(i);
        }
    }
    cout << count << "\n";
    REP(i,SIZE(cities)-1){
        cout << cities[i]+1 << " " << cities[i+1] +1 << "\n";
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
