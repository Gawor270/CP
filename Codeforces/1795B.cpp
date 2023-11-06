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
    k--;
    vector<pi> seg(n);
    for(int i=0; i<n; i++){
        cin >> seg[i].first;
        cin >> seg[i].second;
        seg[i].first--;
        seg[i].second--;
    }
    vector<int> prefderi(51,0);
    for(int i=0; i<n; i++){
        if(seg[i].first <= k && k <= seg[i].second){
            prefderi[seg[i].first]++;
            prefderi[seg[i].second+1]--;
        }
    }
    for(int i=1; i<=50;i++)prefderi[i] += prefderi[i-1];

    bool ok = true;
    for(int i=0; i<50; i++){
        if(i != k && prefderi[i] >= prefderi[k])ok = false;
    }
    cout << (ok ? "YES" : "NO") << "\n";
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
