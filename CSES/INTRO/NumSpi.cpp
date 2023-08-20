#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    ll x,y;
    cin >> y >> x;
    ll mx = max(x,y);
    ll ans;
    if(y <= x){
        if(mx&1){
            ans = mx*mx - (y-1);
        }
        else{
            ans = (mx-1)*(mx-1) + y;
        }

    }
    else{
        if(mx&1){
            ans = (mx-1)*(mx-1) + x; 
        }
        else{
            ans = mx*mx - (x-1);
        }
    }
    printf("%lld\n",ans);

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}