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


void solve() {
    int n,a,b;
    cin >> n;
    vector<int> longestn1(2*n+1,0);
    vector<int> longestn2(2*n+1,0);
    vector<int> countn(2*n+1,0);
    int max = 0;
    int maxn = 0;
    cin >> a;
    if(a > maxn) maxn = a;
    countn[a] = 1;
    longestn1[a] = countn[a];
    for(int i=1; i<n; i++){
        cin >> b;
        if(b > maxn)maxn = b;
        if(b==a){
            countn[b]++;
            if(countn[a] > longestn1[a]) longestn1[a] = countn[a];
        }
        else{
            countn[b] = 1;
            if(countn[b] > longestn1[b]) longestn1[b] = countn[b];
        }
        a = b;
   }
   for(int i=0 ; i<2*n+1; i++){
        countn[i] = 0;
   }
   cin >> a;
   if(a > maxn) maxn = a;
   countn[a] = 1;
   longestn2[a] = countn[a];
   for(int i=1; i<n ;i++){
        cin >> b;
        if(b > maxn) maxn = b;
        if(b==a){
            countn[b]++;
            if(countn[a] > longestn2[a]) longestn2[a] = countn[a];
        }
        else{
            countn[b] = 1;
            if(countn[b] > longestn2[b]) longestn2[b] = countn[b];        
        }
        a =b;
   }
   for(int i=1 ;i <maxn+1; i++){
        if(longestn1[i] + longestn2[i]> max) max = longestn1[i] + longestn2[i];
   }

   cout << max  << "\n";

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