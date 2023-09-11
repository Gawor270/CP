#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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


int extendEuc(int a, int b, int& x, int & y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = extendEuc(a,b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

void solve() {
    int a,b,c;
    cin >> a >> b >> c ;
    int x,y;
    int d = extendEuc(a,b,x,y);
    if(c%d){
        puts("No");
        return;
    }

    x *= c/d;
    y *= c/d;
    if(a<0)x = -x;
    if(b<0)y = -y;
    if(x < 0){
        while(x < 0){
            x += b/d;
            y -= a/d;
        }
        if(y<0){
            puts("No");
            return;
        }
        puts("Yes");
        return;
    }
    if(y<0){
        while(y<0){
            y += a/d;
            x -= b/d;
        }
        if(x < 0){
            puts("No");
            return;
        }
        puts("Yes");
        return;
    }
    puts("Yes");
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
