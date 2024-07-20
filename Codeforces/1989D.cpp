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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll dp[MAX_N];

void solve() {
    int n,m;
    cin >> n >> m;

    vi a(n), b(n), c(m);

    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;
    for(auto&x : c) cin >> x;

    vector<tuple<int,int,int>> diff(n);
    for (int i=0; i<n; i++){
        diff[i] = {a[i] - b[i],a[i], i};
    }


    sort(all(diff));

    vi path;
    int curr = get<1>(diff[0]);
    path.push_back(get<2>(diff[0]));
    for (int i=1; i<n; i++){
        if(get<1>(diff[i]) < curr){
            path.push_back(get<2>(diff[i]));
            curr = get<1>(diff[i]);
        }
    }

    reverse(all(path));
    int j = 0;

    for(int i=a[path[0]]; i<= MAX_N; i++){
        if (j+1 < path.size() && i >= a[path[j+1]]){
            j++;
        }
        dp[i] = dp[i - (a[path[j]] - b[path[j]])] + 2;
    }

    ll res = 0;

    for (int i=0; i<m; i++){
        if(c[i] >= MAX_N){
            int mindiff = a[path.back()] - b[path.back()];
            int dist = c[i] - MAX_N + 1;
            int scoreincr = dist/mindiff + (dist%mindiff > 0);
            res += 2*(scoreincr);
            c[i] -= scoreincr*mindiff;
        }
        res += dp[c[i]];
    }
    cout << res << "\n";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
