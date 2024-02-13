#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int getDigit(ll n, ll k){
    string s = to_string(n);
    return s[k] - '0';
}

ll qexp (ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll k;
    cin >> k;
    ll num = 9;
    ll dig = 1;
    while(k > num*dig){
        k -= num*dig;
        num *= 10;
        dig++;
    }
    cout << getDigit(qexp(10,dig-1) + (k-1)/(dig),(k-1)%dig) << "\n";

    
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
