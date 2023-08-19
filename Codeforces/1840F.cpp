#include <iostream>
#include <vector>
#include <set>
//https://codeforces.com/contest/1840/problem/F
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e4 + 5;
const int MAX_R = 107;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n,m,r;
    int t,d,coord;

    cin >> n >> m >> r;

    bool free[n+1][m+1][r+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<=r; k++){
                free[i][j][k] = true;
            }
        }
    }

    for(int i=0; i<r; i++){
        cin >> t >> d >> coord;
        if(d==1){
            for(int j=0; j<=m; j++){
                if(0<= t-coord -j && t-coord - j <=r){
                    free[coord][j][t-coord-j] = false; // t-coord -j because coord + j is minimal number of steps you have to make to get to point (coord,j) so t-(coord+j) is possible time after which a laser will hit
                }
            }
        }
        else{
            for(int j=0; j<=n; j++){
                if(0 <= t-coord-j && t-coord -j <=r){
                    free[j][coord][t-coord-j] = false;
                }
            }
        }
    }

    bool dp[n+1][m+1][r+1];
    for(int i=0; i<=n; i++){
        for(int j=0;j<=m; j++){
            for(int k=0; k<=r; k++){
                dp[i][j][k] = !(i || j || k);
                if(free[i][j][k]){
                    if(i && dp[i-1][j][k]){
                        dp[i][j][k] = true;
                    }
                    if(j &&  dp[i][j-1][k]){
                        dp[i][j][k] = true;
                    }
                    if(k && dp[i][j][k-1]){
                        dp[i][j][k] = true;
                    }
                }
            }
        }
    }
    int ans = -1;
    for(int t=r; ~t; --t){
        if(dp[n][m][t]){
            ans = n + m + t;
        }
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}