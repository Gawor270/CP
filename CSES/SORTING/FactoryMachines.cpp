#include <bits/stdc++.h>
#include <iostream>

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

bool eval(vector<ll>& a, ll thre, ll target){
    ll countproducts = 0;
    for(ll x : a){
        countproducts += thre/x;
        if(countproducts >= target)return true;
    }
    return false;
}

void solve() {
    ll n,t;
    cin >> n >> t;
    vector<ll> k(n);
    for(auto& x : k)cin >> x;
    ll l = -1;
    ll r = 1e18;
    while(r - l > 1){
        ll m = l + (r-l)/2;
        if(eval(k,m,t)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
