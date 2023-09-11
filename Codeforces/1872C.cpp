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
    ll l,r;
    cin >> l >> r;
    if(r-l+1 == 1){
        int tmp = l;
        int div = 2;
        bool ok = false;
        for(; div*div <= tmp; div++){
            if(tmp%div == 0){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << div << " " <<  tmp - div << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else{
        int tmp = r;
        if(r&1)tmp--;
        if(tmp == 2){
            cout << -1 << "\n";
        } else {
        cout << 2 << " " <<  tmp-2 << "\n";
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
