#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> P;

struct Segment {
	vector<int> tree;
	vector<P> range;
	vector<int> seq;
	Segment(int n) {
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e)
			tree[node] = seq[s];
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		}
	}

	int query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return -1;
		if (i <= s && e <= j) return tree[node];
		int res1 = query(node * 2, s, (s + e) / 2, i, j);
		int res2 = query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
		if (res1 == -1)
			return res2;
		else if (res2 == -1)
			return res1;
		else
			return min(res1, res2);
	}
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Segment s(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s.seq[i]);

	s.init(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", s.query(1, 0, n - 1, a - 1, b - 1));
	}

}