#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct Segment {
	vector<int> tree;
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
			tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
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
	int update(int node, int s, int e, int i, int u) {
		if (i < s || i > e) return tree[node];
		if (i == s && i == e) return tree[node] = u;;
		int res1 = update(node * 2, s, (s + e) / 2, i, u);
		int res2 = update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		if (res1 == -1)
			return tree[node] = res2;
		else if (res2 == -1)
			return tree[node] = res1;
		else
			return tree[node] = gcd(res1, res2);
	}
};

int main() {
	int n;	scanf("%d", &n);
	Segment s(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s.seq[i]);

	s.init(1, 0, n - 1);
	int ans = 0, ansi = 0;
	for (int i = 0; i < n; ++i) {
		s.update(1, 0, n - 1, i, -1);
		if (s.seq[i] % s.tree[1] && ans < s.tree[1]) {
			ans = s.tree[1];
			ansi = i;
		}
		s.update(1, 0, n - 1, i, s.seq[i]);
	}
	printf("%d %d", ans, s.seq[ansi]);
}