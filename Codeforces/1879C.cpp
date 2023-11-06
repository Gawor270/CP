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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    string s;
    cin >> s;
    ll ans =1;
    ll add = 0;
    ll count = 1;
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            count++;
            add++;
        }
        else{
            ans = (ans*count)%MOD;
            count = 1;
        }
    }
    ans = (ans*count)%MOD;
    for(ll f = add; f>=1; f--){
        ans = (ans*f)%MOD;
    }
    cout << add << " " << ans << "\n";
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
