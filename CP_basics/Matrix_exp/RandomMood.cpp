#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
//https://codeforces.com/gym/102644/problem/A
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


struct Mat{
    int n,m;
    vector<vector<double>> a;
    Mat() {}
    Mat(int _n, int _m) {n = _n; m = _m; a.assign(n,vector<double>(m,0)); }
    Mat(vector<vector<double>>v) {n = v.size(); m =n? v[0].size() : 0; a=v;}
    inline void make_unit(){
        assert(n==m);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)a[i][j] = (double)(i==j);
        }
    }
    inline Mat operator + (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n,m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans.a[i][j] = (a[i][j] + b.a[i][j]);
            }
        }
        return ans;
    }
    inline Mat operator - (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n,m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans.a[i][j] = a[i][j] - b.a[i][j]; 
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
                    ans.a[i][j] = (ans.a[i][j] + a[i][k]*b.a[k][j]);
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


void solve() {
    int n;
    cin >> n;
    double p;
    cin >> p;
    Mat limak(2,2);
    limak.a[0][0] = 1-p;
    limak.a[0][1] = p;
    limak.a[1][0] = p;
    limak.a[1][1] = 1-p;
    limak = limak.pow(n);
    cout << setprecision(10) << limak.a[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // int n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}