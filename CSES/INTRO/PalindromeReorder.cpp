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
    int n = sz(s);
    string res = s;
    map<char,int> count;
    int b =0, e=n-1;
    for(char c : s)count[c]++;
    for(auto it : count){
        if(it.second&1){
            if(n&1)res[n/2] = it.first;
            else{
                cout << "NO SOLUTION\n";
                return;
            }
            it.second--;
            n--;
        }
        if(it.second%2 == 0){
            while(it.second){
                res[b] = it.first;
                res[e] = it.first;
                b++, e--;
                it.second -= 2;
            }
        }
    }
    cout << res << '\n';

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
