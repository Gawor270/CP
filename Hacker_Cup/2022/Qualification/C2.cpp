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

const int MAX_N = 2*(1<<10+1);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
bool tree[MAX_N];

string s = "";
int N;

void dfs1(int u){
    if(u >= MAX_N)return;
    tree[u] = true;
    dfs1(2*u + 1);
    dfs1(2*u + 2);
}

void dfs2(int u){
    if(s.length() == 10){
        if(!tree[(u-1)/2] && N){
            cout << s << "\n";
            N--;
        }
        return;
    }
    s = s + '-';
    dfs2(2*u +1);
    s.pop_back();
    s = s + '.';
    dfs2(2*u +2);
    s.pop_back();
}

void solve() {
    memset(tree,false,MAX_N*sizeof(bool));
    cin >> N;
    N--;
    string C1;
    cin >> C1;
    int u = 0;
    for(char c : C1){
        u = 2*u + 1;
        if(c - '-')u++;
        if(u >= MAX_N)break;
        tree[u] = true;
    }
    dfs1(u);
    dfs2(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
}
