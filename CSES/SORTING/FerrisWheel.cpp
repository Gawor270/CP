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
    int n, x;
    cin >> n >> x;
    vi p(n);
    for(auto&a : p)cin >> a;
    sort(all(p));
    int i = 0;
    int j = n-1;
    // for(int k =1; k<n; k++){
    //     if(p[0] + p[k] <=x) j =k;
    // }
    int ans = 0;
    while(i <= j){
        if(i == j){
            ans++;
            j--;
        }
        else if(p[i] + p[j] <= x){
            ans++;
            i++,j--;
        }
        else{
            ans++;
            j--;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
