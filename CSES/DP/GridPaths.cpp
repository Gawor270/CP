#include <iostream>
#include <vector>

//https://cses.fi/problemset/task/1638
using namespace std;

const long long MOD = 1e9 +7;

char grid[1000][1000];
int dp[1001][1001];

int gridpaths(int n){
    if(grid[0][0] == '*') return 0;
    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i-1][j-1] == '*' || (i==1 && j==1))continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    
    return dp[n][n];
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cout << gridpaths(n);
}
