#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


vector<ll> p;
ll findmin(int i =0, ll sum1 =0, ll sum2 = 0){
    if(i == SIZE(p)){
        return abs(sum1 - sum2);
    }

    return min(findmin(i+1, sum1 + p[i],sum2),findmin(i+1,sum1,sum2 + p[i]));
}

void solve() {
    int n;
    cin >> n;
    p.resize(n);
    for(auto& x : p)cin >> x;
    cout << findmin() << "\n";
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
