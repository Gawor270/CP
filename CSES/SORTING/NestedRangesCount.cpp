#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

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

struct range{
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
    vector<int> res1(n,0),res2(n,0);
    for(int i=0; i<n; i++){
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].ind = i;
    }
    sort(all(ranges));
    ordered_multiset s1,s2;
    s1.insert(ranges[0].y);
    s2.insert(ranges[n-1].y);
    for(int i=1; i<n; i++){
        res1[ranges[n-1-i].ind] += s2.order_of_key(ranges[n-1-i].y+1);
        s2.insert(ranges[n-1-i].y);
        res2[ranges[i].ind] += s1.size() - s1.order_of_key(ranges[i].y);
        s1.insert(ranges[i].y);
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

