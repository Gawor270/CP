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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> days(m, {(int)1e9,0,0,0}); 

    for(int i=0; i<n; i++){
        int d,a,b;
        cin >> a >> b >> d;
        if(b < days[--d][0]){
            days[d] = {b, days[d][1], i+1, days[d][3]};
        }
        if(a > days[d][1]){
            days[d] = {days[d][0], a, days[d][2], i+1};
        }
    }

    for(int i=0; i<m; i++){
        if(days[i][0] < days[i][1]){
            cout << "TAK" << " " << days[i][2] << " " << days[i][3] << "\n";
        }
        else{
            cout << "NIE" << "\n";
        }
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
