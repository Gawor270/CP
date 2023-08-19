#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

    vector grid(n,vector<int>(m,0));
    int countone = 0;

    for(int i=0; i<n; i++){
        string inp;
        cin >> inp;
        for(int j=0; j<m; j++){
            grid[i][j] = inp[j] - '0';
            if(grid[i][j])countone++;
        }
    }

    int minim = 3;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+1 < n && j + 1 < m)minim = min(minim,grid[i][j] + grid[i+1][j] + grid[i][j+1]);
            if(i+1 < n && j - 1 >= 0)minim = min(minim,grid[i][j] + grid[i+1][j] + grid[i][j-1]);
            if(i-1 >=0 && j + 1 < m)minim = min(minim,grid[i][j] + grid[i][j+1] + grid[i-1][j]);
            if(i-1 >=0 && j - 1 >= 0)minim = min(minim,grid[i][j] + grid[i][j-1] + grid[i-1][j]);
        }
    }

    if(minim){
        cout << countone - minim + 1 << "\n";
    }
    else{
        cout << countone << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}