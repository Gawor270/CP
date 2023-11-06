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

ll GCD(ll a, ll b){return b ? GCD(b,a%b) : a;}
ll LCM(ll a, ll b){return a/GCD(a,b)*b;}

struct GCD_type { ll x, y, d; };
GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

void solve() {
    ll a,n,b,m;
    cin >> a >> n >> b >> m;
    ll d = GCD(n,m);
    ll k = LCM(n,m);
    if((b - a)%d){
        cout << "no solution" << "\n";
        return;
    }
    auto sol = ex_GCD(n,m);
    ll p1 = (b-a)/d * sol.x;
    ll p2 = m/d;
    ll p3 = n;
    ll ans = ((a + (((p1)%p2)*p3)%k)%k +k)%k;
    cout << ans << " " << k << "\n";
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
