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
    int k,n;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k&1){
        string s1 = "";
        string s2 = "";
        for(int i=0; i<n; i++){
            if(i&1)s1 = s1 + s[i];
            else s2 = s2 + s[i];
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for(int i=0; i<n; i++){
            if(i&1)cout << s1[i/2];
            else cout << s2[i/2];
        }
        cout << "\n";

    }
    else{
        sort(s.begin(),s.end());
        cout << s << "\n";
    }
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
