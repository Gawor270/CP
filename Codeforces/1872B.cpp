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
    vector<pair<int,int>> ds(n);
    for(int i=0; i<n; i++){
        int d,s;
        cin >> d >> s;
        ds[i] = {d,s};
    }
    sort(ds.begin(), ds.end());
    int ans = ds[0].first;
    ans += ds[0].second&1 ? ds[0].second/2 : ds[0].second/2-1;
    for(int i=1; i<n; i++){
        int maxjump = ds[i].second&1 ? ds[i].second/2 : ds[i].second/2-1;
        ans = min(ans, ds[i].first + maxjump);
    }

    cout << ans << "\n";

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
