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
    ll n,x,y;
    cin >> n >> x >> y;
    ll count1 = n/x;
    ll count2 = n/y;
    ll count3 = n/(lcm(x,y));
    
    count1 -= count3;
    count2 -= count3;
    ll ans = 0;
    
    ans += count1*n;
    ans -= (count1)*(count1-1)/2;
    ans -= (count2)*(count2+1)/2;

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
