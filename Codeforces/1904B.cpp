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
    vector<pair<ll,int>> a(n);
    vi res(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<ll> prefsum(n);
    prefsum[0] = a[0].first;
    for(int i=1; i<n; i++){
        prefsum[i] = prefsum[i-1] + a[i].first;
    }
    for(int i=n-2; i>=0; i--){
        if(a[i].first == a[i+1].first || prefsum[i] >= a[i+1].first)prefsum[i] = prefsum[i+1];
    }

    int maxel = n-1;
    res[a[n-1].second] = n-1;
    for(int i=n-2; i>=0; i--){
        while(prefsum[i] < a[maxel].first)maxel--;
        res[a[i].second] = maxel;
    }
    for(int x : res){
        cout << x << " ";
    }
    cout << "\n";
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
