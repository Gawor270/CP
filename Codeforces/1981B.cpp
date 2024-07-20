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
    int n,m;
    cin >> n >> m;
    ll res = n;
    ll l = n - m;
    l = max(0LL, l);
    ll r = n + m;
    for (int bit = 0; bit < 32; bit++) {
        if (l & (1 << bit)){
            res |= (1 << bit);
        } else {
            ll minim = l - l%((1<< bit));
            minim |= (1 << bit);
            if (l <= minim && minim <= r) {
                res |= (1 << bit);
            }
        }
    }
    cout << res << "\n";
}

void show() {
    int x,y;
    cin >> x;
    cout << bitset<32>(x) << "\n";
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
