#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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

int vis[MAX_N];
int t[MAX_N];
int ans[MAX_N];
int tin[MAX_N];
vi order;

int dfs(int v, int token, int d = 0) {
    vis[v] = token;
    tin[v] = d;
    int pivot;
    if(!vis[t[v]])pivot = dfs(t[v],token, d+1);
    else if(vis[t[v]] == token){
        ans[t[v]] = (d - tin[t[v]] + 1);
        pivot =  t[v];
    }
    else{
        ans[v] = ans[t[v]] + 1;
        return v;
    }

    if(tin[v] >= tin[pivot])ans[v] = ans[pivot];
    else ans[v] = ans[t[v]] + 1;

    return pivot;
}

void toposort(int v){
    vis[v] = true;
    if(!vis[t[v]])toposort(t[v]);
    order.push_back(v);
}


void solve() {
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> t[i];
        t[i]--;
    }
    for(int v=0; v<n; v++){
        if(!vis[v])toposort(v);
    }
    fill(vis, vis + n, false);
    reverse(all(order));
    int token = 1;
    for(int v = 0; v<n; v++){
        if(!vis[v])dfs(v,token++);
    }
    for(int i=0; i<n; i++)cout << ans[i] << " ";
    cout << "\n";

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
