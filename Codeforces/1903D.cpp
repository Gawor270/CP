#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll unsigned long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll exp(int n){
    if(n ==0)return 1LL;
    return 2LL*exp(n-1);
}

void solve() {
    int n,q;
    cin >> n >> q;
    int lim = (int)log2(1e18/n) + 1;
    vector<ll> ap(n);
    for(auto& x : ap)cin >> x;
    vector<ll> distp(lim,0);
    for(int i=0; i<n; i++){
        ll below = ap[i];
        for(int j=lim-1; j>=0; j--){
            if(ap[i] & exp(j)){
                below -= exp(j);
            }
            else{
                distp[j] += (exp(j) - below);
            }

        }
    }


    while(q--){
        ll k;
        ll res = 0;
        cin >> k;
        vector<ll> dist = distp;
        vector<ll> a = ap;
        for(int i=lim-1; i>=0; i--){
            if(dist[i] <= k){
                k -= dist[i];
                res += exp(i);
                for(int j=0; j<n; j++){
                    if(!(a[j] & exp(i))){
                        a[j] += exp(i);
                        ll below = 0;
                        for(int h=0; h<i; h++){
                            if(a[j] & exp(h)){
                                a[j] -= exp(h);
                                dist[h] += exp(h);
                                below += exp(h);
                            }
                            else{
                                dist[h] += below;
                            }
                        }
                    }
                }

            }
        }
        cout << res << "\n";
    }
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
