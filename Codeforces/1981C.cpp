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

int a[MAX_N];

pair<uint32_t,int> lca(uint32_t a, uint32_t b) {
    
    int count = 0;
    uint32_t aLeadingZeroes = __builtin_clz(a);
    uint32_t bLeadingZeroes = __builtin_clz(b);
    
    while (aLeadingZeroes > bLeadingZeroes) {
        b >>= 1u;
        bLeadingZeroes++;
        count++;
    }
    
    while (bLeadingZeroes > aLeadingZeroes) {
        a >>= 1u;
        aLeadingZeroes++;
        count++;
    }
    
    while (a != b) {
        a >>= 1u;
        b >>= 1u;
        count += 2;
    }
    
    return {a,count};
}

void solve() {
    int n;
    cin >> n;
    deque<int> path;
    vi sp;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] != -1)sp.push_back(i);
    }

    if (sp.size() == 0) {
        for (int i=0; i<n; i++) {
            cout << (i%2 ? 1 : 2) << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=0; i<sp[0]; i++) {
        int add = (i%2 == 0 ? 2*a[sp[0]] : a[sp[0]]);
        path.push_front(add);
    }

    for (int i=0; i<sp.size()-1; i++) {
        int length = sp[i+1] - sp[i] - 1;
        int l = min(a[sp[i]], a[sp[i+1]]);
        int r = max(a[sp[i]], a[sp[i+1]]);
        bool rev = (a[sp[i]] > a[sp[i+1]]);

        auto [lcaa, cnt] = lca(l,r);

        deque<int> tmpres;

        if (cnt -1 > length || (length - cnt)%2 == 0) {
            cout << -1 << "\n";
            return;
        }

        while(l != lcaa) {
            tmpres.push_back(l);
            l >>= 1;
        }
        tmpres.push_back(lcaa);


        deque<int> tmp;
        while(r != lcaa) {
            tmp.push_front(r);
            r >>= 1;
        }

        tmpres.insert(tmpres.end(), tmp.begin(), tmp.end());

        int last = tmpres.back();

        for (int j = 0; j<= length-cnt; j++) {
            int add = (j%2 == 0 ? last*2 : last);
            tmpres.push_back(add);
        }

        if (rev)reverse(all(tmpres));
        tmpres.pop_back();
        path.insert(path.end(), tmpres.begin(), tmpres.end());
    }

    path.push_back(a[sp.back()]);

    int last = path.back();
    for (int i = 0; i< n - sp.back()-1; i++){
        int add = (i%2 ==0 ? last*2 : last);
        path.push_back(add);
    }

    for (int x : path)cout << x << " ";
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
