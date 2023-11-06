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
    vector leng(n,vector<pi>(m,{2,2}));
    vector maxs(n,vector<int>(m,2));
    int ans = 0;

    leng[0][0] = {1,1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 1  || j == 1){
                if(i == 1 && j == 1){
                    ans = max(ans,4);
                    leng[i][j] = {2,2};
                }
                else if(i == 1){
                    leng[i][j].first = 1;
                    if(grid[i][j] - grid[i][j-1] == grid[i][j-1] - grid[i][j-2]){
                        leng[i][j].second = leng[i][j-1].second +1;
                    }
                    else{
                        leng[i][j].second = 1;
                    }
                }
                else{
                    leng[i][j].second = 1;
                }
            }
            else if(i>1 && j>1){
                if(grid[i][j] - grid[i][j-1] == grid[i][j-1] - grid[i][j-2]){
                    leng[i][j].second = leng[i][j-1].second +1;
                }
                else{
                    leng[i][j].second = 1;
                }
                if(grid[i][j] - grid[i-1][j] == grid[i-1][j] - grid[i-2][j]){
                    leng[i][j].first = leng[i-1][j].first +1;
                }
                else{
                    leng[i][j].first = 1;
                }
                int val = min(leng[i][j].first,leng[i][j].second);
                ans = max(ans, val*val); 
            }
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
