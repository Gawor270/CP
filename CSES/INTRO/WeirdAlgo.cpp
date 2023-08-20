#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    while(true){
        cout << n << " ";
        if(n == 1)break;
        if(n&1){
            n *= 3;
            n++;
        }
        else{
            n >>= 1;
        }
    }
    cout << "\n";

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