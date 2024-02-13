#include <iostream>
#include <vector>
#include <set>
//https://cses.fi/problemset/task/2413
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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll dp[MAX_N][8];

void process() {
    //number of 2x2 bricks beginning with vertical line = 3 = ending with vertical line 
    //number of 2x2 bricks beginning with horizontal line = 5 = ending with horizontal line

    for(int i=0; i<8; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<=1e6; i++){
        for(int j=0; j<8; j++){
            if(j==0 || j==3 || j==4 || j==5 || j==7){
                dp[i][j] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5] + dp[i-1][7])%MOD;
            }
            else{
                dp[i][j] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][6])%MOD;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    process();
    int n;
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        // cout << "Case #" << t << ": ";
        cout << (dp[n-1][1] + dp[n-1][7])%MOD<< "\n";
    }
}