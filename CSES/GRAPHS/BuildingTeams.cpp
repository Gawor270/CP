#include <bits/stdc++.h>

using namespace std;
// https://cses.fi/problemset/task/1668
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

vi graph[MAX_N];
bool vis[MAX_N];
int teams[MAX_N];

bool dfs(int v, int state = 1){
    vis[v] = true;
    teams[v] = state+1;
    bool ok = true;
    for(int u : graph[v]){
        if(!vis[u]){
            ok = ok && dfs(u, state ^1);
        }
        if(teams[u] == (state+1))return false;
    }
    return ok;
}



void solve() {
    int n,m;
    cin >> n >> m;

    REP(i,m){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    REP(i,n){ 
        if(!vis[i]){
            if(!dfs(i)){
                cout << "IMPOSSIBLE";
                return;
            }
        } 
    }
    
    REP(i,n){cout << teams[i] << " ";}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
}
