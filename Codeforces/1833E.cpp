#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
//https://codeforces.com/contest/1833/problem/E
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve(int size) {
    vector<set<int>> g(size); // graph contains sets cause different neighbours possibly remember each other
    vector<int> a(size);
    vector<int> d(size);
    for(int i=0; i<size; i++){
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }

    for(int i=0; i<size; i++){
        d[i] = g[i].size();
    }

    int bamboos = 0; int cycles =0;
    vector<bool> vis(size,false);
    for(int v=0; v<size; v++){
        if(!vis[v]){

            queue<int>Q;
            Q.push(v);
            vis[v] = true;

            vector<int> component = {v};
            while(!Q.empty()){
                int u = Q.front(); Q.pop();

                for(int s: g[u]){
                    if(!vis[s]){
                        vis[s]= true;
                        component.push_back(s);
                        Q.push(s);
                    }
                }
            }

            bool bamboo = false;
            for(int j: component){
                if(d[j] == 1){
                    bamboo = true;
                    break;
                }
            }
            
            if(bamboo) bamboos++;
            else cycles++;
        }

    }

    cout << cycles + min(bamboos,1) << " " << cycles + bamboos << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n;
    vector<int>::iterator iter;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        solve(n);
    }
}