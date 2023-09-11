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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 20;
    for(int i=0; i<26; i++){
        int maxim = 0;
        int counter = 0;
        for(int j=0; j<n; j++){
            if(s[j] - 'a' != i){
                counter++;
                maxim = max(maxim,counter);
            } else {
                counter = 0;
            }
        }
        if(maxim == 0){
            cout << 0 << "\n";
            return;
        }
        ans = min(ans, (int)(log2(maxim)) + 1);
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
