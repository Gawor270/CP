#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
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

int power(int x,int p){
    if(p == 0)return 1;
    else return x*power(x,p-1);
}

void ans(int a, int b){
    cout << a << " + " << b << " = " << a+b << "\n";
}

void solve(){
    int a,b,c;
    ll k;
    int j;
    cin >> a >> b >> c >> k;

    for(int i = power(10,a-1); i<power(10,a); i++){
        int lb = max(power(10,b-1),power(10,c-1)-i);
        int ub = min(power(10,b)-1,power(10,c)-i-1);
        if(lb > ub)continue;

        int jump = ub-lb +1;
        if(jump >= k){
            ans(i,lb + k-1);
            return;
        }
        k-=jump;
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}