#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct type{
    ll u,z,r;
    vector<ll> g;
};

vector<type> heads;
vector<bool> vis;
vector<ll> dp;

ll findres(int v){
    if(dp[v]>0)return dp[v];

    if(vis[v])return MOD;
    ll sum = heads[v].u;
    for(int u : heads[v].g){
        vis[v] = true;
        sum += findres(u);
        vis[v] = false;
    }
    return dp[v] = min(heads[v].z, sum);
}

void solve() {
    int n;
    cin >> n;
    heads.resize(n);
    vis.resize(n);
    dp.resize(n,-1);
    for(int i=0; i<n; i++){
        cin >> heads[i].u >> heads[i].z >> heads[i].r;
        heads[i].g.resize(heads[i].r);
        for(int j=0; j<heads[i].r; j++){
            cin >> heads[i].g[j];
            heads[i].g[j]--;
        }
    }
    cout << findres(0) << "\n";
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
