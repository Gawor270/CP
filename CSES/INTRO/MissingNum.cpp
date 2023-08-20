#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(x) x.begin(),x.end()

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<bool> occ(n,false);
    for(int i=0; i<n-1; i++){
        int inp;
        cin >> inp;
        occ[inp-1] = true;
    }

    for(int i=0; i<n; i++){
        if(!occ[i]){
            cout << i+1 << "\n";
            return;
        }
    }
}

int main(){
    int t;
    t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}