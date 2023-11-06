// zaby, Kamil
// O(n * log(n)), AC, alternative slow solution with a segment tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
	multiset<int> three;
	void add(int x) {
		three.insert(x);
		if((int) three.size() == 4) {
			three.erase(three.begin());
		}
	}
};

void test_case() {
	int n;
	scanf("%d", &n);
	int B = 1;
	while(B < n) {
		B *= 2;
	}
	vector<Node> tree(2 * B);
	for(int i = 0; i < n; ++i) {
		int range, skill;
		scanf("%d%d", &range, &skill);
		int L = max(0, i - range) + B;
		int R = min(n - 1, i + range) + B;
		tree[L].add(skill);
		if(L != R) {
			tree[R].add(skill);
		}
		while(L + 1 < R) {
			if(L % 2 == 0) {
				tree[L+1].add(skill);
			}
			if(R % 2 == 1) {
				tree[R-1].add(skill);
			}
			L /= 2;
			R /= 2;
		}
	}
	long long answer = 0;
	for(int where = 0; where < n; ++where) {
		Node node;
		for(int i = B + where; i >= 1; i /= 2) {
			for(int x : tree[i].three) {
				node.add(x);
			}
		}
		if(node.three.size() == 3) {
			long long sum = 0;
			for(int x : node.three) {
				sum += x;
			}
			answer = max(answer, sum);
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
