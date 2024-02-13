#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <algorithm>

//https://cses.fi/problemset/task/1145
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update>

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define pi pair<int,int>
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin >> x[i];
    ordered_set oset;
    
    int mx = 1;
    for(int i=0; i<n; i++){
        int pos = oset.order_of_key({x[i],0});
        int val = 1;
        if(pos){
            val = oset.find_by_order(pos-1)->second + 1;
            mx = max(mx, val);
        }
        if(oset.size()){
            if(oset.find_by_order(pos)->second <= val){
                oset.erase(oset.find_by_order(pos));
            }
        }
        oset.insert({x[i],val});
    }
    cout << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}