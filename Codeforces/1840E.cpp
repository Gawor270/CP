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



void solve() {
    int t,q,eq,size,n,pos,mode,ind;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    n = (int)s[0].size();

    eq = 0;
    size = n;
    for(int i=0; i<n; i++){
        if(s[0][i] == s[1][i])eq++;
    }

    cin >> t >> q;
    vector<pair<int,int>> add(q);
    for(int i=0; i<q; i++)add[i] = {0,0};
    for(int i=0; i<q; i++){
        cin >> mode;
        size += add[i].first;
        eq += add[i].second;
        if(mode == 1){
            cin >> pos;
            --pos;
            eq -= (s[0][pos] == s[1][pos]);
            size--;
            ind = i + t ;
            if(ind < q){
                add[ind] = {1, (s[0][pos] == s[1][pos])};
            }
        }
        if(mode == 2){
            int num1, pos1, num2, pos2;
            cin >> num1 >> pos1 >> num2 >> pos2;
            --num1; --pos1; --num2; --pos2;
            if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                eq++;
            }
            if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                eq++;
            }
            swap(s[num1][pos1], s[num2][pos2]);
            if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                eq--;
            }
            if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                eq--;
            }
        }
        if(mode == 3){
            cout << ((size == eq ? "YES" : "NO")) << "\n";
        }
    }
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
