#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1079
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


ll factorial[MAX_N];
ll inverse[MAX_N];

ll fastexp(ll x, ll pow){
    ll res =1;
    while(pow){
        if(pow&1)res = (res*x)%MOD;
        x = (x*x)%MOD;
        pow >>= 1;
    }
    return res;
}


void precompute(){
    factorial[0] = inverse[0] = 1;

    for(ll i = 1; i<= MAX_N; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
        inverse[i] = fastexp(factorial[i],MOD-2);
    }
}

void solve() {
    ll a,b;
    cin >> a >> b;
    ll res =1;
    res = ((factorial[a]*((inverse[b]*inverse[a-b])%MOD))%MOD);
    cout << res << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    precompute();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
