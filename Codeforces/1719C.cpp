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
    int n,q;
    cin >> n >> q;
    vi a(n);
    int maxim = 0;
    int maxind = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > maxim){
            maxind = i;
            maxim = a[i];
        }
    }
    vector<int> start(n,-1);
    vector<int> len(n,0);
    int p1 = 0;
    int j = 1;
    for(int i = 1; i<n; i++){
        int p2 = i;
        if(a[p1] < a[p2])swap(p1,p2);
        if(start[p1] == -1)start[p1] = j;
        len[p1]++;
        j++;
    }

    while(q--){
        int i,k;
        cin >> i >> k;
        i--;
        if(k > n-1){
            if(i == maxind){
                cout << len[i] + k -(n-1) << "\n";
            } else {
                cout << len[i] << "\n";
            }
        } else{
            if(start[i] == -1){
                cout << 0 << "\n";
            }
            else if(k - start[i] < 0){
                cout << 0 << "\n";
            } else{
                cout << min(k - start[i]+1, len[i]) << "\n";
            }
        }

    }
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
