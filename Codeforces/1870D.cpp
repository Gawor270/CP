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
    ll k ;
    cin >> n;
    vi c(n);
    for(auto&x : c)cin >> x;
    cin >> k;
    int minim = MOD;
    for(int i = n-1; i>=0; i--){
        minim = min(minim, c[i]);
        c[i] = minim;
    }
    ll last = k/c[0];
    cout << last << ' ';
    k -= last*c[0];
    for(int i=1; i<n; i++){
        int v = c[i] - c[i-1];
        if(v){
            last = min(last, k/v);
            k -= last*v;
        }
        cout << last << " ";
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
