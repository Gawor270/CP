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

bool check(vector<ll>& a, int b, int e){
    ll val = a[b] + a[e];
    bool ok = true;
    ll n = e - b +1;
    for(int i=0; i<n/2; i++){
        if(a[b + i] + a[e-i] != val){
            ok = false;
            break;
        }
    }
    return ok;
}

void solve() {
    int N;
    cin >> N;
    vector<ll> A(2*N+1);
    ll sum = 0;
    for(int i=1; i<2*N; i++){cin >> A[i]; sum += A[i];}
    if(N == 1){
        cout << 1 << "\n";
        return;
    }
    sort(A.begin() + 1, A.end() -1);

    ll s1 = A[1] + A[2*N-1];
    ll s2 = A[1] + A[2*N-2];
    ll s3 = A[2] + A[2*N-1];

    A[0] = s2 - A[2*N-1];
    A[2*N] = s3 - A[1];
    if(A[0] > 0 && check(A,0,2*N-1)){
        cout << A[0] << "\n";
        return;
    }
    ll ans1 = -1;
    if(check(A,1,2*N))ans1 = A[2*N];
    ll ans = -1;
    for(int i=0; i<N; i++){
        if(i == N-1){
            cout << s1 - A[1+i] << "\n";
            return;
        }
        if(A[1 + i] + A[2*N-1-i] > s1){
            ans = s1 - A[2*N-1-i];
            A.insert(A.begin() + i+1, s1 - A[2*N -1 -i]);
            break;
        }
        if(A[1+i] + A[2*N-1-i] < s1){
            ans = s1 - A[1+i];
            A.insert(A.begin() + (2*N-i), s1 - A[1+i]);
            break;
        }
    }
    if(check(A,1,2*N)){
        cout << ans << "\n";
    }else{
        cout << ans1 << "\n";
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
