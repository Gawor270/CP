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
    vi a(n), b(n);
    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;

    int samepos = 0;
    int sameneg = 0;

    int rating1 = 0;
    int rating2 = 0;
    for (int i=0; i<n; i++){
        if(a[i] == 1 && b[i] == 1){
            samepos++;
        }
        if(a[i] == -1 && b[i] == -1){
            sameneg++;
        }
        if(a[i] > b[i]){
            rating1 += a[i];
        }
        if(a[i] < b[i]){
            rating2 += b[i];
        }
    }
    int minrating = min(rating1, rating2);
    int maxrating = max(rating1, rating2);

    minrating += samepos;
    int diff = max(0, minrating - maxrating);
    minrating -= diff/2;
    maxrating += diff/2;

    if(minrating > maxrating)swap(minrating, maxrating);

    maxrating -= sameneg;
    diff = max(0, minrating - maxrating);
    minrating -= diff/2;
    maxrating += diff/2;

    cout << min(minrating,maxrating) << "\n";

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
