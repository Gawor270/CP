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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n,q;
    cin >> n >> q;
    vi c(n);
    for(auto&x : c)cin >> x;
    vi prefsum1(n+1,0);
    vector<ll> prefsum2(n+1,0LL);
    for(int i=1; i<=n; i++){
        prefsum1[i] = prefsum1[i-1] + (c[i-1] == 1);
        prefsum2[i] = prefsum2[i-1] + (c[i-1]-1);
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        int len = r-l+1;
        ll num1 = prefsum1[r] - prefsum1[l-1];
        ll num2 = prefsum2[r] - prefsum2[l-1];
        if(len == 1 || num1 > num2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
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
