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
    vi a(n);
    for(auto& x : a)cin >> x;

    int mx = *max_element(all(a));
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] == mx)count++;
    }

    if(count == n){
        cout << -1  << "\n";
        return;
    }
    cout << n-count << " " << count << "\n";

    for(int i=0; i<n; i++){
        if(a[i] != mx)cout << a[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<count; i++)cout << mx << " ";
    cout << '\n';




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