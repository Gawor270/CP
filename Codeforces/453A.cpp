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

double qexp(double a, int exp){
    double res = 1;
    while(exp){
        if(exp&1)res *= a;
        a *= a;
        exp >>= 1;
    }
    return res;
}

void solve() {
    double m,n;
    cin >> m >> n;
    double ans = 0;
    for(int i=1; i<=m; i++){
        double p = qexp(i/m,(int)n) - qexp((i-1)/m,(int)n);
        ans += (double)i*p;
    }
    printf("%.12f\n" , ans);
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
