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

int pos[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int inp;
        cin >> inp;
        pos[inp] = i;
    }

    int res = n/2;
    if (n&1){
        int num = n/2+1;
        for (int i = 1; i<=n/2; i++) {
            if (pos[num-i] < pos[num-i + 1] && pos[num + i - 1] < pos[num + i])res--;
            else break;
        }
    }
    else {
        int j1 = n/2;
        int j2 = n/2+1;
        for (int i=0; i<n/2; i++){
            if (pos[j1 - i] < pos[j1 -i + 1] && pos[j2 + i - 1] < pos[j2 + i] )res--;
            else break;
        }
    }
    cout << res << "\n";

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
