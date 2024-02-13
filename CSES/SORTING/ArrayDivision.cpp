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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int a[MAX_N];
int n,k;

bool check(ll thre){
    ll sum = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i]>thre)return false;
        if(sum + a[i] > thre){
            count++;
            sum = a[i];
        }
        else{
            sum += a[i];
        }
    }
    if(sum)count++;
    return count <= k;
}

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++)cin >> a[i];
    ll l = -1;
    ll r = 1e18;
    while(r - l > 1){
        ll m = l + (r-l)/2;
        if(check(m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r << "\n";
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
