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
    int n,m;
    cin >> n >> m;
    multiset<int, greater<int>> tickets;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        auto it = tickets.lower_bound(x);
        if(it == tickets.end()){
            cout << -1 << "\n";
        }else{
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
