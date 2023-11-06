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
    vector<ll> a(n), b(n), offs(n+1,0),add(n+1,0);
    for(auto&x : a)cin >> x;
    for(auto&x : b)cin >> x;
    vector<ll> prefsum(n+1);
    prefsum[0] = 0;
    for(int i=1; i<=n; i++){
        prefsum[i] = prefsum[i-1] + b[i-1];
    }

    for(int i=0; i<n; i++){
        vector<ll>::iterator pos = lower_bound(prefsum.begin(),prefsum.end(),a[i] + prefsum[i]);
        int ind = distance(prefsum.begin()+1,pos);
        add[i]++;
        add[ind]--;
        if(ind < n)offs[ind] += min(b[ind],(a[i]+prefsum[i]) - *(pos-1));
    }

    for(int i=1; i<=n; i++){
        add[i] += add[i-1];
    }
    for(int i=0; i<n; i++){
        cout << add[i]*b[i] + offs[i] << " ";
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
