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
    vector<pi> a(2*n);
    for(int i=0; i<n; i++){
        cin >> a[2*i].first >> a[2*i+1].first;
        a[2*i].second = 1, a[2*i+1].second = -1;
    }
    sort(all(a));
    int maxim = 0;
    int count = 0;
    for(auto& event : a){
        count += event.second;
        maxim = max(maxim,count);
    }
    cout << maxim << "\n";
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
