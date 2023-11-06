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
    ll n,c,d;
    cin >> n >> c >> d;
    vi a(n);
    for(auto&x : a)cin >> x;

    sort(all(a));
    auto pt = unique(all(a));
    a.resize(distance(a.begin(),pt));

    ll ans = c*(n - (ll)a.size());

    ll add = 1e17;
    ll last = 0;
    ll tobuy = 0;
    ll m = (ll)a.size();
    for(ll i=0; i<m; i++){
        tobuy += (a[i]-  last -1);
        ll newcost = tobuy*d + (m-i-1)*c;
        add = min(add,newcost); 
        last = a[i];
    }
    cout << min(ans  + add, n*c + d) << "\n";

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
