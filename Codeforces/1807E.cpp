#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

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


void askrange(int a, int b){
    printf("? %d ", (b-a+1));
    for(int i=a; i<=b; i++){
        printf("%d ", (i+1));
    }
    printf("\n");
    fflush(stdout);
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vector<int> prefsum(n+1);
    prefsum[0] = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        prefsum[i+1] = prefsum[i] + a[i];
    }
    int lb = 0;
    int ub = n;
    while(lb < ub){
        int mb = (lb + ub)/2;
        askrange(lb,mb);
        int sum;
        scanf("%d",&sum);
        int countstones = (prefsum[mb+1] - prefsum[lb]);
        if(sum == (prefsum[mb+1] - prefsum[lb])){
            lb = mb+1;
        } else {
            ub = mb;
        }
    }
    printf("! %d\n", (lb+1));
    fflush(stdout);
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
