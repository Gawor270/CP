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

    vector<pi> events(2*n);
    for(int i=0; i<n; i++){
        int beg,end;
        cin >> beg >> end;
        events[2*i] = {beg,i};
        events[2*i+1] = {end,i};
    }

    sort(all(events));
    set<int> occ;
    vector<ll> t1(n);
    map<pi,ll> t2;
    ll last = events.begin()->first;
    for(pi event : events){
        ll dist = (event.first - last);
        if(occ.size() == 2 ){
            int e1 = *(occ.begin());
            int e2 = *(occ.rbegin());
            t2[{e1,e2}] += dist;
        }
        else if(occ.size() == 1){
            int e = *(occ.begin());
            t1[e] += dist;
        }

        if(occ.find(event.second) == occ.end()){
            occ.insert(event.second);
        }
        else{
            occ.erase(event.second);
        }
        last = event.first;
    }

    ll maxim = 0;
    for(const pair<pi,ll> p : t2){
        maxim = max(maxim,t1[p.first.first]+t1[p.first.second] + p.second);
    }

    sort(t1.rbegin(), t1.rend());

    cout << max(maxim,t1[0]+t1[1]) << "\n";
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
