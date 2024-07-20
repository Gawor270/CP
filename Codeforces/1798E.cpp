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
        vi a(n);
        bool ok  = false;
        for(int i=0; i<n; i++){cin >> a[i]; if(a[i])ok = true;}
        if(!ok){cout << "No" << "\n"; return;}
     
        cout << "Yes" << "\n";
        vi pos, neg;
        int prefsum = 0;
        for (int x : a) {
            if (x >= 0) {
                pos.push_back(x);
            }
            else {
                neg.push_back(x);
            }
        }
        int j1 = 0;
        int j2 = 0;

        for (int i=0; i<n; i++) {
            if (prefsum <= 0) {
                cout << pos[j1] << " ";
                prefsum += pos[j1];
                j1++;
            }
            else {
                cout << neg[j2] << " ";
                prefsum += neg[j2];
                j2++;
            }
        }
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
