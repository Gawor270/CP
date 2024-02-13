#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1646
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
    int n,q;
    cin >> n >> q;
    vector<ll> prefsum(n+1);
    prefsum[0]= 0;
    for(int i=1; i<=n; i++){
        int inp;
        cin >> inp;
        prefsum[i] = prefsum[i-1] + inp;
    } 
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << prefsum[b] - prefsum[a-1] << "\n";
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
