#include <bits/stdc++.h>

using namespace std;
// https://cses.fi/problemset/task/1192
#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

char grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int n,m;

pi moves[] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void dfs(int x, int y){
    vis[x][y] = true;
    for(pi move : moves){
        int nx = x + move.first;
        int ny = y + move.second;
        if(nx >=0 && nx < n && ny < m && ny >=0 && !vis[nx][ny] && grid[nx][ny] == '.')dfs(nx,ny);
    }
}

void solve() {
    cin >> n >> m;
    REP(i,n){ REP(j,m){ cin >> grid[i][j]; } }

    int count = 0;
    REP(i,n){
        REP(j,m){
            if(grid[i][j] == '.' && !vis[i][j]){
                count++;
                dfs(i,j);
            }
        }
    }

    cout << count << "\n";

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
