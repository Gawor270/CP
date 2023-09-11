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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
bool poss[MAX_N];

void prepro(){
    for(int i=2; i*i<MAX_N; i++){
        int last = i*i;
        int ind = 1 + i + i*i;
        while(ind < MAX_N){
            poss[ind] = true;
            ind += last*i;
            last *= i;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    puts((poss[n] ? "YES" : "NO"));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    prepro();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
