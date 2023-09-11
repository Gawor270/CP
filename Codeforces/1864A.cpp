[H[J[3J
#include <iostream>

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
    int x,y,n;
    cin >> x >> y >> n;
    vector<int> a;
    a.push_back(y);
    int diff = 1;
    while(--n){
        a.push_back(y - diff);
        y = y  - diff;
        diff++;
    }
    reverse(a.begin(),a.end());
    if(a[0] < x){
        cout << -1 << "\n";
    } else{
        a[0] = x;
        for(int num : a){
            cout << num << " ";
        }
        cout << "\n";
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
