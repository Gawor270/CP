#include <bits/stdc++.h>

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



void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    int diff1 = b-a;
    int diff2 = c-b;
    int diff3 = c - a;

    if(b+diff1 >= 1 && (b + diff1)%c == 0){
        puts("YES");
    }
    else if(b-diff2 >= 1 && (b-diff2)%a == 0){
        puts("YES");
    }
    else if(diff3%2 ==0 && a + (diff3)/2 >= 1 &&  (a+(diff3/2))%b == 0){
        puts("YES");
    }
    else{
        puts("NO");
    }
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
