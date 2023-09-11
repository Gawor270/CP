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
    vector<ll> c(n);
    for(auto& x : c)cin >> x;
    ll mx1 = 0;
    ll mx2 = 0;
    for(int i=0; i<n; i++){
        if(i&1){
            if(c[i] > 0)mx1 += c[i];
        }
        else{
            if(c[i] > 0)mx2 += c[i];
        }
    }

    if(*max_element(all(c)) < 0){
        cout << *max_element(all(c)) << "\n";
    }
    else cout << max(mx1,mx2) << "\n";

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
