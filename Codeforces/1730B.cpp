#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> oxt(n), xt;
    for(auto& a : oxt)cin >> a.first;
    for(auto&a : oxt)cin >> a.second;

    sort(all(oxt));
    oxt.push_back({-1,-1});

    for (int i=0; i<n; i++) {
        if(oxt[i].first != oxt[i+1].first)xt.push_back(oxt[i]);
    }
    n = xt.size();

    int i = 0;
    int time = xt[i].second;
    for (int k =1; k<n; k++){
        int gotby = time + abs(xt[k].first-xt[k-1].first);
        if (gotby <= xt[k].second)i = k;
        time = max(xt[k].second, gotby);
    }

    int j = n-1;
    time = xt[j].second;
    for (int k =n-1; k -1 >= 0; k--) {
        int gotby = time + abs(xt[k].first-xt[k-1].first);
        if (gotby <= xt[k-1].second)j = k-1;
        time = max(xt[k-1].second, gotby);
    }

    double optimal_point = double(((xt[i].first - xt[i].second)*10 + (xt[j].first + xt[j].second)*10)/2)/10.0;
    cout << setprecision(10) << (0.0, optimal_point) << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
