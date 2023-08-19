#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>

using namespace std;

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
    ll b;
    cin >> b;
    ll res = 1;
    ll limit = static_cast<int>(sqrt(b));
    for(int i =2; i <= limit; i++){
        if(b%i == 0){
            int exponent = 0;
            while(b%i == 0){
                ++exponent;
                b/=i;
            }
            res *= (exponent+1);
            limit = static_cast<int>(sqrt(b));

        }
    }
    if(b > 1)res *= 2;

    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
