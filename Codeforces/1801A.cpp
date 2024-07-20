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

const int MAX_N = 2e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

unsigned long long B[MAX_N][MAX_N];

void solve() {
    int n,m;
    cin >> n >> m;
    unsigned long long ones = ~0ULL;
    ones ^= (1ULL << 63);

    cout << n*m << "\n";
    for (unsigned long long i=0; i<n; i++) {
        for (unsigned long long j=0; j<m; j++) {
            if (i%2) {
                B[i][j] = (ones ^ B[i-1][j]);
            }
            else {
                B[i][j] = j + (i << 32);
            }
            cout << (B[i][j]) << " "; // Use parentheses to clarify the order of operations
        }
        cout << "\n";
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
