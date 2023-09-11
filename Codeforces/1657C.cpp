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

bool ispalind(int i, int j, string s){
    bool ok = true;
    while( i < j ){
        ok &= (s[i] == s[j]);
        i++;
        j--;
    }
    return ok;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n;
    int i = 0;
    int count = 0;
    int state = 0;
    int len = 0;
    while(i<n){
        if(s[i] == '('){
            if(state){
                len++;
            }
            else if(i+1 < n){
                count++;
                ans-=2;
                i += 1;
            }
            i++;

        } else {
            if(state){
                len++;
                state = 0;
                count++;
                ans -= len;
                len = 0;
            }
            else{
                state = 1;
                len++;
            }
            i++;
        }
    }

    cout << count << " " << ans << "\n";

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
