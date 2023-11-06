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

vector<int> manacher_odd(vector<ll> & s, int x) {
    int n = s.size();
    vector<int> p(n);
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    vector<int> res;
    for(int i=0; i<n; i++){
        if(p[i] == x){
            res.push_back(i - p[i]/2);
        }
    }
    return res;
}

std::vector<int> findPalindromesOfLengthX(vector<ll> &s, int x) {
    vector<ll> modified(2*s.size() + 1);
    int m = s. size();
    for(int i=0; i<m; i++){
        modified[2*i] = -1;
        modified[2*i +1] = s[i];
    }
    modified[2*s.size()] = -1;

    return manacher_odd(modified,2*x +3);

}



void solve() {
    int n;
    cin >> n;
    vector<ll> resstring(4*n);
    vector<ll> a(n),b(n);
    map<ll, int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        resstring[i] = a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        resstring[i+n] = b[i];
    }
    for(int i=0; i<n; i++){
        resstring[2*n + i] = a[i];
        resstring[3*n + i] = b[i];
    }

    vector res = findPalindromesOfLengthX(resstring, 2*n);
    for(int x : res )cout << x  << " ";
    cout << "\n"; 
    // int diff = 0;
    // for(auto p : mp){
    //     if(p.second != 0)diff++;
    // }

    // int start = 0;
    // bool flag = true;
    // for(int i=n; i<4*n; i++){
    //     if(diff == 0 ){
    //         flag = false;
    //         break;
    //     }
    //     else{
    //         a[i] = b[i-n];
    //         b[i] = a[i-n];
    //         mp[a[i-n]] -= 2;
    //         mp[b[i-n]] += 2;
    //         if(mp[a[i-n]] == -2)diff++;
    //         if(mp[b[i-n]] == 2)diff++;
    //         if(mp[a[i-n]] == 0)diff--;
    //         if(mp[b[i-n]] == 0)diff--;
    //         if(diff == 0){
    //             flag = false;
    //             start = i-n+1;
    //             break;
    //         }
    //     }
    // }

    // if(flag){
    //     cout << -1 << "\n";
    //     return;
    // }


    // for(int i=0; i<n; i++){
    //     if(i < n/2){
    //         if(a[start+i] >= b[start+i] || a[start+i] != b[start +n-1-i]){
    //             cout << -1 << "\n";
    //             return;
    //         }
    //     }
    //     else if(i >= (n+1)/2){
    //         if(a[start+i] <= b[start+i] || a[start+i] != b[start +n-1-i]){
    //             cout << -1 << "\n";
    //             return;
    //         }
    //     }
    //     else{
    //         if(a[start +i] != b[start + n -1]){
    //             cout << -1 << "\n";
    //             return;
    //         }
    //     }
    // }
    // cout << start << "\n";
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
