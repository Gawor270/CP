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
    if(k == 0){
        for(int i=0; i<n; i++){
            cout << -1 << " ";
        }
        cout << "\n";
        return;
    }

    vi a(n);

    int sum = 0;
    bool mode = true;
    for(int i=0; i<n; i++){
        if(mode){
            if(k > (n-i)){
                a[i] = (999-i);
                k -= (n-i);
            } else {
                a[i] = n;
                k--;
                sum += (n-i);
                mode = false;
                continue;
            }
        } else {
            if(k != 0){
                a[i] = -1;
            } else {
                a[i] = -(n+1);
            }
            k--;
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
