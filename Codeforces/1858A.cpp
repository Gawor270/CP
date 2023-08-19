#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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
    ll a,b,c;
    cin >> a >> b >> c;

    if(c&1){
        a += c/2 +1;
        b += c/2;
    }
    else{
        a += c/2;
        b += c/2;
    }

    if(a > b){
        cout << "First" << "\n";
    }
    else{
        cout << "Second" << "\n";
    }



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
