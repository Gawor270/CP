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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n), b(n);
    for(int i=0; i<n; i++)cin >> a[i].first, a[i].second  = i;
    for(int i=0; i<n; i++)cin >> b[i].first, b[i].second  = i;
    sort(all(a)), sort(all(b));
    int diff = a[0].second  - b[0].second;
    diff += n;
    diff %= n;
    for(int i=0; i<n;i++){
        if(a[i].first != b[i].first || (a[i].second -b[i].second + n)%n != diff ){
            cout << "NO" << "\n";
            return;
        }
    }

    if(k == 0 && diff){
        cout << "NO" << "\n";
    }
    else if(k == 1 && diff == 0){
        cout << "NO" << "\n";
    }
    else if(n == 2 && ((diff == 0) + k)%2 == 0){
        cout << "NO" << "\n";
    }
    else cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
