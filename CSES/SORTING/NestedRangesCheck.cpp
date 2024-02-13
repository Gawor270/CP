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


typedef struct range{
    int x,y,ind;
    bool operator<(const range& other){
        if(other.x == x){
            return y > other.y;
        } 
        return x < other.x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<bool> res1(n,0),res2(n,0);
    for(int i=0; i<n; i++){
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].ind = i;
    }
    sort(all(ranges));
    int maxim = ranges[0].y;
    deque<range> dq = {ranges[0]};
    for(int i=1; i<n; i++){
        while(dq.size() && dq.front().x > ranges[i].x)dq.pop_front();
        while(dq.size() && dq.back().y >= ranges[i].y){
            res1[dq.back().ind] = true;
            dq.pop_back();
        }
        if(maxim >= ranges[i].y){
            res2[ranges[i].ind] = true;
        }

        if(ranges[i-1].x <= ranges[i].x && ranges[i-1].y >= ranges[i].y){
            res1[ranges[i-1].ind] = true;
        }
        else{
            dq.push_back(ranges[i-1]);
        }

        maxim = max(maxim,ranges[i].y);
    }
    for(int i=0; i<n; i++)cout << (int)res1[i] << " ";
    cout << "\n";
    for(int i=0; i<n; i++)cout << (int)res2[i] << " ";


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
