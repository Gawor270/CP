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
    vector<ll> k(n);
    for(ll&x : k)cin >>x;
    map<ll, int> mp;
    int counter = 0;
    int mx = 0;
    int min = 0;
    for(int i=0; i<n; i++){
        if(mp.find(k[i]) == mp.end()){
            counter++;
            mx = max(mx,counter);
            mp[k[i]] = i;
        }
        else{
            for(int j=min; j <mp[k[i]]; j++){
                mp.erase(mp.find(k[j]));
            }
            min = mp[k[i]]+1;
            counter = (i - mp[k[i]]);
            mp[k[i]] = i;
        }
    }

    cout << max(mx,counter) << "\n";
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
