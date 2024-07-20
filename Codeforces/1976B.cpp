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
    vector<ll> a(n);
    vector<ll> b(n+1);
    for (auto&x : a)cin >> x;
    for (auto&x : b)cin >> x;

    ll minim = 1e9;
    ll maxim = 0;
    ll add = 1e9;
    for (int i=0; i<n; i++){
        minim = min(a[i], b[i]);
        maxim = max(a[i], b[i]);
        if (b[n] <= maxim && b[n] >= minim)add = 1;
        else add = min(add, min(abs(b[n] - minim) + 1, abs(b[n] - maxim) + 1));
    }

    ll sum = 0;
    for (int i=0; i<n; i++){
        sum += abs(a[i] - b[i]);
    }

    cout << sum + add << "\n";
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
