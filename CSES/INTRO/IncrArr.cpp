#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    int n;
    cin >> n;

    vector<int> x(n);
    for(auto&a : x)cin >> a;

    ll moves = 0;
    for(int i=1; i<n; i++){
        int diff = x[i-1]-x[i];
        if(diff > 0){
            moves += (ll)diff;
            x[i] = x[i-1];
        }
    }

    cout << moves << "\n";
}

int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}