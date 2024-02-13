#include <bits/stdc++.h>
// https://szkopul.edu.pl/problemset/problem/LEXKjN1FW1TpGdLBIpna6vwt/site/
using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

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
const ld EPS = 1e-9;


struct point{
    int x,y;

    bool operator<(const point& other) const {
        // Define the comparison logic for points
        // For example, you can compare based on x and then y if x is equal
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

struct ComparePairs {
    bool operator()(const std::pair<int, point>& a, const std::pair<int, point>& b) {
        // Compare the pairs based on the integer values (first element) of the pairs.
        // For a min priority queue, we want smaller integers to have higher priority.
        return a.first > b.first;
    }
};

map<point, vector<pair<int,point>>> g;
map<point, int> d;

int dist(point a, point b){
    return min(abs(a.x - b.x), abs(a.y - b.y));
}

int dijkstra(point s, point t) {
    priority_queue< pair<int, point>, vector<pair<int, point> >, ComparePairs > q;
    q.push(make_pair(0,s));
    d[s] = 0;
    while(!q.empty()){
        point u = q.top().second;
        int dist = q.top().first;
        q.pop();
        if(dist != d[u])continue;
        for(auto & i : g[u]) {
            if(d[i.second] > d[u] + i.first) {
                d[i.second] = d[u] + i.first;
                q.push(make_pair(d[i.second], i.second));
            }
        }

    }
    return d[t];
}

void solve() {
    int n;
    cin >> n;
    vector<point> tx(n);
    REP(i,n){
        int x,y;
        cin >> x >> y;
        tx[i] = {x,y};
        d[tx[i]] = INF;
    }
    point s = tx[0];
    point t = tx[n-1];


    vector<point> ty = tx;
    sort(tx.begin(), tx.end(), []
        (const point& a, const point& b){
            return a.x < b.x;
        } 
    );
    sort(ty.begin(), ty.end(), []
        (const point& a, const point& b){
            return a.y < b.y;
        } 
    );

    REP(i,n-1){
        int d1 = dist(tx[i],tx[i+1]);
        int d2 = dist(ty[i],ty[i+1]);
        g[tx[i]].push_back(make_pair(d1, tx[i+1]));
        g[tx[i+1]].push_back(make_pair(d1, tx[i]));
        g[ty[i]].push_back(make_pair(d2, ty[i+1]));
        g[ty[i+1]].push_back(make_pair(d2, ty[i]));
    }

    cout << dijkstra(s,t) << "\n";

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
