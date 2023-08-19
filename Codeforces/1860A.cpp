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
    string s;
    cin >> s;
    int n = s.length();
    if(s == "()"){
        cout << "NO" << "\n";
        return;
    }
    bool flag = false;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            flag = true;
            break;
        }
    }

    cout << "YES" << "\n";
    if(flag){
        for(int i=0; i<n; i++){
            cout << "()";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        cout << "(";
    }
    for(int i=0;i<n; i++){
        cout << ")";
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
