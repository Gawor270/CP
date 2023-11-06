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

const int MAX_N = 1e3 + 5;
const ll MOD = 1e6;
const ll INF = 1e9;
const ld EPS = 1e-9;
ll catalan[MAX_N];

void prepro(){
    catalan[0] = catalan[1] = 1;
    for(int i=2; i<MAX_N; i++){
        catalan[i] = 0;
        for(int j=0; j<i; j++){
            catalan[i] += (catalan[j] * catalan[i-j-1])%MOD;
            catalan[i] %= MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prepro();
    int n;
    cin >> n;
    while(n){
        cout << catalan[n] << "\n";
        cin >> n;
    }
}
