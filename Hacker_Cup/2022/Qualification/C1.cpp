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
    string c;
    cin >> c;
    string s;
    bool mode = false;
    if(c[0] == '.'){
        s = ".-";
    } else {
        s = "-.";
        mode = true;
    }
    for(int i=0; i<n-1; i++){
        for(int j=(int)s.length()-1; j>=0; j--)cout << s[j];
        cout << "\n";
        if(mode){
            s.push_back('.');
        } else{
            s. push_back('-');
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": \n";
        solve();
    }
}
