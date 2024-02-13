#include <bits/stdc++.h>
// https://szkopul.edu.pl/problemset/problem/gLRneBzycJPwyUgvhUOjwLVH/site/

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
    ll n,k;
    cin >> n >> k;
    vi res(n);
    int ind = 0;
    for(int i=0; i<n; i++){
        if(i&1){
            res[i] = i/2+1;
        }
        else{
            res[i] = n/2 + i/2 + 1;
        }
    }
    for(int i=1; i<n; i++){
        if(abs(res[i] - res[i-1]) < k){
            cout << "NIE";
            return;
        }
    }
    for(int i=0; i<n; i++){
        cout << res[i] << " ";
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
