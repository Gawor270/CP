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

const int MAX_P = 1e8 - 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


ll perimeter(ll n, ll m){
    return 2*n*n + 2*n*m;
}

bool check(ll n, ll m){
    return ((n*n + m*m) % ((n+m)*(n+m) - 2*n*n)) == 0;
}

void solve() {
    ll ans = 0;
    for(ll m = 1; m<=MAX_P; m++){
        for(ll n = m+1; perimeter(n,m) < MAX_P; n++){
            if(__gcd(n,m) == 1 && check(n,m) && (n%2 ==0 || m%2 == 0)){
                ans += MAX_P/perimeter(n,m);
            }
        }
    }
    cout << ans << "\n";
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
