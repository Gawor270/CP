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


constexpr size_t limit = 1 << 5;
constexpr size_t limitBITS = log2(limit -1 ) + 1;
static_assert(1 << limitBITS >= limit);

using type = int;
constexpr static size_t base = 1 << limitBITS;
constexpr static type neutral = INT_MIN;
inline type op(const type a, const type b){
    return max(a,b);
}


vector<type> tree(base << 1, neutral);
void sett(size_t v, type x){
    v += base;
    tree[v] = x;
}

void init(){
    for(size_t v = base - 1; v; --v) tree[v] = op(tree[2*v], tree[2*v+1]);
}

type query(size_t l, size_t r) {
    type result = neutral;
    l += base -1;
    r += base + 1;
    while(r - l > 1) {
        if(!(l&1)) result = op(result, tree[l+1]);
        if(r&1) result = op(result, tree[r-1]);
        l >>= 1;
        r >>= 1;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i=0; i<n; i++){
        a[i] = 1;
        sett(i,a[i]);
    }

    init();
    for(int i=0; i<n ;i++){
        for(int j=i; j<n; j++){
            cout << query(i,j) << "\n";
        }
    }


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
    return 0;
}
