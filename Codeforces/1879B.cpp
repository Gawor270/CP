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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto& x : a)cin >> x;
    for(auto& x : b)cin >> x;

    ll sum1 = 0;
    ll sum2 = 0;
    for(int i=0; i<n; i++){
        sum1 += a[i];
        sum2 += b[i];
    }

    ll val1 = (*min_element(all(a)))*n + sum2;
    ll val2 = (*min_element(all(b)))*n + sum1;
    cout << min(val1,val2) << "\n";

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
