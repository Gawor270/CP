#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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



void solve() {
    int n;
    cin >> n;
    vector<int> b(n*(n-1)/2);
    for(auto&x : b) cin >> x;

    sort(all(b));

    vector<int> a;
    int k = n-1;
    int beg = 0;
    int e = 0;
    while(e <= n*(n-1)/2){
        if(e == n*(n-1)/2 || b[beg] != b[e]){
            int len = (e - beg);
            while(len){
                a.push_back(b[e-1]);
                len -= k;
                k--;
            }
            beg = e;
        }
        e++;
    }
    a.push_back(a[a.size()-1]);
    
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    






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