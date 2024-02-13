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

vector<ll> primes;

void sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i <= n; i++){
        if(is_prime[i]){
            for(int j=i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    for(int i=2; i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x : a)cin >> x;

    unordered_set<ll> mp;
    for(int x : a){
        for(ll i : primes){
            if(i*i > x)break;
            if(x % i == 0){
                if(mp.find(i) != mp.end()){
                    cout << "YES\n";
                    return;
                }
                mp.insert(i);
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x > 1){
            if(mp.find(x) != mp.end()){
                cout << "YES\n";
                return;
            }
            mp.insert(x);
        }
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    sieve(1e5);
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
