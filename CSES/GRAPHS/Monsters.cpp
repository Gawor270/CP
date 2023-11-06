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

void bfs(vector<pi>& mon, pi player){
    REP(i,MAX_N){ 
        REP(j,MAX_N){
            dist[i][j] = INF;
        }
    }

    queue<pi> mq;
    queue<pi> aq;

    for(pi mo : mon){
        dist[mo.first][mo.second] = -1;
        mq.push(mo);
    }

    while(!mq.empty()){
        pi u = mq.front();
        mq.pop();
        for(pi move : moves){
            int nx = u.first + move.first;
            int ny = u.second + move.second;
            if(nx >=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == '.' && dist[nx][ny] == INF){
                dist[nx][ny] = dist[u.first][u.second] -1;
                mq.push({nx,ny});
            }
        }
    }
    
    parent[player.first][player.second] = {-1,-1};
    dist[player.first][player.second] = 1;
    aq.push(player);

    while(!aq.empty()){
        pi u = aq.front();
        aq.pop();
        for(pi move : moves){
            int nx = u.first + move.first;
            int ny = u.second + move.second;
            if(nx >=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == '.' && abs(dist[nx][ny]) > dist[u.first][u.second] + 1){
                dist[nx][ny] = dist[u.first][u.second] +1;
                parent[nx][ny] = {u.first, u.second};
                aq.push({nx,ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<pi> bounds;
    vector<pi> mon;
    pi player = {-1,-1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if((j == 0 || i == 0 || i == n-1 || j == m-1) && grid[i][j] == '.'){
                bounds.push_back({i,j});
            }
            if(grid[i][j] == 'M')mon.push_back({i,j});
            if(grid[i][j] == 'A')player = {i,j};
        }
    }
    if(player.first == -1 &&  player.second == -1){
        cout << "NO" << "\n";
        return;
    }
    if(player.first == 0 || player.second == 0 || player.first == n-1 || player.second == n-1){
        cout << "YES" << "\n"<< 0 << "\n";
        return;
    }

    if(SIZE(bounds) == 0){
        cout << "NO" << "\n";
        return;
    }

    bfs(mon,player);
    for(pi b : bounds){
        if(dist[b.first][b.second] > 0  && dist[b.first][b.second] != INF){
            
                    cout << "YES" << "\n";
            cout << dist[b.first][b.second]-1 << "\n";
            vector<char> ans;
            pi u  = {b.first, b.second};
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
            return;
        }
    }
    cout << "NO" << "\n";
    
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
