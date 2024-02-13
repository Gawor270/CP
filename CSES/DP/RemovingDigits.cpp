#include <iostream>
#include <vector>
//https://cses.fi/problemset/task/1637
using namespace std;

int removdig(int n,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n] > 0) return dp[n];

    int cpy = n;
    int val = INT32_MAX;
    while(cpy){
        if(cpy%10 != 0) val = min(val,1+removdig(n-cpy%10,dp));
        cpy/=10;
    }
    dp[n] = val;
    return val;

}

int removedigbottomup(int n){
    vector<int> dp(n+1,1e9);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        int cpy = i;
        while(cpy){
            if(cpy%10 != 0){ 
                if(dp[i - cpy%10] + 1 < dp[i]) dp[i] = dp[i-cpy%10] + 1;
            }
            cpy /=10;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    cout << removedigbottomup(n) << "\n";
    // cout << removdig(n,dp);
    return 0;
}