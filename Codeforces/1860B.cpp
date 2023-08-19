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
    int m,k,a1,ak,howk,howk2,count1,count2;
    cin >> m >> k >> a1 >> ak;

    howk = m/k;
    m -= ((int)min(howk,ak))*k;
    m = (int)max(0,m-a1);
   
    count2 =0;
    howk2 = m/k;
    count2 += howk2;
    m -= howk2*k;
    if(m != 0 && (m + a1) >= k){
        count2++;
    }
    else{
        count2 += m;
    }

    cout << count2 << "\n";

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
