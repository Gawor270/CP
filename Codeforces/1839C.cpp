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
    int n;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    reverse(all(a));
    vector<int> res;    
    int count= 0;
    if(a[0] == 1){
        cout << "NO" << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            if(count == 0)res.push_back(0);
        }
        else{
            if(i+1 == n || a[i+1] == 0){
                res.push_back(++count);
                count = 0;
            }
            else{
                res.push_back(0);
                count++;
            }
        }
    }
    cout << "YES" << "\n";
    for(int x : res)cout << x << " ";
    cout << '\n';
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
