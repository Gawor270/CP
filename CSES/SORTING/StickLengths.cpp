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


ll eval(vector<ll> &a, ll lng){
    ll res= 0;
    for(ll x : a){
        res += abs(lng - x);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto&x : a)cin >> x;

    ll lb = 1;
    ll ub = *max_element(all(a));
    while(lb < ub){
        ll md = (lb + ub)/2;
        if(eval(a,md-1) >= eval(a,md) && eval(a,md) <= eval(a,md+1)){
            lb = ub = md;
        }
        else if(eval(a,md) < eval(a,md+1)){
            ub = md-1;
        }
        else{
            lb = md+1;
        }
    }
    cout << eval(a,lb) << "\n";

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
