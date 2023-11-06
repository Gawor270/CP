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

vi x;
set<int> z;

int countbetween(int b, int e){
    auto ptr1 = lower_bound(all(x), b);
    auto ptr2 = upper_bound(all(x), e);
    return ptr1 < ptr2 ? distance(ptr1, ptr2) : 0;
}

int l;

pi getbe(int val){
    auto ptr = z.find(val);

    auto prevptr = prev(ptr);
    auto nxtptr = next(ptr);
    return {max(*(prevptr) + l + 1, *(ptr) - l), min(*(nxtptr) -l - 1, *(ptr) + l)};
}

void solve() {
    int n,m,d;
    pi be;
    cin >> n >> m >> d >> l;

    x.resize(n+2);
    x[0] = -2e9;
    x[1] = 0;
    for(int i=2; i<=n; i++){
        cin >> x[i];
    }
    x[n+1] = 2e9;

    z.insert((int)-1e9);
    z.insert((int)2e9);

    int ans = 0;
    for(int i=0; i<m; i++){
        int inp;
        cin >> inp;
        z.insert(inp);

        be = getbe(inp);
        ans += countbetween(be.first,be.second);
    }
    cout << ans << "\n";

    while(d--){
        int p,r;
        cin >> p >> r;

        be = getbe(p);
        ans -= countbetween(be.first,be.second);

        z.erase(z.find(p));
        z.insert(r);
        be = getbe(r);
        ans += countbetween(be.first,be.second);

        cout << ans << "\n";
    }
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
