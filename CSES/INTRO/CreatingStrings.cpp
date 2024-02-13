#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ll long long
#define ld long double

#define REP(i,n) for(int i=0;i<(n);++i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define SIZE(c) ((int)((c).size()))
#define ALL(u) (u).begin(),(u).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


map <char,int> cnt;
string s;

int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

void generate(int i = 0, string ans = ""){
    if(i == s.size()){
        cout << ans << "\n";
        return;
    }
    for(auto p : cnt){
        if(p.second == 0)continue;
        cnt[p.first]--;
        generate(i+1, ans+p.first);
        cnt[p.first]++;
    }


}

void solve() {
    cin >> s;
    for(char c : s)cnt[c]++;
    int res = fact(s.size());
    for(auto p : cnt)res /= fact(p.second);
    cout << res  << "\n";
    generate();
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
