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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    for(auto&x : a)cin >> x;
    for(auto&x : b)cin >> x;
    int poss = 0;
    for(int i=0; i<m; i++)poss |= b[i];
    int ans = 0;
    for(int i=0; i<n; i++)ans ^= a[i];
    int maxim = ans;
    int minim = ans;
    for(int i=0; i<32; i++){
        if(n&1  && !(maxim & (1 << i)) && (poss & (1 << i)))maxim += (1 << i);
        if(!(n&1) && (maxim & (1 << i)) && (poss & (1 << i)))minim -= (1 << i);
    }
    cout << minim << ' ' << maxim << "\n";
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
