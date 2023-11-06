#include <bits/stdc++.h>

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

vi g[MAX_N];
int dist[MAX_N];
int parent[MAX_N];

int n,m;

int bfs(){
    REP(i,n)dist[i] = INF;
    queue<int> q;
    parent[0] = -1;
    dist[0] = 1;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] +1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return dist[n-1];
}
void solve() {
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    int res = bfs();
    if(res == INF){
        cout << "IMPOSSIBLE" << "\n";
    }
    else{
        cout << res << "\n";
        vi ans;
        int u = n-1;
        while(u != -1){
            ans.push_back(u);
            u = parent[u];
        }
        reverse(ALL(ans));
        for(int x : ans)cout << x +1 << " ";
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
