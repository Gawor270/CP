#include <iostream>
#include <vector>
#include <set>
//https://codeforces.com/problemset/problem/1845/C
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

bool issubstr(vector<vector<int>> &state, vector<int> &passwd,int m){
    int ind = 0;
    for(int i=0; i<m; i++){
        if(state[ind][passwd[i]] == -1) return false;
        ind = state[ind][passwd[i]];
    }

    return true;

}

bool check(string l, string r, int m,vector<vector<int>> state,int n){
    int ind = 0;
    // greedy method
    for(int j=0; j<m; j++){
        int maxim = 0;
        // always choose farthest index from possible nums in bounds l[i] <= x <= r[i] using state array
        for(int i = (int)l[j] - 48; i<=(int)r[j] - 48; i++){
            if(state[ind][i] == -1)return true;
            maxim  = max(maxim,state[ind][i]);
        }
        ind = maxim+1;
    }

    return false;
}


void solve() {
    int m,n;
    string s,l,r;
    cin >> s;

    n = s.length();
    vector state(n+1,vector<int>(10,-1));

    //dynamically fill state 2d array where state[i][j] contains closest index to the right from index i to variable of value = j
    for(int i = n-1; i >=0; i--){
        for(int j=0; j<10; j++){
            state[i][j] = state[i+1][j];
        }
        state[i][(int)s[i]-48] = i;
    }

    cin >> m;
    cin >> l >> r;

    if(check(l,r,m,state,n)){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }



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