#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return;
    }

    if(n <= 3){
        cout << "NO SOLUTION" << "\n";
        return;
    }

    for(int i=2; i<=n; i+=2){
        cout << i << " ";
    }
    for(int i=1; i<=n; i+=2){
        cout << i << " ";
    }

    cout << "\n";

}

int main(){
    int t;
    t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}