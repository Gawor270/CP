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



void solve() {
    ll n,q;
    cin >> n;
    ll suma = 0, suma2 =0, sumb = 0, sumb2= 0;

    for(int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        suma = (suma + a)%MOD;
        suma2 = (suma2 + (a*a)%MOD)%MOD;
        sumb = (sumb + b)%MOD;
        sumb2 = (sumb2 + (b*b)%MOD)%MOD;
    }

    cin >> q;

    ll sum = 0 ;
    while(q--){
        ll x,y;
        cin >> x >> y;
        ll x2 = (x*x)%MOD;
        ll y2 = (y*y)%MOD;
        ll xsuma = (x*suma)%MOD;
        ll ysumb = (y*sumb)%MOD;
        ll sum1 = (((n*x2)%MOD + suma2)%MOD -(2*xsuma)%MOD + MOD)%MOD;
        ll sum2 = (((n*y2)%MOD + sumb2)%MOD -(2*ysumb)%MOD + MOD)%MOD;
        sum = (sum + sum1 + sum2)%MOD;

    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
