#include <bits/stdc++.h>

using namespace std;

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
int dist[MAX_N][MAX_N];
pi parent[MAX_N][MAX_N];

int n,m;

pi moves[] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int bfs(int xa, int ya, int xb, int yb){
    REP(i,MAX_N){ REP(j,MAX_N)dist[i][j] = INF;}
    queue<pi> q;
    parent[xa][ya] = {-1,-1};
    dist[xa][ya] = 0;
    q.push({xa, ya});

    while(!q.empty()){
        pi u = q.front();
        q.pop();
        for(pi move : moves){
            int nx = u.first + move.first;
            int ny = u.second + move.second;
            if(nx >= 0 && nx < n && ny >=0 && ny < m && dist[nx][ny] == INF && (grid[nx][ny] == '.' || grid[nx][ny] == 'B') ){
                dist[nx][ny] = dist[u.first][u.second] + 1;
                parent[nx][ny] = {u.first,u.second};
                q.push({nx,ny});
            }
        }
    }
    return dist[xb][yb];
}

void solve() {
    cin >> n >> m;
    int xa, ya, xb, yb;
    REP(i,n){
        REP(j,m){
            cin >> grid[i][j];
            if(grid[i][j] == 'A')xa = i, ya = j;
            if(grid[i][j] == 'B')xb = i, yb = j;
        }
    }


    int res = bfs(xa,ya,xb,yb);
    if(res == INF){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        cout << res << "\n";
        vector<char> ans;
        pi u  = {xb,yb};
        while(u.first != -1 && u.second != -1){
            pi v = parent[u.first][u.second];
            pi vec = {u.first - v.first, u.second - v.second};
            if(vec.first == 1){
                ans.push_back('D');
            }
            else if(vec.first == -1){
                ans.push_back('U');
            }
            else if(vec. second == 1){
                ans.push_back('R');
            }
            else{
                ans.push_back('L');
            }
            u = v;
        }
        for(int i=ans.size()-2; i >=0 ; i--){
            cout << ans[i];
        }
        cout << "\n";
    }


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
