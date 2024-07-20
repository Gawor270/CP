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
    int n,f,k;
    cin >> n >> f >> k;
    f--;
    vector<pi> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    int val = a[f].first;
    sort(a.rbegin(), a.rend());

    int first = 0;
    int last = 0;
    bool found = false;
    for (int i=0; i<n; i++) {
        if (a[i].first == val) {
            if (!found) {
                first = i;
                found =true;
            }
            last = i;
        }
    }

    k--;
    if (last <= k) {
        cout << "YES\n";
    } else if (first <= k && k < last) {
        cout << "MAYBE\n";
    } else {
        cout << "NO\n";
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
