#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1652
using namespace std;

const int MAXN = 1e3 + 5;

int grid[MAXN][MAXN];
int prefsum[MAXN][MAXN];
int main(){
    char c;
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c == '*')grid[i][j] = 1; 
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            prefsum[i+1][j+1] = prefsum[i+1][j] + prefsum[i][j+1] - prefsum[i][j] + grid[i][j];
        }
    }

    while(q--){
        int x1,x2,y1,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefsum[y2][x2] - prefsum[y2][x1-1] - prefsum[y1-1][x2] + prefsum[y1-1][x1-1] << "\n";
    }
}