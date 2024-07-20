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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n,m;
    cin >> n >> m;
    vector<vi> days(m);
    vi count(n, 0);
    vi res(m);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        days[i].resize(k);
        for(int j=0; j<k; j++){
            int p;
            cin >> p;
            if (j == 0){
                count[p-1]++;
                res[i] = p;
            }
            --p;
            days[i][j] = p;
        }
    }
    int thre = m/2 + m%2;
    int maxim = *max_element(all(count));
    int maxind = 0; 
    for(int i=0; i<n; i++){
        if(count[i] == maxim)maxind = i;
    }
    for(int i=0; i<m && maxim > thre; i++){
        if(days[i][0] == maxind && days[i].size() > 1){
            maxim--;
            res[i] = days[i][1]+1;
        }
    }
    if (maxim <= thre){
        cout << "YES\n";
        for(int x : res)cout << x << " ";
        cout << "\n";
    }
    else{
        cout << "NO\n";
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
