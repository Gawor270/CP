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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi color(n);
    int color1 = 1, color2 = 2;
    bool used1 = false, used2 = false;
    vector<int> count(2,0);
    if(s[0] == ')')swap(color1,color2);
    for(int i=0; i<n; i++){
        if(s[i] == '(' && count[1] == 0){
            color[i] = color1;
            used1 = true;
            count[0]++;
        }
        else if(s[i] == '('){
            used2 = true;
            color[i] = color2;
            count[1]--;
        }
        else if(s[i] == ')' && count[0] == 0){
            color[i] = color2;
            used2 = true;
            count[1]++;
        }else{
            color[i] = color1;
            used1 = true;
            count[0]--;
        }
    }
    if(count[0] || count[1]){
        cout << -1 << "\n";

    } else{
        cout << used1 + used2 << "\n";
        for(int x : color)cout << x << " ";
        cout << "\n";
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
