#include "bits/stdc++.h"
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using Tree = tree <T,  null_type,  less_equal<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie( nullptr);

    int n, m, a, ans = 0;
    cin >> n >> m;
    vector<int> D(n);
    Tree<int> T;
    for(int i = 0 ; i < n ; ++i) cin >> D[i];
    for(int i = 0 ; i < m ; ++i) {
        cin >> a; T.insert(a);
    }
    sort(D.begin(), D.end(), greater<>());
    for(const auto& d : D) {
        auto it = T.find_by_order(T.order_of_key(d*5));
        if(it == T.end()) {
            it = T.find_by_order(T.order_of_key(d*3));
            if(it == T.end()) {
                cout << "NIE\n"; return 0;
            }
            T.erase(it);
            it = T.find_by_order(T.order_of_key(d*2));
            if(it == T.end()) {
                cout << "NIE\n"; return 0;
            }
            T.erase(it);
            ans++; ans++;
        } else {
            T.erase(it);
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
