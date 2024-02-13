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
    bool operator ==(point& other){
        return x == other.x && y == other.y;
    }

    ll det(point& other){
        return x*other.y - y*other.x;
    }
};

bool pred(ll a, ll b){
    return a ==0 || b ==0 || (a < 0 && b > 0) || (b < 0 && a > 0);
}

void solve() {
    point p1,p2,p3,p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    if(p1 ==p3 || p1 == p4 || p2 == p3 || p2 == p4){
        cout << "YES\n";
        return;
    }
    
    if(min(p3.x,p4.x) > max(p1.x, p2.x) || max(p3.x,p4.x) < min(p1.x,p2.x)  || min(p3.y,p4.y) > max(p1.y, p2.y) || max(p3.y,p4.y) < min(p1.y,p2.y)){
        cout << "NO" << "\n";
        return;
    }
    point v1 = p2 - p1;
    point v2 = p3 - p1;
    point v3 = p4 - p1;
    point v4 = p4 - p3;
    point v5 = p1 - p3;
    point v6 = p2 - p3;
    ll d1 = v1.det(v2), d2 = v1.det(v3), d3 = v4.det(v5), d4 = v4.det(v6);
    if(pred(d1,d2) && pred(d3,d4) ){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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
