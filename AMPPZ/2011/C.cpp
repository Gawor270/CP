#include <bits/stdc++.h>
// https://szkopul.edu.pl/problemset/problem/X4pQ7NKUJUkYw_MBtprKFZas/site/?key=statement
using namespace std;

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

bool isPowerOfTwo(ll x)
{
    if(x<0) return false;
    /* First x in the below expression is for the case when
     * x is 0 */
    return x && (!(x & (x - 1)));
}

void solve() {
    ll n;
    cin >> n;
    if(isPowerOfTwo(n)){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
