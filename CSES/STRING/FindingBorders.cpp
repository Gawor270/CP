#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1732
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<int> z(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
        x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> zar = z(s);
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(i + zar[i] == n)ans.push_back(zar[i]);
    }
    for(int x : ans)cout << x << " ";
    cout << "\n";
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
