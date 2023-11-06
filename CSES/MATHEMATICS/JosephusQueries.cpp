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



int solve(int n, int k) {
        if(n == 1)return 1;
        if(k <= (n+1)/2) return 2*k > n ? (2*k)%n : 2*k;
        int tmp = solve(n/2, k - (n+1)/2);
        return n&1 ? 2*tmp +1 : 2*tmp -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n,k;
        cin >> n >> k;
        cout << solve(n,k) << "\n";
    }
}
