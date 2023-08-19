#include <iostream>
#include <vector>
#include <set>
//https://codeforces.com/contest/1848/problem/C
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

int gcd(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) {
            return gcd(b, r) + k + k / 2;
        } else {
            return gcd(r, b) + k + k / 2;
        }
    }
    return 1 + gcd(b, abs(a - b));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    vector<int> cnt(n);
    int n1 = 4;
    int n2 = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 0 && b[i] == 0){
            cnt[i] = 4;
        }
        else{
            cnt[i] = gcd(a[i],b[i])%3;
            n2 = cnt[i];
        }
    }

    int counter =0;
    for(int i=0; i<n; i++){
        if(cnt[i] == n1 || cnt[i] == n2)counter++;
    }
    if(counter == a.size()){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}