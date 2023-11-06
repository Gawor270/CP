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

vector<vector<int>> tree;
vector<bool> vis;
int k;
int maxd;
vector<int> res;

pi dfs(int v){
    vis[v]  = true;
    int count = 0;
    int level = -1;
    for(int u : tree[v]){
        if(!vis[u]){
            count++;
            pi ans = dfs(u);
            count += ans.first;
            level = max(level,ans.second);
        }
    }
    if(count == 0){
        if(level == -1){
            res.push_back(v+1);
            return {-1,1};
        }
        else if(level <= k/2){
            res.push_back(v+1);
            return {-1,level+1};
        }
    }
    return {0,2*k};

}

void solve() {
    int n ;
    cin >> n >> k;
    tree.resize(n);
    vis.resize(n);
    int v = 0;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }

    dfs(0);
    sort(all(res));
    if(k&1){
        for(int i=0; i<n; i++){
            if(res[i] != i+1){
                res.push_back(i+1);
                break;
            }
        }
    }

    cout << res.size() << "\n";
    for(int x : res)cout << x << " ";



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
