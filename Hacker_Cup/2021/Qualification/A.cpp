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

char vowels[] = {'A','E','I','O','U'};
vector<bool> isvow(26,false);

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1e9;
    vector dist(26,vector<int>(26,1e9));
    for(int i=0; i<26; i++)dist[i][i] = 0;
    int k;
    cin >> k;
    while(k--){
        char s,t;
        cin >> s >> t;
        dist[s-'A'][t-'A'] = 1;
    }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++) 
            for (int j = 0; j < 26; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int j=0; j<26; j++){
        int count = 0;
        for(int i=0; i<n; i++){
            if(j != s[i] - 'A'){
                if(dist[s[i] - 'A'][j] < 1e9 )count += dist[s[i] - 'A'][j];
                else{
                    count = 1e9+1;
                    break;
                }
            }
        }
        ans = min(ans, count);
    }
    cout << (ans < 1e9 ? ans : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(char c : vowels){
        isvow[c - 'A'] = true;
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
