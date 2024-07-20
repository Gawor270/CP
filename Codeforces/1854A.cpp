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


void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    int maxim = 0;
    int maxind = 0;
    for(int i=0; i<n; i++){
        if(abs(a[i]) > abs(maxim)){
            maxim = a[i];
            maxind = i;
        }
    }
    
    vector<pi> res;
    for(int i=0; i<n; i++){
        res.push_back({i+1,maxind+1});
    }

    if (maxim <= 0){
        for(int i=n; i>1; i--){
            res.push_back({i-1,i});
        }
    }
    else{
        for(int i=1; i<n; i++){
            res.push_back({i+1,i});
        }
    }

    cout << res.size() << "\n";
    for(auto p : res){
        cout << p.first << " " << p.second << "\n";
    }
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