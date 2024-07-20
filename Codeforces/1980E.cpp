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

    vector<vi> a(n, vi(m));
    vi sumrowsa(n);
    vi sumcola(m);
    vector<vi> b(n, vi(m));
    vi sumrowsb(n);
    vi sumcolb(m);

    for (int i=0; i <n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            sumrowsa[i] += a[i][j];
            sumcola[j] += a[i][j];
        }
    }

    for (int i=0; i <n; i++) {
        for (int j=0; j<m; j++) {
            cin >> b[i][j];
            sumrowsb[i] += 
            sumcolb[j] += b[i][j];
        }
    }

    vector<pi> srb(n*m);
    for (int i=0; i <n; i++) {
        for (int j=0; j<m; j++) {
            srb[b[i][j] - 1] = {sumrowsb[i], sumcolb[j]};
        }
    }


    for (int i=0; i <n; i++) {
        for (int j=0; j<m; j++) {
            pi curr = {sumrowsa[i],sumcola[j]};
            if (curr != srb[a[i][j]-1]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";


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
