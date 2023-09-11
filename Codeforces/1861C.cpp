#include <bits/stdc++.h>
 
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
    int size = 0;
    int last = 1e9;
    int mn = 0; 
    int count = 0;
    char lasts = '1';
    bool ok = true;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            if(lasts != s[i] && count == 0)ok = false;
            if(size < 2 || (lasts != s[i] && mn >= last))ok = false;
            if(lasts != s[i] && mn < last)last = size;
            if(lasts == s[i] && mn < last)last = size;
            mn = size;
            lasts = s[i];
            count = 0;
        }
        if(s[i] == '1'){
            if(lasts != s[i] && count == 0)ok = false;
            if(lasts != s[i] && mn >= last)ok = false;
            else last = 1e9;
            lasts = s[i];
            count = 0;
        }
        if(s[i] == '+'){size++; count++;};
        if(s[i] == '-'){
            size--;
            mn = min(mn,size);
            count++;
        }
    }
    puts((ok ? "YES" : "NO"));
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
