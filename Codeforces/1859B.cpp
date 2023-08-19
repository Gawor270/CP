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
    int n,m;
    cin >> n;
    int minim = 1e9 +5;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> m;
        vector<int> tmp(m);
        int mini = 1e9 + 5;
        int minind=0;
        for(int j=0; j<m; j++){
            cin >> tmp[j];
            if(mini > tmp[j]) {
                mini = tmp[j];
                minind = j;
            }
        }
        minim = min(minim,mini);
        a[i] = 1e9 + 5;
        for(int j=0; j<m; j++){
            if(j != minind){
                a[i]= min(a[i],tmp[j]);
            }
        }
    }
    sort(all(a));

    ll res = (ll)minim;
    for(int i = 1; i<n; i++)res += a[i];
    cout << res << "\n";
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