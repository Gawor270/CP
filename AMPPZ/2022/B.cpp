#include<bits/stdc++.h>

#define ll long long
#define ci const int
#define vi vector<int>
#define pb emplace_back
#define fi first
#define se second

using namespace std;
using point = pair<int, int>;

pair<int,int> operator-(const pair<int,int> &p, const pair<int,int> &q) {return {make_pair(p.first - q.first, p.second - q.second)};}

ll det(const pair<int,int> &p, const pair<int,int> &q) { return 1LL * p.fi * q.se - 1LL * p.se * q.fi; }

void solve() {

    int n;
    cin >> n;
    vi a(n);
    for(int& x : a) cin >> x;
    vector<pair<int,int>> st;

    for(int x=0; x<n; x++){
        pair<int,int> t = pair<int,int>(x, a[x]);
        while(st.size() > 1 && det(t - st.end()[-2], st.back() - st.end()[-2]) <= 0) st.pop_back();
        st.push_back(t);
    }

    ll ans = 0;
    for(int i =0; i < st.size() - 1; i++){
        ans += 1ll * (st[i].se + st[i + 1].se) * (st[i + 1].fi - st[i].fi);
    } 

    cout << ans << "\n";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}