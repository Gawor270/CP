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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto&x : a)cin >> x;
    map<ll,ll> mp;
    int dist = 0;
    int i = 0;
    ll res = n*(n+1)/2 ;
    for(int j=0; j<n; j++){
        if(mp.find(a[j]) == mp.end() || mp[a[j]] == 0){
            dist++;
        }
        mp[a[j]]++;
        while(i < j && dist > k){
            res -= (n-j);
            mp[a[i]]--;
            if(mp[a[i]] == 0)dist--;
            i++;
        }
    }
    cout << res << "\n";
    
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
