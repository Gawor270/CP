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
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    vector<pi> r(n);
    for(int i=1; i<=n; i++){
        cin >> r[i-1].first;
        r[i-1].second =  i;
    }
    sort(r.rbegin(), r.rend());

    vi a, b;
    int curr1 = s1;
    int curr2 = s2;
    for(int i=0; i<n; i++){
        if(curr1 < curr2){
           a.push_back(r[i].second);
           curr1 += s1;
        } else {
           b.push_back(r[i].second);
           curr2 += s2;
        }
    }

    cout << a.size() << " ";
    for(int x : a)cout << x << " ";
    cout << "\n" << b.size() << " ";
    for(int x : b)cout << x << " ";
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
