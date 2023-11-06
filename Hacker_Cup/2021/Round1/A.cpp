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
    int N;
    cin >> N;
    string W;
    cin >> W;
    vector<ll> pairs;
    ll ans = 0;
    for(int i=0; i<N; i++)if(W[i]!='F')pairs.push_back(i);

    for(int i=1; i<(int)pairs.size(); i++){
        ll a = pairs[i-1];
        ll b = pairs[i];
        if(W[a] != W[b]){
            ans = (ans + (a+1)*(N-b))%MOD;
        }
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
