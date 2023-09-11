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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> carp(n,vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> carp[i][j];
        }
    }

    string s = "vika";
    int k = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(carp[j][i] == s[k]){
                k++;
                break;
            }
        }
    }
    puts(k == 4 ? "YES" : "NO");

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
