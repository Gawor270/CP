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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n&1){
        cout << -1 << "\n";
        return;
    }
    vector<int> count(26,0);
    for(int i=0; i<n; i++){
        count[s[i] - 'a']++;
    }

    for(int i=0; i<26; i++){
        if(count[i] > n/2){
            cout << -1 << "\n";
            return;
        }
    }

    int ans = 0;
    fill(all(count),0);
    for(int i=0; i<n/2; i++){
        if(s[i] == s[n-i-1]){
                ans++;
                count[s[i] - 'a']++;
        }
    }
    ans = ans&1 ? ans/2 +1 : ans/2;
    cout << max(*max_element(all(count)), ans) << "\n";
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
