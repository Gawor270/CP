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
    vector<pi> td(n);
    for(int i=0; i<n; i++){
        cin >> td[i].second >> td[i].first;
    }
    sort(all(td));

    int ans = td[0].first - td[0].second;
    int free = 0;
    for(int i=1; i<n; i++){
        int diff = td[i-1].first - (td[i].first - td[i].second);
        if(diff >0){
            if(diff > free){
                ans -= (diff-free);
                free = 0;
            }
            else{
                free -= diff;
            }
        }
        else{
            free -= diff;
        }
    }

    cout << ans << "\n";
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
