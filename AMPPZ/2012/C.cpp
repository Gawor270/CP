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
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<pi> count(k);
    int ans= 0 ;
    int parity  =0;
    int mindist = 1e9;
    for(auto&x : a)cin >> x, x &= 1;
    for(int i=0; i<k;i++){
        int count0 =0, count1 = 0;

        for(int j=i; j<n; j+= k){
            if(a[j])count1++;
            else count0++;
        }
        count[i] = {count0, count1};
        mindist = min(mindist,abs(count1 - count0));
        if(count0 < count1){
            parity = (parity+1)&1;
            ans += count0;
        }
        else{
            ans += count1;
        }
    }
    if(parity){
        ans += mindist;
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
