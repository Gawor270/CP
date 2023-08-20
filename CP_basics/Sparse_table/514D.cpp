#include <bits/stdc++.h>
#include <iostream>
//https://codeforces.com/problemset/problem/514/D
using namespace std;

const int MAXN = 1e5 + 5;
const int K = 17;
const int MAXM = 5;
int st[MAXM][K+1][MAXN];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void preprocess(int N){
    int K = log2_floor(N);
    // initialize sprarse table for every type of detail
    for(int m =0; m<MAXM; m++){
        for(int i=1; i<=K; i++){
            for(int j=0; j + (1 << i) <=MAXN; j++){
                st[m][i][j] = max(st[m][i-1][j], st[m][i-1][j + (1<<(i-1))]);
            }
        } 
    }
}

int query(int L, int R,int level){
    int length = R-L +1;
    int k = log2_floor(length);
    return max(st[level][k][L],st[level][k][R - (1 << k) + 1]);
}

bool check(int b, int e, int k, int m,vector<int> &res){
    long long sum = 0;
    vector<int> tmp(m);
    for(int i=0; i<m; i++){
        tmp[i] = query(b,e,i);
        sum += (long long )tmp[i];
    }
    if(sum <= k){
        for(int i=0; i<m; i++)res[i] = tmp[i];
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> st[j][0][i];
        }
    }
    preprocess(n);
    int maxi = 0, maxj = 0;
    int i =0, j=0;
    vector<int> ans(m);
    while(j < n){
        vector<int> tmp(m);
        if(check(i,j,k,m,tmp)){
            j++;
            if((j -i + 1) > (maxj - maxi + 1)){
                maxj = j;
                maxi = i;
                for(int i=0; i<m; i++)ans[i] = tmp[i];
            }
        }
        else{
            i++;
            j = max(i,j);
        }
    }

    for(int mx : ans)cout << mx << " ";
    cout << "\n";


    return 0;
}

