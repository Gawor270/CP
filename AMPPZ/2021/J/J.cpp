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

const int MAX_N = 2001;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
vector<char> path;
vector<char> currpath;
int n,m;
char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

bool dfs(int i, int j){
    if(vis[i][j])return false;
    vis[i][j] = true;
    if(i == n-1 & j == m-1){
        path = currpath;
        return true;
    }
    bool v1 = false, v2 = false;
    if(i+1 < n && (grid[i+1][j] == 'O' || grid[i+1][j] == '@' || grid[i+1][j] == '.')){
        currpath.push_back('D');
        if(dfs(i+1,j))return true;
        currpath.pop_back();
    }
    if(j+1 < m && (grid[i][j+1] == 'O' || grid[i][j+1] == '@' || grid[i][j+1] == '.')){
        currpath.push_back('P');
        if(dfs(i,j+1))return true;
        currpath.pop_back();
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            vis[i][j] = false;
        }
    }
    vector<bool> staten(n,false);
    vector<bool> statem(m,false);
    int i = 0, j = 0;
    if(dfs(0,0)){
        for(char d : path){
            if(d == 'P'){
                if((grid[i][j+1] == '@' && staten[i] == statem[j+1]) || (grid[i][j+1] == 'O' && staten[i] != statem[j+1])){
                    statem[j+1] = (statem[j+1] != true);
                }
                j++;
            }
            else{
                if((grid[i+1][j] == '@' && staten[i+1] == statem[j]) || (grid[i+1][j] == 'O' && staten[i+1] != statem[j])){
                    staten[i+1] = (staten[i+1] != true);
                }
                i++;
            }

        }
        cout << "TAK" << "\n";
        for(bool s : staten){
            cout << (s ? "T" : "N");
        }
        cout << "\n";
        for(bool s : statem){
            cout << (s ? "T" : "N");
        }
        cout << "\n";
        for(char c : path){
            cout << c;  
        }
        cout << "\n";
    }else{
        cout << "NIE" << "\n";
    }
    path.clear();
    currpath.clear();
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
