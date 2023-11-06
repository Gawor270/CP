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


ll f(ll b, ll k, ll a, ll c){
    return (b-k)*(b-k) - 4*a*c;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> l(n);
    for(auto&x : l)cin >> x;
    sort(all(l));
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(c <= 0){
            cout << "NO" << "\n";
        } else {
            ll low = b - 2*sqrt(a*c);
            ll up  = b + 2*sqrt(a*c);
            auto p = lower_bound(all(l),low);
            bool flag = true;;
            while(p != l.end() && (*p) < up+1){
                ll val = *p;
                if((b-val)*(b-val) - 4*a*c < 0){
                    cout << "YES" << "\n";
                    cout << val << "\n";
                    flag = false;
                    break;
                }
                p++;
            }
            if(flag){
                cout << "NO" << "\n";
            }
        }
    }

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
