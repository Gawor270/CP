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

const int MAX_N = 505; 
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n,m;
    cin >> n >> m;

    vector board(n,vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }


    
    int mode = 0;
    int count = 0;
    bool flag = true;
    for(int i=0; i<n; i++){
        count = 0;
        for(int j=0; j<m; j++){
            if(board[i][j] == 'U'){
                board[i][j] = mode ? 'B' : 'W';
                board[i+1][j] = mode ? 'W' : 'B';
                count++;
                mode ^= 1;
            }

        }
        if(count&1)flag = false;
        mode = 0;
    }

    mode = count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[j][i] == 'L'){
                board[j][i] = mode ? 'B' : 'W';
                board[j][i+1] = mode ? 'W' : 'B';
                count++;
                mode ^= 1;
            }
        }
        if(count&1)flag = false;
        mode = 0;
    }

    if(flag){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << -1 << "\n";
    }

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
