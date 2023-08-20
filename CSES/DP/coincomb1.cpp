#include <iostream>
#include <vector>
//https://cses.fi/problemset/task/1635
using namespace std;


const long long MOD = 1e9 + 7;


int disways(vector<int>& coins,int x,int n){
    vector<int> dp(x+1,0);
    dp[0] =1;

    for(int i=0; i<x; i++){
        if(dp[i] == 0)continue;
        for(auto coin : coins){
            if(i+coin <=x){
                dp[i+coin] = (dp[i+coin] +dp[i])%MOD;
            }
        }
    }

    return dp[x];
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];   
    }

    cout << disways(c,x,n);
    return 0;
}