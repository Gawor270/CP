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
    int n;
    cin >> n;
    vi s(n);
    for(auto&x : s)cin >> x;
    sort(all(s));
    int beg = 0;
    for(int i=0; i<n; i++){
        if(s[i] != i){
            beg = i;
            break;
        }
    }
    if(s.back() == (n-1))beg = n;
    int resp;
    while(beg+1){
        printf("%d\n",beg);
        fflush(stdout);
        scanf("%d",&resp);
        beg = resp;
    }
}

int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
