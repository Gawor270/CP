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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<ar<int,3>> edges;

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
    ll n,m;
    cin >> n >> m;
    DSU dsu = DSU(n);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({c,a,b});
    }
    sort(all(edges));
    ll sum = 0;
    int count = 0;
    for( ar<int,3> &e : edges){
        if( !dsu.same(e[1],e[2])){
            dsu.unite(e[1],e[2]);
            sum += e[0];
            count++;
        }
    }
    cout << (count < n-1 ? "IMPOSSIBLE" : to_string(sum) ) << "\n";
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
