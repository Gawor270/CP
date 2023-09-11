#include <bits/stdc++.h>
#include <iostream>

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
    int n,m;
    cin >> n >> m;

    vector a(n,vector<int>(m,0));
    vector<int> sum(n,0);
    int counter =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int inp;
            cin >> inp;
            a[i][j] = inp;
            if(inp){
                sum[i]++;
                counter++;
            }
        }
    }

    if(counter%n){
        cout << -1 << "\n";
        return;
    }

    int req = counter/n;

    vector<vector<int>> res;
    for(int pos = 0; pos<m; pos++){
        stack<int> s;
        stack<int> b;
        for(int arr = 0; arr<n; arr++){
            if(sum[arr] < req && !a[arr][pos])s.push(arr);
            if(sum[arr] > req && a[arr][pos])b.push(arr);
        }
        while(!s.empty() && !b.empty()){
            res.push_back({s.top()+1,b.top()+1,pos+1});
            sum[s.top()]++;
            sum[b.top()]--;
            s.pop();
            b.pop();
        }
        while(!s.empty())s.pop();
        while(!b.empty())b.pop();
    }

    cout << res.size() << "\n";
    for(int i=0; i<(int)res.size(); i++){
        for(int j=0; j<3; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
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
