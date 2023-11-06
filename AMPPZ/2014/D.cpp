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

const int MAX_N = 2e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


ll countocc[MAX_N];

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;

    for(int x : a)countocc[x]++;

    ll ans = countocc[1] > 0 ? countocc[1]*(countocc[1]-1) + countocc[1]*(n - countocc[1]) : 0;
    ll mx = *max_element(all(a));
    for(int i=2; i<=mx; i++){
            ans += countocc[i]*(countocc[i]-1);
            for(int j=2*i; j<=mx; j+=i){
                ans += countocc[i]*countocc[j];
            }
    }
    cout << ans << "\n";
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
