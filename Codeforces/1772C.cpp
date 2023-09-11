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
    cin >> k >> n;
    vector<int> a;
    int free = n-k;
    
    a.push_back(1);
    int sz = 1;
    int count = 1;
    int num = 1;
    while(free - count >= 0 && sz<k){
        a.push_back(num + 1 + count);
        sz++;
        num = num + 1 + count;
        free -= count;
        count++;
    }

    while(sz < k){
        ++sz;
        ++num;
        a.push_back(num);
    }

    for(int x : a)cout << x << " ";

    cout << "\n";
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
