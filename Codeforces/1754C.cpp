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
    for(auto& x: a)cin >> x;

    int sum = 0;
    for(int x : a)sum += x;

    if(sum&1){
        cout << -1 << "\n";
        return;
    }

    vector<pair<int,int>> res;
    for(int i=0; i<n; i+=2){
        if(a[i] == a[i+1]){
            res.push_back(make_pair(i+1,i+2));
        }
        else{
            res.push_back(make_pair(i+1,i+1));
            res.push_back(make_pair(i+2,i+2));
        }
    }

    cout << res.size() << "\n";
    for(auto p : res){
        cout << p.first << " " << p.second << "\n";
    }

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
