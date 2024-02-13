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

const int MAX_N = 5e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
int ka[MAX_N];
int kb[MAX_N];

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for(auto&x : a)cin >> x;
    for(auto&x : b)cin >> x;
    for(int i=0; i<=k; i++)ka[i] = kb[i] = 0;
    for(int i=0; i<n; i++){
        if(a[i] <= k)ka[a[i]]++;
    }
    for(int i=0; i<m; i++){
        if(b[i] <= k)kb[b[i]]++;
    }
    int ua=0;
    int ub = 0;
    for(int i=1; i<=k; i++){
        if(ka[i] + kb[i]){
            if(ka[i] == 0)ub++;
            if(kb[i]==0)ua++;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << (ua<= k/2 && ub <=k/2 ? "YES\n" : "NO\n");

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
