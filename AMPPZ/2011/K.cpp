#include <bits/stdc++.h>
// https://szkopul.edu.pl/problemset/problem/zanbxXE8whXFqUbok2Aei9RK/site/?key=statement

using namespace std;

#define int long long

const int M1 = 1e10 + 7;
const int M2 = 1e10 + 8;


struct Point{
    int x,y,z;

    Point() : x(0), y(0), z(0) {}
    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    Point operator - (Point& other){
        return Point(this->x - other.x, this->y - other.y, this->z - other.z);
    }

};

Point crossProduct(const Point& a, const Point& b) {
    return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

bool areColinnear(const Point& vec1, const Point& vec2){
    Point prod = crossProduct(vec1, vec2);
    return (prod.x ==0 && prod.y == 0 && prod.z == 0);
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i=0; i<n; i++){
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    if(n <= 3){
        cout << "TAK" << "\n";
        return;
    }
    Point a = points[0], b = points[1];
    Point v1 = b -a;
    Point v2;
    bool flag = true;
    for(int i=2; i<n; i++){
        if(!areColinnear(v1, points[i] - a)){
            flag = false;
            v2 = points[i] - a;
            break;
        }
    }
    if(flag){
        cout << "TAK" << "\n";
        return;
    }
    Point normal = crossProduct(v1,v2);

    for(int i=3; i<n; i++){
        Point d = points[i];
        int s1 = ((normal.x * (d.x -a.x) + M1)%M1 + (normal.y * (d.y -a.y) + M1)%M1 + (normal.z * (d.z - a.z) + M1)%M1)%M1;
        int s2 = ((normal.x * (d.x -a.x) + M2)%M2 + (normal.y * (d.y -a.y) + M2)%M2 + (normal.z * (d.z - a.z) + M2)%M2)%M2; 

        if(s1 || s2){
            cout << "NIE" << "\n";
            return;
        }
    }
    cout << "TAK" << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
