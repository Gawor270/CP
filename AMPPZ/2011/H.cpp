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
    if(n == 1){
        cout << "HM" << "\n";
        return;
    }
    int counth = 0;
    int countm = 0;
    char c;
    for(int i=0; i<n-1; i++){
        cin >> c;
        counth += (c == 'H');
        countm += (c == 'M');
    }
    char grb;
    cin >> grb;
    if(counth > countm){
        cout << "H";
    }
    else if(countm > counth){
        cout << "M";
    }
    else{ 
        cout << (c == 'H' ? "M" : "H");
    }
    cout << "\n";

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
