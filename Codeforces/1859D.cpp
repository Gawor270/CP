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


typedef struct data{
    int l,r,a,b;
}data;

void solve() {
    int n, int q;
    vector<data> portals(n);
    for(int i=0; i<n; i++){
        cin >> portals[i].l >> portals[i].r >> portals[i].a >> portals[i].b;
    }

    cin >> q;
    while(q--){
        int x;
        cin >> x;

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
