#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define all(a) (a).begin(), (a).end()

typedef long long ll;

void solve(){
    long long  n;
    cin >> n;

    if((n*(n+1)/2)&1){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    long long s = n*(n+1)/2;
    vector<int> s1,s2;

    long long  mid = s/2;
    for(long long  i=n; i>0; i--){
        if(i <= mid){
            s1.push_back(i);
            mid -= i;
        }
        else{
            s2.push_back(i);
        }

    }

    cout << s1.size() << "\n";
    for(int num : s1)cout << num << " ";
    cout << "\n" << s2.size() << "\n";
    for(int num : s2)cout << num << " ";
    cout << "\n";



}
int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}