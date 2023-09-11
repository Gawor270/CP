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
    vi a(n);
    for(auto&x : a)cin >> x;
    sort(all(a));
    
    vector<vector<int>> rep(n);
    int i=0;
    int counter = 0;
    int ans = 1;
    while(i+1<n){
       if(a[i] == a[i+1]){
           rep[counter].push_back(a[i]);
           counter++;
       }
       else if(a[i+1] - a[i] == 1)counter = 0;
       else if(a[i+1] - a[i] != 1){
           counter = 0;
           ans++;
       }
       i++;
    }
    for(int i=0; i<n; i++){
        if(rep[i].size())ans++;
        for(int j=1; j<(int)rep[i].size(); j++){
            if(rep[i][j] - rep[i][j-1] != 1)ans++;
        }
    }

    cout << ans << "\n";
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
