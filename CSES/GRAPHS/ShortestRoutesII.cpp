#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1672
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

const int MAX_N = 5e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll dist[MAX_N][MAX_N];


void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        fill(dist[i], dist[i] + n + 1, 1e18);
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dist[a][b] < 1e18){
            cout << dist[a][b] << "\n";
        }
        else{
            cout << -1 << "\n";
        }
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
