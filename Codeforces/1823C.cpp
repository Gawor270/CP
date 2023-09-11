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

const int MAX_N = 1e7 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n;
    cin >> n;
    vi a(n);
    int ans= 0;
    int remain = 0;
    for(auto&x : a)cin >> x;
    map<int,int> primes;
    for(int i=0; i<n; i++){
        for(int div = 2; div*div <= a[i]; div++){
            while(a[i] % div == 0){
                a[i] /= div;
                primes[div]++;
            }
        }
        if(a[i] > 1)primes[a[i]]++;
    }

    for(pair<int,int> p : primes){
        if(p.second&1)remain++;
        ans += p.second/2;
    }
    cout << ans + remain/3 << "\n";
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
