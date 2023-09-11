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

bool check(int a, int b, int c, int d){
    if(b < a && d < a && c < b && c < d)return true;
    return false;
}

void solve() {
    int a,b,c,d;
    cin >> a >> b >> d >> c;
    for(int i=0 ;i<4; i++){
       int tmp = a;
       a = d;
       int tmp1  = b;
       b = tmp;
       tmp = c;
       c = tmp1;
       d = tmp;
       if(check(a,b,c,d)){
           puts("YES");
           return;
       }
    }
    puts("NO");

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
