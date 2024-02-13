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


vector<vector<bool>> grayCode = {{0},{1}};

void setCode(int n){
    if(n==1) return;
    grayCode.resize(2*grayCode.size());
    for(int i=0; i<grayCode.size()/2; i++){
        grayCode[grayCode.size()-i-1] = grayCode[i];
        grayCode[i].push_back(0);
        grayCode[grayCode.size()-i-1].push_back(1);
    }
    setCode(n-1);
}


void solve() {
    int n;
    cin >> n;
    setCode(n);
    for(auto v: grayCode){
        for(auto b: v){
            cout << (b ? 1 : 0);
        }
        cout << "\n";
    }

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
