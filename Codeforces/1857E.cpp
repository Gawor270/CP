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
    vector<pair<ll,int>> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.begin(), x.end());

    vector<ll> res(n);
    ll sum =0;
    for(pair<int,int> a : x){
        sum += (ll)abs(x[0].first-a.first)+1;
    }
    res[x[0].second] = sum;
    for(ll i=1; i<n; i++){
        sum -= (n-i)*(x[i].first-x[i-1].first);
        sum += i*(x[i].first-x[i-1].first);
        res[x[i].second] = sum;
    }
    
    for(ll a : res)cout << a << " ";
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