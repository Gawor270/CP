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
    int n;
    cin >> n;
    vector<int> cnt(n+1,0), mx(n+1,0);
    for(int i=0; i<n; i++){
        int inp;
        cin >> inp;
        if(inp <= n)cnt[inp]++;
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+= i){
            mx[j] += cnt[i];
        }
    }
    
    cout << *max_element(all(mx)) << "\n";
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
