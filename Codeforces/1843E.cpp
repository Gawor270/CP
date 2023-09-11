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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<pair<int,int>> seg;
vector<int> changes;

bool check(int k, int n, int m){
    vector<int> newarr(n, 0);
    for(int i=0; i<=k; i++){
        newarr[changes[i]] = 1;
    }
    vector<int> prefsum(n+1);
    prefsum[0] = 0;
    for(int i=1; i<=n; i++){
        prefsum[i] = prefsum[i-1] + newarr[i-1];
    }

    for(int i=0; i<m; i++){
        int no1 = prefsum[seg[i].second+1] - prefsum[seg[i].first];
        int len = seg[i].second - seg[i].first + 1;
        if(no1 > len/2)return true;
    }
    return false;
}

void solve() {
    int n,m,q;
    cin >> n >> m;
    vector<int> minim(n,1e9);
    seg.resize(m);
    for(int i=0; i<m; i++){
        int l,r;
        cin >> l >> r;
        seg[i] = {--l,--r};
    }
        

    cin >> q;
    changes.resize(q);
    for(int i=0; i<q; i++){
        int inp;
        cin >> inp;
        changes[i] = --inp;
    }
    
    int lb = 0;
    int ub = q;

    bool flag = false;
    while(lb < ub){
        int md = lb + (ub-lb)/2;
        if(check(md,n,m)){
            flag = true;
            ub = md;
        }
        else{
            lb = md+1;
        }
    }

    cout << (flag ? lb+1 : -1) << "\n";

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
