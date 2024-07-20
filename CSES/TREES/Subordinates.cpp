#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// https://cses.fi/problemset/result/8523101/ 
 
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
 
vi tree[MAX_N];
int res[MAX_N];
 
 
int dfs(int v){
    if(tree[v].empty())return res[v] = 0;
    for(int u : tree[v]){
        res[v] += dfs(u)+1;
    }
    return res[v];
}
 
void solve() {
    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cout << res[i] << " ";
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