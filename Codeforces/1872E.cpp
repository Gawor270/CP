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
    int n,q;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    vi prefxor(n+1,0);
    string s;
    cin >> s;
    int xor1 = 0;
    int xor0 = 0;
    for(int i=0; i<n; i++){
        prefxor[i+1] = (prefxor[i] ^ a[i]);
        if(s[i] == '0')xor0 ^= a[i];
        else xor1 ^=a[i];
    }

    cin >> q;
    while(q--){
        int type;
        cin >> type;
        --type;
        if(type){
            int val;
            cin >> val;
            cout << (val ? xor1 : xor0 ) << " ";
        } else {
            int l,r;
            cin >> l >> r;
            l--;
            int segxor = (prefxor[r] ^ prefxor[l]);
            xor0 ^= segxor;
            xor1 ^= segxor;
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
