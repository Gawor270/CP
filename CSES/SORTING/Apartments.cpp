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
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    for(auto& x : a)cin >> x;
    for(auto& x : b)cin >> x;

    sort(all(a)), sort(all(b));
    int count = 0;
    int i=0,j=0;
    while(i<n && j<m){
        if(b[j] - k <= a[i] && a[i] <= b[j] + k){
            i++;
            j++;
            count++;
        } else {
            if(a[i] -b[j] > k){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
