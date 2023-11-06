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




ll fastexp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1)res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}




void solve() {
    int n;
    cin >> n;

    ll res = 1;
    for(ll d = 2; d*d<=n; d++){
        if(n%d ==0){
            ll cnt =0;
            ll d2 = n/d;
            while(n%d == 0){
                cnt++;
                n/=d;
            }
            res = (res*((fastexp(d,cnt+1)-1)*(fastexp(d-1,MOD-2))%MOD)%MOD);

            cnt = 0; 
            while(n%d2 == 0){
                cnt++;
                n/=d2;
            }
            res = (res*((fastexp(d2,cnt+1)-1)*(fastexp(d2-1,MOD-2))%MOD)%MOD);
        }
    }
    cout << res << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
