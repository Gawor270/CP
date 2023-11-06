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

unordered_map<ll,bool> mp;
unordered_map<ll,vector<int>> vmp;
vector<int> act;

void prepro(ll num,ll prod,int last){
    if(num == 0){
        mp[prod] = true;
        vmp[prod] = act;
    }
    for(int i=last; i<=num; i++){
        act.push_back(i);
        prepro(num-i,prod*i,i);
        act.pop_back();
    }
}

void solve() {
    ll p;
    cin >> p;
    if(mp[p] == true){
        cout << vmp[p].size() << " ";
        for(int x : vmp[p])cout << x << " ";
    }
    else{
        cout << -1;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    prepro(41,1,1);
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
