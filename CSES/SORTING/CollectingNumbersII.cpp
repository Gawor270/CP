#include <bits/stdc++.h>
#include <iostream>

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
    int n, m;
    cin >> n >> m;
    vi vo(n);
    vi v(n);
    for(auto&x : vo){cin >> x; x--;}
    for(int i=0; i<n; i++)v[vo[i]] = i;

    int res = 1;
    for(int i=1; i<n; i++){
        res += (v[i] < v[i-1]);
    }
    while(m--){
        int a,b,c,d;
        cin >> c >> d;
        c--,d--;
        if(vo[d])res += (c < v[vo[d]-1]);
        if(vo[d]+1 < n)res -= (c < v[v[d]+1]);

        if(vo[c])res += (d < v[vo[c]-1]);
        if(vo[c]+1 < n)res -= (d < v[vo[c]+1]);

        swap(vo[c],vo[d]);
        swap(v[vo[c]],v[vo[d]]);

        cout << res << "\n";
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
