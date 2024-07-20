#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// https://cses.fi/problemset/task/1676
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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

struct DSU {
    int* parent;
    int* size;

    DSU(const int n){
        parent = new int[n];
        size = new int[n];

        for(int i=0; i<n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] != x)parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x != root_y){
            if(size[root_x] < size[root_y])swap(root_x, root_y);
            parent[root_y] = root_x;
            size[root_x] += size[root_y];

        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    ~DSU(){
        delete[] parent;
        delete[] size;
    }

};

void solve() {
    int n,m;
    cin >> n >> m;
    DSU dsu = DSU(n);
    int count = n;
    int mx = 1;
    while(m--){
        int s,t;
        cin >> s >> t;
        s--, t--;
        if(!dsu.same(s,t)){
            dsu.unite(s,t);
            count--;
            mx = max(mx, dsu.size[dsu.find(s)]);
        }
        printf("%d %d\n", count ,mx);
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
