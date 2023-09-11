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
    vector<pi> ord(n);
    for(int i=0; i<n; i++)ord[i] = {0,i+1};
    int t = n;
    while(t--){
        int k = n-1;
        while(k--){
            int inp;
            cin >> inp;
            ord[inp-1].first += (k-1);
        }
    }

    sort(ord.rbegin(),ord.rend());
    for(int i=0; i<n; i++){
        cout << ord[i].second << " ";
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
