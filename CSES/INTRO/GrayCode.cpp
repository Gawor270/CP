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

bool bs[16];

void printbs(int n){
    for(int i=0; i<n;i++){
        if(bs[i])cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

void line(int n,int bound){
    printbs(n);
    bs[0] = 1;
    printbs(n);
    for(int i=1; i<bound; i++){
        bs[i] = 1;
        printbs(n);
        bs[i-1] = 0;
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i=n; i>0; i--){
        line(n,i);
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
