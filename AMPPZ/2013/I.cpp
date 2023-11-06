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

void solve() {
    int n,k;
    cin >> n >> k;
    vi g(n);
    vi d(n+1,0);
    for(auto&x : g)cin >> x;
    map<int,int> count;
    for(int i=n-1; i>=0; i--){
        d[i] = d[i+1];
        count[g[i]]++;
        if(count[g[i]] == k){
            d[i] += k;
            count.clear();
        }
    }
    count.clear();
    vi res;
    pi minim = {1e9,-1};
    for(int i=0; i<n; i++){
       count[g[i]]++;
       if(count[g[i]] == k){
           if(g[i] <= minim.first){
               minim = {g[i],i};
           }
       }
       if(d[i] != d[i+1] && minim.second > -1){
            for(int j=0; j<k; j++)res.push_back(minim.first);
            count.clear();
            i = minim.second;
            minim = {1e9,-1};
        }
    }
    if(minim.second != -1){
        while(k--)res.push_back(minim.first);
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
