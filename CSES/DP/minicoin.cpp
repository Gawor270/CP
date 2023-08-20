#include <iostream>
#include <vector>
//https://cses.fi/problemset/task/1634
using namespace std;


int sumofmoney(vector<int>& coins,int n, int x){
    vector<int> dp(x+1,INT32_MAX);

    dp[0] = 0;

    for(int i=0; i<=x; i++){
        if(dp[i] == INT32_MAX) continue;
        for(auto coin : coins){
            if(i+coin <=x) dp[i + coin] = min(dp[i+coin],dp[i] +1);
        }
    }
    if(dp[x] == INT32_MAX) return -1;
    return dp[x];
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    cout << sumofmoney(c,n,x);
    return 0;
}