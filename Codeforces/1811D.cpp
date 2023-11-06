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

ll fib[46];

void prepro(){
    fib[0] = fib[1] = 1;
    for(int i=2; i<46; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}


bool solve(int n, int x, int y) {
    if(n == 0)return true;
    if(y <= (fib[n+1] - fib[n]) || y > fib[n]){
        return solve(n-1,(y >= fib[n+1]-fib[n] ? y-fib[n] : y),x);
    }
    return false;
}

int main() {
    int tc = 1;
    prepro();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n,x,y;
        cin >> n >> x >> y;
        cout << (solve(n,x,y) ? "YES" : "NO") << "\n";
    }
}
