#include <bits/stdc++.h>

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
    ll x,y;

    point operator -(point& other){
        return point{x - other.x, y - other.y};
    }
    bool operator <(const point& b) const { return x == b.x ? y < b.y : x < b.x; }
    ll det(point& other){
        return x*other.y - y*other.x;
    }
};

point P[MAX_N];

void solve() {
    int n;
    cin >> n;
    vector<point> hull;
    hull.clear();
    REP(i,n){
        cin >> P[i].x >> P[i].y;
    }

    sort(P, P + n);
    
    int S  = 0;
    REP(_,2){
        for(int i=0; i<n; i++){
            while((int)hull.size() - S >= 2){
                point p1 = hull[hull.size()-2];
                point p2 = hull[hull.size()-1];
                point v1 = P[i] - p1;
                point v2 = p2 - p1;
                if(v1.det(v2) >= 0)break;
                hull.pop_back();
            }
            hull.push_back(P[i]);
        }
        hull.pop_back();
        S = hull.size();
        reverse(P, P + n);
    }

    cout << hull.size() << "\n";
    for(point p : hull){
        cout << p.x << " " << p.y << "\n";
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
