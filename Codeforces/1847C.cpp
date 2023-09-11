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


const int MAXVAL = (1 << 8);

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    vector<bool> poss(MAXVAL,false);
    poss[0] = 1;
    int curr = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        curr ^= a[i];
        for(int pref=0; pref<MAXVAL; pref++){
            if(poss[pref])ans = max(ans, curr^pref);
        }
        poss[curr] = 1;
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
