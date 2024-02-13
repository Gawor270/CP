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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct point{
    ll x,y;
};

void solve() {
    int n;
    cin >> n;
    vector<point> points(n);
    REP(i,n){
        cin >> points[i].x >> points[i].y;
    }
    points.push_back(points.front());


    ll res = 0;
    REP(i,n){
        res += points[i].x*points[i+1].y - points[i+1].x*points[i].y;
    }
    cout << abs(res) << "\n";
     
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
