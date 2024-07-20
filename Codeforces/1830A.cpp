#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<pi> graph[MAX_N];

int dfs(int v = 1, int parent = -1, int time = -1, int len = 0) {
    int res = 0;
    bool leaf = true;
    for (auto &u : graph[v]){
        if(u.first == parent)continue;
        leaf = false;
        res = max(dfs(u.first, v, u.second, len + (u.second < time)), res);
    }
    return leaf ? len : res;
}

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)graph[i].clear();
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }

    cout << 1 + dfs() << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
