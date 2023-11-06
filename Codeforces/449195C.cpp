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
 


ll qexp(ll a, ll b){
    ll res = 1;
    while(b){
        if(res > 1e10 + 7)return -1;
        if(b&1)res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
 
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto&x : a)cin >> x;
    map<ll,int> mp;
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll arrhash = 1;
        ll tofind = 1;
        bool state = true;
        for(int j=2; j*j <= a[i]; j++){
            if(a[i]%j == 0){
                int count =  0;
                while(a[i]%j == 0){
                    a[i] /= j;
                    count++;
                }
                count %= k;
                arrhash *= qexp(j,count);
                if(state){
                    tofind *= qexp(j,(k-count)%k);
                    if(tofind < 0)state = false;
                }
            }
        }
        if(a[i] != 1){
            arrhash *= a[i];
            if(state)tofind *= qexp(a[i],k-1);
        }
        if(state)ans += mp[tofind];
        mp[arrhash]++;
    }
    cout << ans << "\n";
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
