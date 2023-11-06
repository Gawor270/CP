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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;




ll fastexp(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b&1)res = (res*a)%m;
        a = (a*a)%m;
        b >>=1;
    }
    return res;
}




void solve() {
    ll n;
    cin >> n;
    ll num = 1;
    ll no_div = 1;
    ll sum_div = 1;
    ll prod_div = 1;
    ll exp = 1;

    while(n--){
        ll x,k;
        cin >> x >> k;
        no_div = (no_div*(k+1))%MOD;
        sum_div = sum_div*(((fastexp(x,k+1,MOD)-1)*fastexp(x-1,MOD-2,MOD))%MOD)%MOD;
        ll val = fastexp(x,k*(k+1)/2,MOD);
        prod_div = (fastexp(prod_div,k+1,MOD)*fastexp(val,exp,MOD))%MOD;
        exp = (exp*(k+1))%(MOD-1);
    }
    
    printf("%lld %lld %lld\n",no_div,sum_div,prod_div);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) { solve(); }
}
