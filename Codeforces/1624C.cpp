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

const int MAX_N = 53;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    sort(a.rbegin(), a.rend());
    vector<bool> used(n,false);
    for(int i=n; i >= 1; i--){
        bool flag = true;
        for(int j = 0; j<n; j++){
            if(used[j])continue;
            int tmp = a[j];
            while(tmp){
                if(tmp == i){
                    flag = false;
                    used[j] = true;
                    break;
                }
                tmp >>= 1;
            }
            if(!flag)break;
        }
        if(flag){
            puts("NO");
            return;
        }
    }

    puts("YES");


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
