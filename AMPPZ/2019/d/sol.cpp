// zaby, Kamil
// O(n * log(n)), AC
#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> add(n), rem(n);
	for(int i = 0; i < n; ++i) {
		int range, skill;
		scanf("%d%d", &range, &skill);
		add[max(0, i - range)].push_back(skill);
		rem[min(n - 1, i + range)].push_back(skill);
	}
	long long answer = -1;
	multiset<int> current;
	for(int where = 0; where < n; ++where) {
		for(int x : add[where]) {
			current.insert(x);
		}
		if((int) current.size() >= 3) {
			long long sum = 0;
			auto it = current.end();
			for(int rep = 0; rep < 3; ++rep) {
				sum += *(--it);
			}
			answer = max(answer, sum);
		}
		for(int x : rem[where]) {
			current.erase(current.find(x));
		}
	}
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
