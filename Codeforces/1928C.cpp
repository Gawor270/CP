#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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


unordered_set<int> divisors(int num){
    unordered_set<int> pos;
    for(int i=1; i*i <= num; i++){
        if(num%i == 0){
            if((num/i)%2 ==0){
                pos.insert(num/i);
            }
            if(i%2 == 0){
                pos.insert(i);
            }
        }
    }
    unordered_set<int> ans;
    for(int div: pos)ans.insert(1+div/2);
    return ans;
}

void solve() {
    int n,x;
    cin >> n >> x;
    unordered_set<int> candidates = divisors(n-x);
    for(int div : divisors(n+x-2))candidates.insert(div);

    int res = 0;
    for(int div : candidates)res += (div >= x);
    cout << res << "\n";
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
