#include <bits/stdc++.h>

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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a)cin >> x;
    ll maxdiff =  0;
    vector<ll> minel(n);
    minel[n-1] = a.back();
    for(int i=n-2; i>=0; i--){
        minel[i] = min(minel[i+1], a[i]);
    }
    for(int i=1; i<n; i++){
        if(a[i-1] > a[i])maxdiff = max(maxdiff, a[i-1] - minel[i]);
    }

        cout << (maxdiff ? floor(log2(maxdiff)) +1 : maxdiff) << "\n";
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
