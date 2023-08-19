#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a*d == b*c){
        cout << 0 << "\n";
        return;
    }

    ll mx = max(a*d,b*c);
    ll mn = min(a*d,b*c);
    if(mx == 0 || mn ==0){
        cout << 1 << "\n";
        return;
    }

    if(mx % mn == 0){
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}