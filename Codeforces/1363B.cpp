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

int comp(string a, string b){
    int count = 0;
    for(int i=0; i<a.length();i++){
        if(a[i] != b[i])count++;
    }
    return count;
}
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int minim = 1e9;
    vector<pi> prefleft(n+1,{0,0});
    vector<pi> prefright(n+1,{0,0});

    for(int i=0; i<n; i++){
        prefleft[i+1].first = prefleft[i].first + (s[i] == '0');
        prefleft[i+1].second = prefleft[i].second + (s[i] == '1');
    }

    for(int i=n-1; i>=0; i--){
        prefright[i].first = prefright[i+1].first + (s[i] == '0');
        prefright[i].second = prefright[i+1].second + (s[i] == '1');
    }

    for(int i=0; i<n; i++){
        minim = min(minim,prefleft[i].first + prefright[i].second);
        minim = min(minim,prefleft[i].second + prefright[i].first);
    }
    cout << minim << "\n";
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
