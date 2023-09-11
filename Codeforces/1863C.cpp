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
 
bool used[MAX_N];
 
void solve() {
    int n,k;
    cin >> n >> k;
    vi a(n);
    k = (k%(n+1));
    for(auto&x : a)cin >> x;
   
    vector<int> res(n);
    memset(used,0,(n+1)*sizeof(bool));
    bool flag = true;
    int num;
    for(int i=0; i<n; i++){
        int ni = (i + k);
        if(ni<n){
            res[ni] = a[i];
            used[a[i]] = true;
        }
        else{
            ni -= n;
            if(flag){
                num = a[i];
                flag = false;
            }
            if(i+1 < n){
                res[ni] = a[i+1];
                used[a[i+1]] = true;
            }
            else{
                for(int j=0; j<=n; j++){
                    if(!used[j] && j != num){
                        res[ni] = j;
                    }
                }
            }
        }
    }
    for(int x : res){
        cout << x << " ";
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
