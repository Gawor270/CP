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
    for(auto&x : a)cin >> x;

    sort(all(a));

    int j = n-1;
    int i;
    ll sum = 0;
    for (i=0; i<j; i++) {
        sum += a[i];
        if (sum >= a[j]) {
            sum = (sum - a[j]);
            a[j] = 1;
            j--;
        }
    }

    if (a[j] > 1) {
        if (i > j) {
            if (sum > 1) {
                a[j] = (a[j] - sum) + sum/2 + sum%2 + 1;
            }
        } else {
            a[j] = (a[j] + sum)/2 + (a[j]+ sum)%2 + 1 - sum;
        }
    }

    cout << accumulate(all(a), 0LL) << "\n";
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