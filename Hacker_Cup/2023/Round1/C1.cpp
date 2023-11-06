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

const int MAX_N = 4e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void process(vector<bool>& S, vector<bool> state,int n){
    for(int i=1; i<=n; i++){
        if(state[i]){
            for(int j =i; j<=n; j+= i){
                S[j] = (S[j] != true);
            }
        }
    }

}

void solve() {
    int n;
    cin >> n;
    vector<bool> S(n+1,true);
    for(int i=1; i<=n; i++){
        char inp;
        cin >> inp;
        if(inp == '0')S[i] = false;
    }
    int q;
    cin >> q;
    vector<bool> state(MAX_N,false);
    ll ans = 1;
    while(q--){

    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
