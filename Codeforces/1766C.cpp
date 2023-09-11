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
    int m;
    cin >> m;
    vector grid(2,vector<char>(m));

    for(int i=0; i<2; i++){
        for(int j=0; j<m ;j++){
            cin >> grid[i][j];
        }
    }
    vector<int> dp(m,-1);
    if(grid[0][0] == 'B' && grid[1][0] == 'B')dp[0] = 2;
    else if(grid[0][0] == 'B')dp[0] = 0;
    else if(grid[1][0] == 'B')dp[0] = 1;

    for(int i=1; i<m; i++){
        switch(dp[i-1]){
            case -1:
                puts("NO");
                return;

            case 0:
                if(grid[0][i] == 'B')dp[i] = 0;
                if(dp[i] == 0 && grid[1][i] == 'B')dp[i] = 1;
                break;

            case 1:
                if(grid[1][i] == 'B')dp[i] = 1;
                if(dp[i] == 1 && grid[0][i] == 'B')dp[i] = 0;
                break;
            
            case 2:
                if(grid[0][i] == 'B' && grid[1][i] == 'B')dp[i] = 2;
                else if(grid[0][i] == 'B')dp[i] = 0;
                else if(grid[1][i] == 'B')dp[i] = 1;
        }
    }
    dp[m-1] != -1 ? puts("YES") : puts("NO");
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
