#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1731
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 2e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll trie[MAX_N][26];
ll dp[5005];
int stop[MAX_N];
ll num = 0;

void insert(string s){
    int u = 0;
    for(char c : s) {
        if(!trie[u][c - 'a'])trie[u][c - 'a'] = ++num;
        u = trie[u][c - 'a'];
    }
    stop[u] = 1;
}

ll search(string s,int x,int n) { 
    int u = 0;
    ll ans = 0;
    for (int i=x; i<n; i++) {
        if (!trie[u][s[i] - 'a']) return ans;
        u = trie[u][s[i] - 'a'];
        if(stop[u])ans = (ans + dp[i+1])%MOD;
    }
    return ans;
}

void solve() {
    int k;
    string s;
    cin >> s;
    cin >> k;
    while(k--){
        string inp;
        cin >> inp;
        insert(inp);
    }
    dp[s.size()] = 1;
    int n = s.length();
    for(int i=n-1; i>=0; i--){
        dp[i] = search(s,i,n);
    }
    cout << dp[0] << "\n";

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
