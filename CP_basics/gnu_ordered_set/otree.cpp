#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

using namespace __gnu_pbds;
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

#define ordered_set tree<int64_t , null_type , less_equal<int64_t>, rb_tree_tag , \
tree_order_statistics_node_update>

int main ( ) {
    ordered_set S;
    S.insert(1);
    S.insert(5);
    S.insert(3);
    S.insert(-1);
    for(int i=0; i<size(S); i++){
        cout << *S.find_by_order(i) << "\n";
    }
    S.erase(S.lower_bound(-2));
    for(int i=0; i<size(S); i++){
        cout << *S.find_by_order(i) << "\n";
    }

}
