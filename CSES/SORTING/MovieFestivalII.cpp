#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ar<int,2> a[MAX_N];

void solve() {
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i][1] >> a[i][0];
    }
    ordered_set st;
    while(k--)st.insert({0,-k});
    int res=  0;
    sort(a, a +n);
    for(int i=0; i<n; i++){
        int pos = st.order_of_key({a[i][1],0});
        if(pos){
            res++;
            st.erase(st.find_by_order(pos-1));
            st.insert({a[i][0],-i-1});
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
