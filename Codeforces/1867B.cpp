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
    string s;
    cin >> s;
    int count = 0;
    int count1 = 0;
    int count0 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1')count1++;
        else count0++;
    }
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-1-i])count++;
    }
    count1 -= count;
    for(int i=0; i<=n; i++){
        if(i < count)cout << 0;
        else{
            if(i > (n - count)){
                cout << 0;
                continue;
            }
            if(n&1){
                cout << 1;
            } else {
                if((i-count)%2 == 0){
                    cout << 1;
                } else{
                    cout << 0;
                }
            }
        }
    }
    cout << "\n";
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
