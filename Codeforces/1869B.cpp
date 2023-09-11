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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    ll n,k,a,b;
    cin >> n >> k >> a >> b;
    vector<pair<ll,ll>> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i].first >> c[i].second; 
    }
    pair<ll,ll> acord = c[a-1];
    pair<ll,ll> bcord = c[b-1];
    ll ans = abs(acord.first - bcord.first) + abs(acord.second - bcord.second);
    ll mina = 1e12;
    ll minb = 1e12;
    for(int i=0; i<k; i++){
        mina = min(mina, abs(acord.first - c[i].first) + abs(acord.second - c[i].second));
        minb = min(minb, abs(bcord.first - c[i].first) + abs(bcord.second - c[i].second));
    }

    cout << min(ans, mina + minb) << "\n";
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
