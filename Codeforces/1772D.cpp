#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {

    int n;
    cin >> n;
    vi a(n);
    for(auto& x : a)cin >> x;

    int l = 0,up = 1e9;
    for(int i=0; i<n-1; i++){
        if(a[i] < a[i+1]){
            up = min(up,(a[i]+a[i+1])/2);
        }
        else if(a[i] > a[i+1]){
            l = max(l, (a[i]+a[i+1]+1)/2);
        }
    }

    l <= up ? cout << l : cout << -1;
    cout << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
