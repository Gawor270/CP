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
    vi p(n);
    for(auto&x : p)cin >> x;

    auto rptr = find(all(p), n);

    int r = rptr - p.begin();
    if (r == 0){
        auto aux = find(all(p), n-1);
        r = aux - p.begin();
    }

    int l = r;

    if (r == n-1){
        while(l-1 >0 && p[l-1] > p[0])l--;
        for(int i=n-1; i >=l; i--)cout << p[i] << " ";
        for(int i=0; i<l; i++)cout << p[i] << " ";
        cout << "\n";
        return;
    }

    l = r-1;

    while(l -1 > 0 && p[l-1] > p[0]){
        l--;
    }

    for(int i=r; i<n; i++)cout << p[i] << " ";
    for(int i=r-1; i >= l; i--)cout << p[i] << " ";
    for(int i=0; i < l; i++)cout << p[i] << " ";
    cout << "\n";
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
