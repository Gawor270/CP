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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


char grid[8][8];
bool poss[8][8];

pair<int,int> moves[] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

int queens(int row = 0){
    if(row == 8) return 1;
    bool newposs[8][8];
    memcpy(newposs, poss, sizeof(poss)); 
    int count = 0;
    for(int i=0; i<8; i++){
        if(poss[row][i]){
            poss[row][i] = false;
            for(int j=0; j<8; j++){
                for(auto mv : moves){
                    int x = row + mv.first*j;
                    int y = i + mv.second*j;
                    if(x >= 0 && x < 8 && y >= 0 && y < 8){
                        poss[x][y] = false;
                    }
                }
            }
            count += queens(row+1);
        }
        memcpy(poss, newposs, sizeof(poss));
    }
    return count;
}

void solve() {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> grid[i][j];
            poss[i][j] = (grid[i][j] == '.');
        }
    }
    cout << queens() << endl;
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
