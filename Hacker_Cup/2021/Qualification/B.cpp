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



void solve() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for(int i=0; i<N; i++)cin >> grid[i];
    
    vector<set<int>> fnd(N+1);
    for(int i=0; i<N; i++){
        int count1= 0;
        int count2 = 0;
        stack<pi> vs1, vs2;
        for(int j=0; j<N; j++){
            if(grid[i][j] == 'O')count1 = -(N+1);
            if(grid[j][i] == 'O')count2 = -(N+1);
            if(grid[i][j] == '.'){
                count1++;
                vs1.push({i,j});
            }
            if(grid[j][i] == '.'){
                count2++;
                vs2.push({j,i});
            }
        }
        int setv;
        if(count1 > 0){
            setv = 0;
            while(!vs1.empty()){
                if(N&1 && i == N/2 && vs1.top().first != vs1.top().second)setv -= vs1.top().first +349*vs1.top().second;
                else setv += vs1.top().first +349*vs1.top().second;
                vs1.pop();
            }
            fnd[count1].insert(setv);
        }
        if(count2 > 0){
            setv = 0;
            while(!vs2.empty()){
                setv += vs2.top().first +349*vs2.top().second;
                vs2.pop();
            }
            fnd[count2].insert(setv);

        }
    }

    for(int i=1; i<=N; i++){
        if(fnd[i].size()){
            cout << i << " " << fnd[i].size() << "\n";
            return;
        }
    }
    cout << "Impossible" << "\n";
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
