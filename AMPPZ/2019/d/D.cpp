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
    vector<vi> add(n);
    vector<vi> del(n);
    for(int i=0; i<n; i++){
        int r,s;
        cin >> r >> s;
        add[max(0,i - r)].push_back(s);
        del[min(n-1, i+ r+1)].push_back(s);
    }

    multiset<int> st;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int x : add[i]){
            st.insert(x);
        }
        for(int x : del[i]){
            st.erase(st.find(x));
        }
        if(st.size() >= 3){
            auto ptr = st.rbegin();
            int sum = 0;
            for(int j=0; j<3; j++){
                sum += *ptr;
                ptr++;
            }
            ans = max(ans,sum);
        }
        
    }
    cout << ans << "\n";
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
