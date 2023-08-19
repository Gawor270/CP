#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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
    vector<int> used(n+1,0);
    vector<int> res = {1};
    for(int x=2; x <=n; x++){
        if(used[x])continue;
        int u = x;
        while(u <=n){
            res.push_back(u);
            used[u] = 1;
            u*= 2;
        }
    }
    
    for(int x : res){
        cout << x << " ";
    }
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
