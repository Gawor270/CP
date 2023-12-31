#include <iostream>
#include <vector>
#include <set>
//https://codeforces.com/problemset/problem/1796/C
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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int l,r;
    cin >> l >> r;

    int maxsz = 0;
    int maxval = l;
    while(maxval <= r){
        maxval = maxval << 1;
        maxsz++;
    }
    maxval >>= 1;
    int seg = maxval/l;
    int amount1 = r/seg - l +1;
    int amount2 = 0;
    if(seg/2)amount2 = r/((seg/2)*3) - l +1;

    cout << maxsz << " " << amount1 + (max(0,amount2))*(maxsz-1) << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
