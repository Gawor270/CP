#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;
const ld EPS = 1e-9;



void solve() {
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> s(m+2);
    for(int i=1; i<=m; i++)cin >> s[i];
    s[0] = 1-d;
    s[m+1] = n+1;

    int res = m;
    for(int i=1; i<=m+1; i++){
        int dist = s[i] - s[i-1]-1;
        res += dist/d;
    }

    int minim = INF;
    int count = 1;
    for(int i=1; i<=m; i++){
        int dist1 = s[i] - s[i-1]-1;
        int dist2 = s[i+1]-s[i]-1;
        int dist3 = s[i+1] - s[i-1]-1;
        int delta = dist3/d - (dist1/d + dist2/d);
        if(delta < minim){
            count = 1;
            minim = delta;
        }
        else if(delta == minim)count++;
    }

    cout << res + minim -1 << " " << count << "\n";


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
