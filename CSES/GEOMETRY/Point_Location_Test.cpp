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
    ll x, y;

    point(){
        x = 0, y=0;
    }

    point(ll x, ll y){
        this->x = x, this->y = y;
    }

    point operator -(point& other){
        return point(x - other.x, y - other.y);
    }

    ll det(point& other){
        return x*other.y - y*other.x;
    }
};

void solve() {
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    point v1 = point(p2-p1);
    point v2 = point(p3-p1);
    ll res = v1.det(v2);
    if(res > 0){
        cout << "LEFT";
    }
    else if(res < 0){
        cout << "RIGHT";
    }
    else{
        cout << "TOUCH";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc ;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
