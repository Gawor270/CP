#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++)cin >> b[i];

    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            cout << "NO\n";
            return;
        }
        else if(a[i] < b[i]){
            bool found = false;
            for(int j=i+1; j<n; j++){
                if(a[j] > b[i] || b[j] < b[i]){
                    break;
                }
                if(a[j] == b[i]){
                    found = true;
                    break;
                }
            }
            if(found)continue;
            for(int j = i-1; j>=0;  j--){
                if(a[j] > b[i] || b[j] < b[i]){
                    break;
                }
                if(a[j] == b[i]){
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
