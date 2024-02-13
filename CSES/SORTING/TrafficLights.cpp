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
    cin >> x >> n;
    vi p(n);
    for(auto&a : p)cin >> a;

    multiset<int> sizes;
    sizes.insert(x);
    set<int> cuts;
    cuts.insert(0);
    cuts.insert(x);
    for(int cut : p){
        int l = *prev(cuts.lower_bound(cut));
        int u = *(cuts.upper_bound(cut));
        cuts.insert(cut);
        sizes.erase(sizes.find(u-l));
        sizes.insert(cut-l);
        sizes.insert(u-cut);
        cout << *sizes.rbegin() << " ";
    }
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
