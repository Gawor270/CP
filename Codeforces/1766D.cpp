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

vi primes;
void sieve(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pi> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].second - a[i].first == 1){
            cout << -1 << "\n";
        }
        else if(__gcd(a[i].first,a[i].second) != 1){
            cout << 0 << "\n";
        }
        else{
            int diff = a[i].second - a[i].first;
            int res = 1e9;
            for(int j : primes){
                if(j*j > diff) break;
                if(diff%j == 0){
                    res = min(res,j - (a[i].first%j));
                    while(diff%j == 0){
                        diff /= j;
                    }
                }
            }
            if(diff > 1){
                res = min(res, diff- (a[i].first%diff));
            }
            cout << res << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    sieve(1e5);
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
