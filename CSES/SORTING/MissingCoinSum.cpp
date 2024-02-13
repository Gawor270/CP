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

ll qexp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1)res*=a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll brute(vector<int> &a, ll tofind){
    int n = a.size();
    ll bound = qexp(2,n);
    for(ll mask = 1; mask <= bound; mask++){
        ll sum = 0;
        for(ll bit = 1; bit <= n; bit++ ){
            if(mask&qexp(2,bit))sum += a[bit-1];
        }
        if(sum == tofind)return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for(auto&a : x)cin >> a;
    sort(all(x));
    if(x[0] != 1){
        cout << 1 << "\n";
        return;
    }
    ll sum = 1;
    for(int i=1; i<n; i++){
        if(x[i] > sum+1){
            cout << sum +1 << "\n";
            return;
        }
        sum += x[i];
    }
    cout << sum+1 << "\n";
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
