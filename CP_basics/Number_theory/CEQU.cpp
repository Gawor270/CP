#include <bits/stdc++.h>
//https://www.spoj.com/problems/CEQU/
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


int main() {
    int q,a,b,c;
    cin >> q; 
    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c;
        int g = __gcd(a,b); 

        if(c % g)
            cout<<"Case "<<i<<": No"<<endl; 
        else 
            cout<<"Case "<<i<<": Yes"<<endl; 
    }
}
