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
    int n,cnt1,cnt2;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    a.insert(a.end(),a.begin(), a.end());

    int res = 1e9;
    cnt1 = cnt2 = 1;
    for(int i=2*n-2; i>=0; i--){
        if(a[i] == a[i+1]){
            cnt1++;
            cnt2++;
        }
        else if(a[i] > a[i+1]){
            cnt2++;
            cnt1 = 1;
        }
        else{
            cnt1++;
            cnt2 = 1;
        }

        if(cnt2 == n){
            res = min(res,n-i+1);
            res= min(res,i+1);
        }
        if(cnt1 == n){
            res = min(res,n-i);
            res = min(res,i+2);
        }
    }
    if(res == 1e9)res = -1;
    cout << res << "\n";

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
