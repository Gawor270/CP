#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// https://cses.fi/problemset/task/1130

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


pi dfs(int v, int p = -1){
    pi curr = {0,0};
    vector<pi> currres;
    for(int u : tree[v]){
        if(u != p){
            pi res = dfs(u, v);
            currres.push_back(res);
            curr.first += res.second;
        }
    }
    curr.second = curr.first;
    for(pi res : currres){
            curr.second = max(curr.second, curr.first - res.second + res.first + 1);
    }
    return curr;
}

void solve() {
    int n;
    cin >> n;
    for(int i=2; i<=n; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    pi res = dfs(1);
    cout << max(res.first, res.second) << "\n";
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
