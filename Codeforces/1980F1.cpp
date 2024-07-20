#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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
    ll n, m, k, alpha, last_height;
    cin >> n >> m >> k;
    vector<tuple<ll,ll,ll>> fountains(k);
    vi res(k+1, 0);

    for (ll i=0; i<k; i++) {
        ll r,c;
        cin >> r >> c;
        fountains[i] = {r,c,i};
    }
    fountains.push_back({-1,0,-1});
    fountains.push_back({n,m+1,k});
    fountains.push_back({n,m+2,k});

    sort(all(fountains), [](const tuple<ll,ll,ll>& a, const tuple<ll,ll,ll>& b) {
        if (get<1>(a) == get<1>(b)) {
            return get<0>(a) > get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    });

    last_height = (ll)n;
    alpha = 0LL;
    int j = 1;
    while (j <= k+1){
        int curr_col = get<1>(fountains[j]);
        alpha += (curr_col - get<1>(fountains[j-1]) - 1)*last_height;
        ll curr_height = min(last_height,n - get<0>(fountains[j]));
        ll poss_height = last_height;
        if (get<1>(fountains[j+1]) == curr_col)
            poss_height = min(poss_height, n - get<0>(fountains[j+1]));

        alpha += curr_height;
        last_height = curr_height;
        int currind = j;
        while(j <= k+1 && curr_col == get<1>(fountains[j]))j++;
        res[get<2>(fountains[currind])] = (poss_height - curr_height)*( get<1>(fountains[j]) - curr_col);
    }

    tuple<ll,ll,ll> minim = *min_element(fountains.begin(), fountains.end()-2, [](tuple<ll,ll,ll> a, tuple<ll,ll,ll> b) {
        if (get<0>(a) == get<0>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<0>(a) > get<0>(b);
    });
    fountains.erase(find(all(fountains), minim));

    last_height = (ll)n;
    ll new_alpha = 0LL;
    j = 1;
    while (j <= k){
        int curr_col = get<1>(fountains[j]);
        new_alpha += (curr_col - get<1>(fountains[j-1]) - 1)*last_height;
        ll curr_height = min(last_height,n - get<0>(fountains[j]));
        ll poss_height = last_height;
        if (get<1>(fountains[j+1]) == curr_col)
            poss_height = min(poss_height, n - get<0>(fountains[j+1]));

        new_alpha += curr_height;
        last_height = curr_height;
        int currind = j;
        while(j <= k && curr_col == get<1>(fountains[j]))j++;
    }

    res[get<2>(minim)] = new_alpha - alpha;


    cout << alpha << "\n";
    for (int i=0; i<k; i++)cout << res[i] << " ";
    cout << "\n";

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
