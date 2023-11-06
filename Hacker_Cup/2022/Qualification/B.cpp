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

pi neigh[4] = {{0,1},{1,0},{-1,0},{0,-1}};

void solve() {
    int R,C;
    cin >> R >> C;
    int counttrees = 0;
    vector grid(R,vector<char>(C));
    vector goodbad(R,vector<bool>(C,false));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '^')counttrees++;
            if(grid[i][j] != '#')goodbad[i][j] = true;
        }
    }

    queue<pi> q;
    vector vis(R,vector<bool>(C,false));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(goodbad[i][j]){
                int count = 0;
                for(pi n : neigh){
                    int ni = i + n.first;
                    int nj = j + n.second;
                    if(0 <= ni && ni < R && 0 <= nj && nj < C && grid[ni][nj] != '#')count++;
                }
                if(count < 2)goodbad[i][j] = false;
            }
            if(!goodbad[i][j] && grid[i][j] != '#')q.push({i,j}),vis[i][j] = true;
        }
    }

    while(!q.empty()){
        pi u = q.front(); q.pop();
        int count = 0;
        for(pi n : neigh){
            int ni = u.first + n.first;
            int nj = u.second + n.second;
            if(0 <= ni && ni < R && 0 <= nj && nj < C){
                if(!vis[ni][nj]){
                    vis[ni][nj] = true;
                    q.push({ni,nj});
                }
                if(goodbad[ni][nj])count++;
            }
        }
        if(count < 2)goodbad[u.first][u.second] = false;
    }
    bool ok = true;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(grid[i][j] == '^' && !goodbad[i][j]){
                ok = false;
                break;
            }
            if(goodbad[i][j] && counttrees)grid[i][j] = '^';
        }
    }

    if(ok || !counttrees){
        cout << "Possible" << "\n";
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }else{
        cout << "Impossible" << "\n";
    }
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
