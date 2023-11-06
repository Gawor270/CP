#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ll long long


#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<pi> g[MAX_N];
int parent[MAX_N];
int r[MAX_N];
int ds[MAX_N];
int n;

void dijkstra(int s) {
    REP(i,n+1) { ds[i] = INF; }
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
    ds[s] = 0; q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        int dist = q.top().first;
        q.pop();
        if (dist!=ds[u]) continue;
        for(auto &i : g[u])
            if (ds[i.second] > ds[u] + i.first) {
                ds[i.second] = ds[u] + i.first;
                q.push(make_pair(ds[i.second], i.second));
            }
    }
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    r[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);
        parent[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
}

void solve() {
    int s,m,c;
    cin >> n >> s >> m;
    for(int i=0; i<s; i++){
        cin >> c;
        g[0].push_back({0,c});
    }

    vector<vector<int>> edg(m);
    for(int i=0; i<m; i++){
        int u,v,d;
        cin >> u >> v >> d;
        edg[i] = {d,u,v};
        g[u].push_back({d,v});
        g[v].push_back({d,u});
    }

    dijkstra(0);
    for(int i=0; i<m; i++){
        edg[i][0] = edg[i][0] + ds[edg[i][1]] + ds[edg[i][2]];
    }
    sort(ALL(edg), []
        (const vi&a , const vi&b){
            return a[0] < b[0];
        } 
    );

    int q;
    cin >> q;
    vector queries(q,vector<int>(4));
    REP(i,q){
        int x,y,b;
        cin >> x >> y >> b;
        queries[i] = {x,y,b,i};
    }

    sort(ALL(queries), []
        (const vi&a , const vi& b){
            return a[2] < b[2];
        } 
    );

    vector<string> ans(q);
    REP(i,n+1)make_set(i);
    int i =0;
    for(auto v : queries){
        while(i < m && edg[i][0] <= v[2]){
            union_sets(edg[i][2],edg[i][1]);
            i++;
        }
        ans[v[3]] = find_set(v[0]) == find_set(v[1]) ? "TAK" : "NIE";
    }

    for(string a : ans){
        cout << a << "\n";
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
