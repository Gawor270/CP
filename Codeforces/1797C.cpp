#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

//https://codeforces.com/problemset/problem/1797/C
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

void ask(int* dist,int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",dist);
}

void ans(int x, int y){
    printf("! %d %d\n",x,y);
    fflush(stdout);
}

void solve() {
    int n,m;
    cin >> n >> m;
    int npos,mpos;
    int dist;
    npos = 1, mpos = 1;
    ask(&dist,npos,mpos);
    if(dist == 0){
        ans(npos,mpos);
        return;
    }
    npos = min(n,dist+1);
    mpos = min(m,dist+1);
    ask(&dist,npos,mpos);
    if(dist == 0){
        ans(npos,mpos);
        return;
    }
    if(npos - dist >= 0){
        int tmp;
        ask(&tmp,npos-dist,mpos);
        if(tmp == 0){
            ans(npos-dist,mpos);
            return;
        }
    }
    ans(npos,mpos-dist);

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