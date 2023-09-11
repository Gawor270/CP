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
    vector grid(n,vector<int>(m));
    int start = 0;
    for(int i=0; i<m; i++){
        int upp = min(n,m-1);
        for(int j=0; j<upp; j++){
            grid[j][i] = (start + j)%m;
        }
        for(int j=upp; j<n; j++){
            grid[j][i] = start;
        }
        start = (start-1 + m)%m;
    }

    if(m > 1){
        cout << min(n+1,m) << "\n";
    } else{
        cout << 0 << "\n";
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
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
