#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ld EPS = 1e-9;


void solve() {
    int n,m;
    cin >> n >> m;
    vector<char> st(n);
    for(auto& x : st)cin >> x;

    vector<int> l0(n);
    vector<int> l1(n);

    l0[0] = -1;
    for(int i=0; i<n; i++){
        if(i)l0[i] = l0[i-1];
        if(st[i] == '0')l0[i] = i;
    }

    l1[n-1] = n;
    for(int i=n-1; i>=0; i--){
        if(i < n-1)l1[i] = l1[i+1];
        if(st[i] == '1')l1[i] = i;
    }

    set<pair<int,int>> diff;
    while(m--){
        int l,r;
        cin >> l >> r;
        int ll = l1[l-1], rr = l0[r-1];
        if(ll > rr){
            diff.insert({-1,-1});
        }
        else{
            diff.insert({ll,rr});
        }
    }
    
    cout << diff.size() << "\n";

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
