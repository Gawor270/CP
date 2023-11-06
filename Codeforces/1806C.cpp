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
    vector<ll> a(2*n);
    ll ans = 0;
    ll sum = 0;
    for(int i=0; i<2*n; i++){
        cin >> a[i];
        ans += abs(a[i]);
        sum += abs(a[i] - (-1));
    }
    if(n == 1){
        ans = min(ans, abs(a[0] - a[1]));
    }
    if(n == 2){
        ans = min(ans, abs(a[0]-2) + abs(a[1] - 2) + abs(a[2]-2) + abs(a[3]-2));
    }
    if(!(n&1)){
        for(int i=0; i<2*n; i++){
            ans = min(ans, sum - abs(a[i]-(-1)) + abs(a[i] - n));
        }
    }
    cout << ans << "\n";
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
