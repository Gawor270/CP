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

const int MAX_N = 3e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int vis[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];


pi moves[] = {{0,1},{1,0},{-1,0},{0,-1}};

pi point;

pi dfs(int x, int y,int token,int r, int c){
    int countw = 0;
    int count = 0;
    if(grid[x][y] == 'W')countw++;
    vis[x][y] = 1;
    for(pi p : moves){
        int nx = x + p.first;
        int ny = y + p.second;
        if(nx >= 0 && nx < r && ny >=0 && ny < c){
            if(vis[nx][ny] == 0){
                if(grid[nx][ny] == 'W'){
                    pi res = dfs(nx,ny,token,r,c);
                    count += res.first;
                    countw += res.second;
                }
            }
            if(vis[nx][ny] != token && grid[nx][ny] == '.'){
                    count++;
                    vis[nx][ny] = token;
                    point = {nx,ny};
            }
            }
        }
    return {count,countw};
}

void solve() {
    int r,c;
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }

    int token =1;
    int res = 0;
    map<pi,int> mp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!vis[i][j] && grid[i][j] == 'W'){
                token++;
                pi ans = dfs(i,j,token,r,c);
                if(ans.first == 1){
                    mp[point] += ans.second;
                    res = max(res, mp[point]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
