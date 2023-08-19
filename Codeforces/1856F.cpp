#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>

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

long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}

void solve() {
    int n,q,inp;
    ll ai,ay,x,y,D,counter1,counter2;
    cin >> n;
    map<int, long long> cnt;
    cnt.clear();
    for(int i=0; i<n; i++){
        cin >> inp;
        cnt[inp]++;
    }

    cin >> q;
    while(q--){
        cin >> x >> y;
        D = my_sqrt(x*x - 4*y);
        if(D < 0){
            cout << 0 << " ";
            continue;
        }
        ai = (x - D)>>1;
        ay = (x + D)>>1;

        if(ai + ay != x || ai*ay != y){
            cout << 0 << " ";
            continue;
        }
        
        if(D == 0){
                cout << (ll)(cnt[ai]*(cnt[ai]-1)/2) << " ";
        }
        else{
            cout << cnt[ai]*cnt[ay] << " ";
        }
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