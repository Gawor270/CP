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
        vector<ll> a(n);
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum%n){
            cout << "No" << "\n";
            return;
        }
        ll avr = sum/n;
     
        int count[32] = {};
        for(int i=0; i<n; i++){
            int diff = avr - a[i];
            bool swap = (diff < 0);
            if (diff < 0)diff *= -1;
            if (diff){
                bool found = false;
                for (int j=0; j<32; j++){
                    if(__builtin_popcountll((1 << j) - diff) == 1){
                        found = true;
                        int got = j;
                        int give = (int)log2((1<<j) - diff);
                        if(swap){
                            count[give]++;
                            count[got]--;
                        }
                        else{
                            count[got]++;
                            count[give]--;
                        }
                    }
                }
                if(!found){
                    cout << "No\n";
                    return;
                }
            }
        }
        int errors = 0;
        for(int x : count){
            errors += abs(x);
        }

        cout << (errors ? "No\n" : "Yes\n");
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