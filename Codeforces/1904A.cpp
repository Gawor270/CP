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
    ll a,b,xk,yk,xq,yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    set<pair<ll,ll>> s;
    vector<pair<ll,ll>> moves = {{-a,-a},{a,a},{-a,a},{a,-a}};
    if(a != b){
        moves = {{-a,b},{a,b},{a,-b},{-a,-b},{-b,a},{-b,-a},{b,a},{b,-a}};
    }

    for(pair<ll,ll> &p : moves){
        ll nx = xk + p.first;
        ll ny = yk + p.second;
        for(pair<ll,ll> &q : moves){
            ll nx2 = nx + q.first;
            ll ny2 = ny + q.second;
            if(nx2 == xq && ny2 == yq){
                s.insert({nx,ny});
            }
        }
    }

    cout << s.size() << "\n";
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
