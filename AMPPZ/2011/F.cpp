#include <bits/stdc++.h>

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
    int n,k;
    cin >> n >> k;
    vi d(n);
    for(auto&x : d)cin >> x;
    multiset<int> l;
    for(int i=0; i<k; i++){
        int inp;
        cin >> inp;
        l.insert(inp);
    }
    sort(d.rbegin(), d.rend());

    int ans = 0;
    for(int i=0; i<n; i++){
        auto ptr = l.lower_bound(5*d[i]);
        if( ptr == l.end() ){
            ptr = l.lower_bound(3*d[i]);
            if(ptr == l.end()){
                cout << "NIE" << "\n";
                return;
            }
            l.erase(ptr);
            ptr = l.lower_bound(2*d[i]);
            if(ptr == l.end()){
                cout << "NIE" << "\n";
                return;
            }
            l.erase(ptr);
            ans++;
        }
        else{
            l.erase(ptr);
        }
        ans++;
    }
    cout << ans << '\n';
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
