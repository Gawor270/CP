#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

template<class T>
struct RQ{
    typedef T (*funcPtr)(T,T);
    funcPtr f;

    int n,k;
    int maxn;
    vector<vector<T>> st;

    int log2_floor(T x){
        return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
    }

    RQ(funcPtr f, int n, vector<T> arr){
        this-> n = n;
        this-> f = f;
        k = log2_floor(n)+1;
        st.assign(k+1, vector<T>(n));
        for(int i=0; i<n; i++)st[0][i] = arr[i];
        for(int i=1; i<=k; i++){
            for(int j=0; j+(1<<i) <= n; j++){
                st[i][j] = f(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }

    T query(int l, int r){
        int len = r-l+1;
        int j = log2_floor(len);
        return f(st[j][l], st[j][r-(1<<j)+1]);
    }
};

ll rangesum(int l, int r, vector<ll>& prefsum){
    return prefsum[r+1] - prefsum[l];
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vector<ll> prefsum(n+1,0);
    for(auto&x : a)cin >> x;
    for(int i=1; i<=n; i++){
        prefsum[i] = prefsum[i-1] + a[i-1];
    }
    RQ<int> rqmin([](int a, int b){return min(a,b);}, n, a);
    RQ<int> rqmax([](int a, int b){return max(a,b);}, n, a);

    for(int i=0; i<n; i++){
        if((i && a[i-1] > a[i]) || (i+1 < n && a[i+1] > a[i])){
            cout << "1 ";
            continue;
        }
        int res = 1e9;
        if(i && rqmin.query(0,i-1) != rqmax.query(0,i-1) && rangesum(0,i-1, prefsum) > a[i]){
            int r = i-1;
            int l = 0;
            while(r-l > 1){
                int md = l + (r-l)/2;
                ll psum = rangesum(md,i-1,prefsum);
                if(rqmin.query(md,i-1) != rqmax.query(md,i-1) && psum > a[i]){
                    l = md;
                }
                else{
                    r = md;
                }
            }
            res = min(res, abs(i - l));
        }
        if(i+1 < n && rqmin.query(i+1,n-1) != rqmax.query(i+1,n-1) && rangesum(i+1, n-1, prefsum) > a[i]){
            int r = n-1;
            int l = i+1;
            while(r-l > 1){
                int md = l + (r-l)/2;
                ll psum = rangesum(i+1,md,prefsum);
                if(rqmin.query(i+1,md) != rqmax.query(i+1,md) && psum > a[i]){
                    r = md;
                }
                else{
                    l = md;
                }
            }
            res = min(res, abs(i - r));
        }
        cout << (res == 1e9 ? -1 : res) << " ";
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
