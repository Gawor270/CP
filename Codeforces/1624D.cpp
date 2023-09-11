#include <bits/stdc++.h>

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



void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> occ(26,0);
    for(int i=0; i<n; i++)occ[s[i] - 'a']++;
    int no_pairs = 0;
    int remain = 0;
    for(int x : occ){
        remain += (x&1);
        no_pairs += x/2;
    }
    int used = 2*(no_pairs/k);
    int notused = no_pairs - (used/2)*k;
    remain + 2*notused >=k ? cout << used +1 << "\n" : cout << used << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
