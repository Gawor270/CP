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
    string m = "meow";
    string s;
    cin >> s;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int i = 0;
    for(int j=0; j<4; j++){
        int count = 0;
        while(i < n && s[i] == m[j]){
            i++;
            count++;
        }
        if(count == 0){
            puts("NO");
            return;
        }
    }

    i == n ? puts("YES") : puts("NO");
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
