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
    int n,x;
    cin >> n>> x;
    vector<ll> a(n), prefsum(n+1,0);
    for(auto&x : a)cin >> x;
    for(int i=0; i<=n; i++){
        prefsum[i] = (prefsum[i-1] + a[i-1]);
    }
    map<ll,ll> mp;
    ll count  = 0;
    for(int i=0; i<=n; i++){
        count += mp[x-prefsum[i]];
        mp[-prefsum[i]]++;
    }

    cout << count << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
