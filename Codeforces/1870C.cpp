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
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    vector<int> ans(k+1,0);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(),a.rend());
    int minind = 1e9;
    int maxind = -1;
    for(int i=0; i<n; i++){
        minind = min(minind,a[i].second);
        maxind = max(maxind,a[i].second);
        ans[a[i].first] = 2*(maxind - minind +1);
    }

    for(int i=1; i<=k; i++){
        cout << ans[i] << " ";
    }
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
