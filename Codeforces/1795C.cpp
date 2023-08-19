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
    int n;
    cin >> n;
    vi a(n),b(n);
    vector<ll> res(n);
    for(auto&x : a)cin >> x;
    for(auto&x : b)cin >> x;


    ll remain = 0;
    for(int i=n-1; i>=0; i--){
        ll tmp = (ll)a[i]+ remain - (ll)b[i];
        if(tmp <= 0){
            res[i] = (ll)a[i] + remain;
            remain = 0;
        }
        else{
            
        }   
    }

    for(auto&x : res)cout << x << " ";
    cout << "\n";
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