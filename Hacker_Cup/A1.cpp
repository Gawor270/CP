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

vector<vector<int>> vis;
vector<vector<char>> grid;

pi moves[] = {{0,1},{1,0},{-1,0},{0,-1}};

int r,c;

int dfs(int x, int y,int token){
    vis[x][y] = token;
    int count = 0;
    for(pi p : moves){
        int nx = x + p.first;
        int ny = y + p.second;
        if(nx >= 0 && nx < r && ny >=0 && ny < c){
            if(vis[nx][ny] != token){
                if(grid[nx][ny] == 'W'){
                    count += dfs(nx,ny,token);
                }
                else if(grid[nx][ny] == '.'){
                    vis[nx][ny] = token;
                    count++;
                }
            }
        }
    }
    return count;
}

void solve() {
    cin >> r >> c;
    vis.resize(r);
    grid.resize(r);
    for(int i=0; i<r; i++){
        vis[i].resize(c);
        grid[i].resize(c);
        for(int j=0; j<c; j++){
            cin >> grid[i][j];
            vis[i][j] = false;
        }
    }

    int token =1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!vis[i][j] && grid[i][j] == 'W'){
                if(dfs(i,j,token) == 1){
                    cout << "YES" << "\n";
                    return;
                }
                token++;
            }
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
