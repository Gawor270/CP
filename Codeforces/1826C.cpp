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
    int n,m;
    cin >> n >> m;
    if(n&1){
        if(n == 1){
            puts("YES");
        } else {
            int div = 3;
            for(; div*div <= n;div+= 2){
                if(n%div == 0){
                    break;
                }
            }
            if(n%div != 0)div = n;
            puts((m >= div ? "NO" : "YES"));
        }
    } else {
        puts((m > 1 ? "NO" : "YES"));
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
