#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1750
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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int t[31][MAX_N];
int n;


void prepro(){
    for(int i=1; i<31 ; i++ ){
        for(int j=1; j<=n; j++){
            t[i][j] = t[i-1][t[i-1][j]];
        }
    }
}


void solve() {
    int q;
    cin >> n >> q;
    for(int i=1; i<=n; i++)cin >> t[0][i];
    prepro();
    while(q--){
        int x,k;
        cin >> x >> k;
        for(int i=0; i<31; i++){
            if(k&(1 << i)){
                x = t[i][x];
            }
        }
        cout << x << "\n";
    }
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
