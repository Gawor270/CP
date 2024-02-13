#include <iostream>
#include <vector>
#include <set>
//https://cses.fi/problemset/task/1746
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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAX_M = 100;

ll dp[MAX_N][MAX_M];

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){cin >> a[i]; --a[i];}

    for(int i=0; i<n; i++){
        if(i){
            for(int j=0; j<m; j++){
                dp[i][j] = dp[i-1][j];
                if(j){
                    dp[i][j] += dp[i-1][j-1];
                }
                if(j<m-1){
                    dp[i][j] += dp[i-1][j+1];
                }
                dp[i][j] %=MOD;
            }
        }
        else{
            for(int j=0; j<m; j++){
                dp[i][j] = 1;
            }
        }
        if(~a[i]){
            for(int j=0; j<m; j++){
                if(j^a[i])
                    dp[i][j] =0;
            }
        }
    }

    ll sum = 0;
    for(int i=0;i<m; i++){
        sum += dp[n-1][i];
    }

    cout << sum%MOD;

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