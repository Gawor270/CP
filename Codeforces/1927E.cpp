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

void solve() {
    int n,k;
    cin >> n>> k;
    vi a(n);
    deque<int> dq;
    for(int i=0; i<n;i++)dq.push_back(i+1);
    for(int i=0; i<k; i++){
        if(i&1){
            for(int j=i; j<n; j+=k){
                a[j] = dq.front();
                dq.pop_front();
            }
        }
        else{
            for(int j=i; j<n; j+=k){
                a[j] = dq.back();
                dq.pop_back();
            }
        }
    }
    for(int x : a)cout << x << " ";
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
