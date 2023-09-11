#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    ll x;
    cin >> x;
    vi res;
    res.pb(x);
    
    for(int i=0; ; ++i){
        if(x & (1 << i)){
            if(x == (1 << i)){
                break;
            }
            x -= (1 << i);
            res.pb(x);
        }
    }

    while(x != 1){
        x >>= 1;
        res.pb(x);
    }

    cout << res.size() << "\n";
    for(int n : res){
        cout << n << " ";
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
