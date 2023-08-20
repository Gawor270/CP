#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    string dna;
    cin >> dna;

    int ans=0, count=0;
    char l = 'A';
    for(char c : dna){
        if(c == l){
            ans = max(ans,++count);
        }
        else{
            l = c;
            count = 1;
        }
    }

    cout << ans << "\n";
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