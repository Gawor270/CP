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
    int n;
    cin >> n;
    vi b(n);
    for(auto&x : b)cin >> x;
    vi a;
    a.push_back(b[0]);
    for(int i=1; i<n; i++){
        if(b[i-1] <= b[i]){
            a.push_back(b[i]);
        }
        else{
            a.push_back(min(b[i-1]-1,b[i]));
            a.push_back(b[i]);
        }
    }
    cout << a.size() << "\n";
    for(int x : a){
        cout << x << " ";
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
