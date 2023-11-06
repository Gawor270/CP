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

vector<int> z(vector<int>& s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
        x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    bool eq = true;
    for(auto&x : A)cin >> x;
    for(int i=0; i<n; i++){
        cin >> B[i];
        if(A[i] != B[i])eq = false;
    }
    vector<int> Z(3*n+1);
    for(int i=0; i<n; i++)Z[i] = B[i];
    for(int i=n+1; i<=2*n; i++)Z[i] = A[i -(n+1)];
    for(int i=2*n+1; i <=3*n; i++)Z[i] = A[i - (2*n+1)];
    Z[n] = -1;
    if(eq && k == 1){
        Z[n+1] = Z[3*n] = -2;
    }

    vector<int> zv = z(Z);
    bool ok = false;
    for(int i=n; i<=(int)zv.size(); i++){
        if(zv[i] ==n){
            ok = true;
            break;
        }
    }

    if(k == 0){
        cout << (eq ? "YES" : "NO") << "\n";
    }
    else{
        if(n == 2){
            if(A[0] == A[1] && eq){
                cout << "YES" << "\n";
            }
            else cout << (ok && (eq + k)&1 ? "YES" : "NO") << "\n";
        }
        else cout << (ok ? "YES" : "NO" ) << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
