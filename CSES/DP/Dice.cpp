#include <iostream>
#include <vector>
using namespace std;
//https://cses.fi/problemset/task/1633/
typedef long long ll;
const ll MOD = 1e9 +7;

int dicecomb(int n,vector<ll>& dp){
    if(n==0){
        return 1;
    }
    if(n<0) return 0;
    if(dp[n] > 0) return dp[n];

    ll ans = 0;
    for(int i=1; i<=6; i++){
        ans = (ans+ dicecomb(n-i,dp))%MOD;
    }
    dp[n] = ans%MOD;
    return ans;
}

int bottomupdice(int n){
    vector<int> dp(n+1);

    dp[0] = 1;

    for(int i=0;i<n; i++){
        for(int j=1; j<=6; j++){
            if(i+j <=n) dp[i+j] = (dp[i+j] +dp[i])%MOD; 
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n+1,-1);
    cout << bottomupdice(n);
    return 0;
}