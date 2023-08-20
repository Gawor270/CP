#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
       cout << (i*i)*(i*i-1)/2 - 4*(i-1)*(i-2) << "\n"; 
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