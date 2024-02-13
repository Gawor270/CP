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

ll cabs(ll a, ll b){
    if(a > b)swap(a,b);
    return b -a;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto&x : a)cin >> x;
    if(k>2){
        cout << 0 << "\n";
        return;
    }
    sort(all(a));
    ll minim = a[0];
    for(int i=1; i<n; i++){
        minim = min(minim,cabs(a[i-1],a[i]));
    }
    if(k == 2){
        for(int i=0; i<n; i++){
           for(int j=0; j<i; j++){
            ll diff = cabs(a[i],a[j]);
            minim = min(minim,diff);
            auto ptr = lower_bound(all(a),diff);
            int ind = distance(a.begin(),ptr);
            minim = min(minim,cabs(diff,a[ind]));
            if(ind > 0)minim = min(minim,cabs(diff,a[ind-1]));
            if(ind < n-1)minim = min(minim,cabs(diff,a[ind+1]));
           } 
        }
    }
    cout << minim << "\n";
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
