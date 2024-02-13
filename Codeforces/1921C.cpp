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
    int h,w,xa,ya,xb,yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa >= xb){
        cout << "Draw" << "\n";
        return;
    }
    int xdist = xb-xa;
    int ydist = abs(yb-ya);
    if(xdist&1){
        int bdist = yb >= ya ? w-yb : yb - 1;
        if(max(0,ydist - max(0,xdist/2 -bdist) ) <= 1){
            cout << "Alice" << "\n";
            return;
        }
    }
    else{
        int bdist = yb >= ya ? ya-1 : w - ya;
        if(max(0,ydist - max(0,xdist/2 - bdist)) == 0){
            cout << "Bob" << "\n";
            return;
        }
    }
    cout << "Draw" << "\n";
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
