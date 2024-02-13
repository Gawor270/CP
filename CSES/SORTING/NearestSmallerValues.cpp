#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
    vector<pi> x(n);
    vi res(n,0);
    for(int i=0; i<n; i++){
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(all(x));

    ordered_set o_set;
    stack<int> st;
    for(int i=0; i<n; i++){
        if(i && x[i].first != x[i-1].first){
            while(st.size()){
                o_set.insert(st.top());
                st.pop();
            }
        }
        int pos = o_set.order_of_key(x[i].second);
        if(pos) res[x[i].second] = *(o_set.find_by_order(pos-1))+1;
        if(i && x[i].first != x[i-1].first){
            o_set.insert(x[i].second);
        }
        else{
            st.push(x[i].second);
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
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
