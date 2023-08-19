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

    ll maxim = 0;
    for(ll i=0; i<n; i++){
        vector<ll> newperm(n);
        for(ll j=0; j<i; j++){
            newperm[j] = (j+1)*(j+1);
        }
        for(ll j=i; j<n; j++){
            newperm[j] = (j+1)*(n-(j-i));
        }
        ll sum = 0;
        for(int j=0; j<n; j++)sum += newperm[j];
        sum -= *max_element(all(newperm));
        maxim = max(maxim,sum);
    }

    cout << maxim << "\n";
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