#include <bits/stdc++.h>
// https://projecteuler.net/problem=214
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 4e7;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool notPrime[MAX_N];
vector<ll> primes;

void sieve(){
    notPrime[1] = true;
    for(int i=2; i<MAX_N; i++){
        if(notPrime[i])continue;
        primes.push_back(i);
        for(int j = 2*i; j<MAX_N; j += i){
            notPrime[j] = true;
        }
    }
}

ll phi(ll n){
    if(n == 1)return 0;
    ll res = n;
    for(ll i=0; primes[i]*primes[i] <= n; i++){
        if(n%primes[i]== 0){
            res -= (res/primes[i]);

            while(n%primes[i] ==0)n/=primes[i];
        }
    }
    if(n > 1)res -= (res/n);

    return res;
}

void solve() {
    sieve();
    ll sum = 0;
    int length = 25;
    for(ll p : primes){
        int count = 0;
        ll inp = p;
        while(inp){
            if(count > length)break;
            inp = phi(inp);
            count++;
        }
        if(count == length)sum += p;
    }
    cout << sum << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
