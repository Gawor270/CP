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

struct state {
    int day, s, ind;
    bool operator<(const state& other){
        if(day == other.day){
            return s < other.s;
        }
        return day < other.day;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<state> customers(2*n);
    vi room(n,-1);
    for(int i=0; i<n; i++){
        cin >> customers[2*i].day;
        cin >> customers[2*i+1].day;
        customers[2*i].s = -1;
        customers[2*i+1].s = 1;
        customers[2*i].ind = customers[2*i+1].ind = i;
    }
    sort(all(customers));
    vi rooms;
    int k = 0;
    for(state p : customers){
        if(p.s == 1){
            rooms.push_back(room[p.ind]);
        }
        else{
            if(rooms.size()){
                room[p.ind] = rooms.back();
                rooms.pop_back();
            }
            else{
                room[p.ind] = ++k;
            }
        }
    }
    cout << k << "\n";
    for(int x : room)cout << x << " ";
    cout << "\n";
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
