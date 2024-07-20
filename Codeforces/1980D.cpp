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
    cin  >> n;

    vi a(n);
    for(auto&x : a)cin >> x;

    vi b(n-1);
    int notright = 0;
    for(int i=0; i<n-1; i++) {
        b[i] = __gcd(a[i], a[i+1]);
        if (i)notright += (b[i-1] > b[i]);
    }
    
    if (notright == 0){
        cout << "YES\n";
        return;
    }

    if (notright == 1) {
        if(b[0] > b[1]){
            cout << "YES\n";
            return;
        }

        if(b[n-3] > b[n-2]){
            cout << "YES\n";
            return;
        }
    }

    for(int i=1; i<n-1; i++){
        int neww = __gcd(a[i-1], a[i+1]);

        int bal = 0;
        if (i-2 >= 0) {
            bal += (b[i-2] > b[i-1]);
            bal -= (b[i-2] > neww);
        }
        if(i+1 < n-1) {
            bal += (b[i] > b[i+1]);
            bal -= (neww > b[i+1]);
        }

        bal += (b[i-1] > b[i]);

        if (notright - bal <= 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

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
