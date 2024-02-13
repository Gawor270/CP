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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x : a)cin >> x;
    vector<ll> suffsum(n+1,0);
    for(int i=n-1; i>=0; i--){
        suffsum[i] = suffsum[i+1] + max(0LL,a[i]);
    }
    ll res =  0;
    for(int i=0; i<n; i++){
        ll val = i&1 ? 0 : a[i];
        res= max(res, suffsum[i+1] + val);
    }
    cout << res << '\n';


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
