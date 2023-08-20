#include <iostream>
#include <vector>
#include <set>
//https://cses.fi/problemset/task/1097
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

const int MAX_N = 5e3 +7; 
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


pair<ll,ll> dp[MAX_N][MAX_N];

void solve() {
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> dp[i][i].first;
        dp[i][i].second = 0;
    }

    for(int i=n-1; ~i; --i){
        for(int j=i+1; j<n; ++j){
            if(i^j){
                if(dp[i][i].first + dp[i+1][j].second >= dp[j][j].first + dp[i][j-1].second){
                    dp[i][j] = {dp[i][i].first + dp[i+1][j].second, dp[i+1][j].first};
                }
                else{
                    dp[i][j] = {dp[j][j].first + dp[i][j-1].second, dp[i][j-1].first};
                }
            }
        }
    }

    cout << dp[0][n-1].first << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}