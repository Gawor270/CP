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

ll countexp[50];

void solve() {
    int n,q;
    memset(countexp,0LL,50*sizeof(ll));
    cin >> n >> q;
    vector<ll> a(n);
    vi x(q);
    for(auto&b : a)cin >> b;
    for(auto&b : x)cin >> b;

    int minim = 50;
    for(ll b : x){
        if(b < minim){
            countexp[b]++;
            minim = b;
        }
    }

    for(ll& b : a){
        ll cpy = b;
        ll exp = 1;
        ll val = 2;
        while(cpy%val ==0){
            b += countexp[exp]*val/2;
            exp++;
            val <<= 1;
        }
    }

    for(ll&b : a)cout << b << " ";
    cout << "\n";
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
