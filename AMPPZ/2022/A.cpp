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


vector<string> firstname;
vector<string> lastname;

int ispos(int a, int b){
    map<string,int> count;
    int maxim = 0;
    for(int i=0; i<firstname.size(); i++){
        int l1 = firstname[i].length();
        int l2 = lastname[i].length();
        string res = firstname[i].substr(0,min(l1,a)) + lastname[i].substr(0,min(l2,b));
        count[res]++;
        maxim = max(maxim,count[res]);
    }
    int c = ceil(log10(maxim)); 
    return c;

}

void solve() {
    int n;
    cin >> n;
    firstname.resize(n), lastname.resize(n);
    int maxf =0, maxl = 0;
    for(int i=0; i<n; i++){
        cin >> firstname[i] >> lastname[i];
        maxf = max((int)firstname[i].length(), maxf);
        maxl = max((int)lastname[i].length(), maxl);
    }

    int a = 0,b = 0,c = 6;
    int minim = 6;
    for(int i=0; i<=6; i++){
        for(int j=0; j<=6; j++){
                int k = ispos(i,j);
                if((i || j || k) && i + j + k < minim){
                    minim = i + j + k;
                    a = i, b= j, c = k;
                }
        }
    }

    cout << a << " " << b << " " << c << "\n";
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
