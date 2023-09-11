#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll unsigned long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll ans[5000007];
ll presum[1500][1500];

void prepro(){
    presum[0][0] = 1;
    ans[1] = 1;
    ll startdiff = 2;
    ll startval = 1;
    for(ll i=0; i<1500; i++){
        if(i){
            presum[i][0] = presum[i-1][0] + startval*startval;
        }
        ans[startval] = presum[i][0];
        ll curr = startval;
        ll currdiff = startdiff;
        for(ll j=1; j<1500; j++){
            curr += currdiff;
            presum[i][j] = presum[i][j-1];
            if(i){
                presum[i][j] += presum[i-1][j];
            }
            presum[i][j] += curr*curr;
            if(i){
                presum[i][j] -= presum[i-1][j-1];
            }
            ans[curr] = presum[i][j];
            currdiff++;
        }
        startval += (startdiff-1) ;
        startdiff++;
    }

}
void solve() {
    ll n;
    cin >> n;
    cout << ans[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prepro();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
