#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
  
#define ordered_set tree<ar<long long,3>, null_type,less<ar<long long ,3>>, rb_tree_tag,tree_order_statistics_node_update>

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
#define vi vector<int>
#define vll vector<long long>

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n;
    cin >> n;
    vll dp(n,0LL);
    ordered_set events;
    for(int i=0; i<n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        events.insert({b,a,c});
    }

    dp[0] = (*events.begin())[2];
    ll res=  dp[0];
    int i = 1;
    for(auto it = next(events.begin()); it != events.end(); ++it){
        dp[i] = max((*it)[2], dp[i-1]);
        int pos = events.order_of_key({(*it)[1],0,0});
        if(pos)dp[i] = max(dp[i],dp[pos-1] + (*it)[2]);
        res = max(res, dp[i]);
        i++;
    }
    cout << res << "\n";
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