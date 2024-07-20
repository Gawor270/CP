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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
map<int,set<int>> mp;

void trial_division3(long long n, vector<ll>& factorization, int j) {
    for (int d : {2, 3, 5}) {
        if (n % d == 0) {
            factorization.push_back(d);
            mp[d].insert(j);
            while(n % d == 0)n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        if (n % d == 0) {
            factorization.push_back(d);
            mp[d].insert(j);
            while(n % d == 0)n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        mp[n].insert(j);
        factorization.push_back(n);
}

void solve() {
    int n, s, t;
    cin >> n;
    vi a(n);
    for(auto&x : a)cin >> x;
    cin >> s >> t;
    --s, --t;
    vector<vector<ll>> factorizations(n);
    for(int i=0; i<n; i++){
        trial_division3(a[i], factorizations[i], i);
    }

    queue<int> q;
    q.push(s);
    vi parent(n,-1);
    while(!q.empty()){
        int curr = q.front();
        if (curr == t){
            vi path;
            while(t != s){
                path.push_back(t+1);
                t = parent[t];
            }
            path.push_back(s+1);
            reverse(all(path));
            cout << path.size() << "\n";
            for(int x : path)cout << x << " ";
            return;
        }
        q.pop();
        vector<ll> currfactors = factorizations[curr];
        for (int factor : currfactors){
            for (auto iter = mp[factor].begin(); iter != mp[factor].end(); iter++){
                parent[*iter] = curr;
                q.push(*iter);
            }

            for (auto iter = mp[factor].begin(); iter != mp[factor].end(); iter++){
                for (int x : factorizations[*iter]){
                    if(x == factor)continue;
                    mp[x].erase(*iter);
                }
            }
            mp[factor].clear();
        }
    }
    cout << -1 << "\n";
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
