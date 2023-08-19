#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stack>

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
//https://codeforces.com/problemset/problem/1833/B


void solve(vector<int> &a, vector<int> &b,int size) {
    map<int,stack<int>> positions;
    vector<int>::iterator iter;
    vector<int> result(size,INT32_MAX);
    for(int i=0 ;i<size; i++){
        positions[a[i]].push(i);
    }

    sort(all(a));
    sort(all(b));
    for(int i=0; i<size; i++){
        result[positions[a[i]].top()] = b[i];
        positions[a[i]].pop();
    }
    iter = result.begin();
    for(iter; iter < result.end(); iter++){
        cout << *iter << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n,k;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        // cout << "Case #" << t << ": ";
        solve(a,b,n);
    }
}