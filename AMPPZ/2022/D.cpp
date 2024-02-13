#include <bits/stdc++.h>
// https://amppz.tcs.uj.edu.pl/2022/data/amppz.pdf
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
vector<int> dh;
vector<bool> vis;
pi countleafes(int v){
    vis[v] = true;
    int count = 0;
    int countl = 0;
    int sum = 0;
    for(int u : tree[v]){
        if(!vis[u]){
            count++;
            pi res = countleafes(u);
            sum += res.first;
            countl += res.second;
        }
    }
    if(count){
        dh[sum] += countl;
        return {sum+1,countl};
    }
    else{
        return {1,1};
    }
}



void solve() {
    int n;
    cin >> n;
    tree.resize(n);
    dh.resize(n);
    vis.resize(n,false);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }
    int no_leafes = countleafes(0).second;

    int count = 0;
    vi ans = {1};
    for(int i=0; i<n; i++){
        if(dh[i] == no_leafes){
            count++;
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
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
