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
    vi a(n);
    for(auto&x : a)cin >> x;
    sort(all(a));

    int lb = -1; int ub = 1e9;
    while(ub - lb > 1){
        int md = (lb+ub) >> 1;
        int i=0;
        while(i+1 < n && a[i+1] - a[0] <= 2*md)i++;
        int j = n-1;
        while(j-1 > -1 && a[n-1] - a[j-1] <= 2*md)j--;

        ++i; --j;
        if(i > j || a[j] - a[i] <= 2*md){
            ub = md;
        }
        else{
            lb = md;
        }
    }

    cout << ub << "\n";
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
