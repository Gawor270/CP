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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;




ll GCD(ll a, ll b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

ll LCM(ll a, ll b){
    return a*b/GCD(a,b);
}


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(auto&x : primes)cin >> x;
    
    ll res = 0;
    for(ll i=1; i<(1ll<<k); i++){
        ll prod = 1;
        for(ll j=0; j<k; j++){
            if(i & (1<<j)){
                prod *= primes[j];
            }
        }
        res += i&1 ? n/prod : -n/prod;
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) { solve(); }
}
