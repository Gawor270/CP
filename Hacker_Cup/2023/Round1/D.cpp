#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 2e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int n, q, arr[MAX_N], st[4 * MAX_N];
 
void build(int node, int start, int end) {
    if (start == end) {
        st[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    st[node] = st[2*node] + st[2*node +1];
}
 
void update(int node, int start, int end, int l, int r, int x) {
    if(start > r || end < l)return;
    if(l <= start && r <= end){
        st[node] += x;
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid,l,r,x);
    update(2 * node + 1, mid + 1, end,l,r,x);
    st[node] = st[2*node] + st[2*node + 1];
}

 
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    ll ans = 0;
    while (q--) {
        int l,r;
        cin >> l >> r;
        l--,r--;
        int x;
        cin >> x;
        update(1,1,n,l,r,x);
        cout << st[1] << endl;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
