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



void solve() {
        ll n,k,w;
        cin >> n >> k >> w;
        vector<ll> L(n);
        for(int i=0; i<k; i++)cin >> L[i];
        ll Al,Bl,Cl,Dl;
        cin >> Al >> Bl >> Cl >> Dl;
        vector<ll> H(n);
        for(int i=0; i<k; i++)cin >> H[i];
        ll Ah,Bh,Ch,Dh;
        cin >> Ah  >> Bh >> Ch >> Dh;
        for(int i=k; i<n; i++){
            L[i] = (((Al)*L[i-2]%Dl + Bl*L[i-1]%Dl + Cl)%Dl + 1)%MOD;
            H[i] = (((Ah)*H[i-2]%Dh + Bh*H[i-1]%Dh + Ch)%Dh + 1)%MOD;
        }
        ll P = (2*w + 2*H[0])%MOD;
        ll ans = P;
        for(int i=1; i<n; i++){
            if(L[i-1] + w >= L[i]){
                P = (P + (2*(L[i] - L[i-1]))%MOD);
                ll h = i-1 ? H[i-1] : H[i];
                for(int j =i-1; j>=max(0,i-(int)w); j--){
                    if(L[j] + w >= L[i]){
                        h = max(h,H[j]);
                    }
                }
                if(H[i] > h){
                    P = (P + 2*(H[i] - h))%MOD;
                }
            }
            else if(L[i] > L[i-1] + w){
                P = (P + 2*(w + H[i])%MOD);
            }
            else{
                ll h = i-1 ? H[i-1] : H[i];
                for(int j =i-1; j>=max(0,i-(int)w); j--){
                    if(L[j] + w >= L[i]){
                        h = max(h,H[j]);
                    }
                }
                if(H[i] > h){
                    P = (P + 2*(H[i] - h))%MOD;
                }
 
            }
            ans = (ans * P)%MOD;
        } 
        cout << ans << "\n";
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
