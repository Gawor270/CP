#include <bits/stdc++.h>
// https://amppz.tcs.uj.edu.pl/2022/data/amppz.pdf
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
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    for(int i=0; i<n-3; i++){
        if(s.substr(i,4) == "ania"){
            count++;
            i += 3;
        }
    }
    cout << count << "\n";
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
