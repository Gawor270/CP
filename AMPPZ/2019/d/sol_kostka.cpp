#include "bits/stdc++.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
	  int n;
	  cin >> n;
	  vector <int> a(n), b(n);
	  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
	  vector <pair <int, int> > E;
	  for(int i=0; i<n; i++) {
		int st = max(0, i-a[i]), en = min(n-1, i+a[i]);
		E.emplace_back(st, -b[i]);
		E.emplace_back(en, b[i]);
	  }
	  sort(E.begin(), E.end());
	  multiset <int> M;
	  int res = 0;
	  for(auto e : E) {
		if(e.second < 0) {
		  M.insert(-e.second);
		} else {
		  M.erase(M.find(e.second));
		}
		if(M.size() < 3) continue;
		int ttt = 0;
		auto it = M.end();
		for(int i=0; i<3; i++) ttt += *(--it);
		res = max(res, ttt);
	  }
	  cout << res << "\n";
  }
}
