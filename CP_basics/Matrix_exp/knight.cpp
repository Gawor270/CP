#include <iostream>
#include <vector>
#include <set>
#include <cassert>
//https://codeforces.com/gym/102644/problem/E
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
const ll MOD = 1LL<<32;
const ll INF = 1e9;
const ld EPS = 1e-9;


struct Mat{
    int n,m;
    vector<vector<int>> a;
    Mat() {}
    Mat(int _n, int _m) {n = _n; m = _m; a.assign(n,vector<int>(m,0)); }
    Mat(vector<vector<int>>v) {n = v.size(); m =n? v[0].size() : 0; a=v;}
    inline void make_unit(){
        assert(n==m);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)a[i][j] = i==j;
        }
    }
    inline Mat operator + (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n,m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans.a[i][j] = (a[i][j] + b.a[i][j])%MOD;
            }
        }
        return ans;
    }
    inline Mat operator - (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n,m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans.a[i][j] = (a[i][j] - b.a[i][j] +MOD)%MOD;
            }
        }
        return ans;
    }
    inline Mat operator * (const Mat &b){
        assert(m==b.n);
        Mat ans = Mat(n,b.m);
        for(int i=0; i<n; i++){
            for(int j=0; j<b.m; j++){
                for(int k=0; k<m; k++){
                    ans.a[i][j] = (ans.a[i][j] + 1LL*a[i][k]*b.a[k][j]%MOD )%MOD;
                }
            }
        }
        return ans;
    }
    inline Mat pow(ll k){
        assert(n==m);
        Mat ans(n,n), t=a; ans.make_unit();
        while(k){
            if(k&1)ans = ans*t;
            t = t*t;
            k >>=1;
        }
        return ans;
    }
    inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
    inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
    inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
    inline bool operator == (const Mat& b) { return a == b.a; }
    inline bool operator != (const Mat& b) { return a != b.a; }
};


void solve(){
    ll k;
    cin >> k;
    pair<int,int> moves[9] = {{0,0},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1}};
    Mat pos(8,8);
    Mat board(8,8);
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            for(pair<int,int> move: moves){
                if(i +move.first >=0 && i+move.first<8 && j+move.second >=0 && j+move.second <8){
                    pos.a[i][j]++;
                }
            }
        }
    }
    board.a[0][0]=1;
    board.a[1][2] = 1;
    board.a[2][1] = 1;
    if(k==1){
        
    }
    board = board*pos;
    board = board.pow(k-2);
    ll ans = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            ans += board.a[i][j];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}