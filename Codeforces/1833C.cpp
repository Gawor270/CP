#include <iostream>
#include <vector>
#include <set>

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

//https://codeforces.com/problemset/problem/1833/C

void solve(vector<int> &a,int size) {
    int maxodd = 0;
    int maxeven =0;
    int mineven =INT32_MAX;
    int minodd = INT32_MAX;
    for(int i=0; i<size; i++){
        if(a[i]&1){
            if(a[i] > maxodd) maxodd=a[i];
            if(a[i] < minodd) minodd =a[i];
        }
        else{
            if(a[i] < mineven) mineven=a[i];
            if(a[i] > maxeven) maxeven = a[i];
        }
    }
    if(maxodd == 0 || maxeven == 0 || minodd < mineven) cout << "YES" << "\n";
    else if(minodd > mineven) cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        // cout << "Case #" << t << ": ";
        solve(a,n);
    }
}