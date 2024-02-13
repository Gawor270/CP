#include <bits/stdc++.h>
// https://szkopul.edu.pl/problemset/problem/C03vrSVVhiHGjLdR3Gu1LuEq/site/

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n;
    cin >> n;
    string s;
    map<char,int> mp = {{'T', 0}, {'C',0}, {'G',0}, {'A',0}};
    cin >> s;
    for(char c : s){
        mp[c]++;
    }
    int minim = mp['T'];
    char c = 'T';
    for(const auto&el : mp){
        if(el.second < minim){
            minim = el.second;
            c = el.first;
        }
    }
    cout << mp[c] << "\n";
    cout << string(n,c) << "\n";

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
