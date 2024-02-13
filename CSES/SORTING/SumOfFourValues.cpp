#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>


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

bool check(vector<pair<ll,int>> &a, ll val, int sec, int i, int j){
    auto el = lower_bound(all(a), make_pair(val, sec)); // Modify the argument list
    if(el != a.end() && el->first == val && a[i].second != el->second && a[j].second != el->second){ // Check if the element is found
        cout << a[i].second+1 << ' ' << a[j].second+1 << ' ' << el->second+1 << '\n'; // Print the result
        return true;
    }
    return false;
}

void solve() {
    int n,x;
    cin >> n >> x;
    vector<pair<ll,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    for(int i=0; i<n; i++){
        for(int j=i+1; j <n; j++){
            ll val = x - a[i].first - a[j].first;
            int l = n-1;
            for(int k = j+1; k<l; k++){
                while( k<l && a[k].first + a[l].first > val)l--;
                if(k==l)break;
                if(a[k].first + a[l].first == val){
                    a[i].second++, a[j].second++, a[k].second++, a[l].second++;
                    printf("%d %d %d %d\n",a[i].second, a[j].second, a[k].second, a[l].second );
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
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
