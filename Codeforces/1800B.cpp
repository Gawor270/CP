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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> counts(26,0);
    vector<int> countb(26,0);

    int ans = 0;
    for(int i=0 ; i<n; i++){
        if(s[i] >= 'a'){
            counts[s[i] - 'a']++;
        }
        else{
            countb[s[i] - 'A']++;
        }
    }
    
    for(int i=0; i<26; i++){
        int mn = min(counts[i],countb[i]);
        ans += mn;
        counts[i] -= mn;
        countb[i] -= mn;
        if(k > 0){
            ans += min(k,counts[i]/2);
            k -= min(k,counts[i]/2);
        }
        if(k > 0){
            ans += min(k,countb[i]/2);
            k -= min(k,countb[i]/2);
        }
    }

    cout << ans << "\n";



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
