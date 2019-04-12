#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t + 1);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	Segment seg(n);
	for (int i = 0; i < n; ++i) {
		seg.seq[i] = 1;
		for (int j = 0; j < 4; ++j) 
			seg.seq[i] *= seq[i + j >= n ? (i + j) - n : i + j];
	}
	seg.init(1, 0, n - 1);
	for (int i = 0; i < k; ++i) {
		int a; scanf("%d", &a); --a;
		for (int j = 0; j < 4; ++j) {
			int idx = a - j >= 0 ? a - j : a - j + n;
			ll & ref = seg.seq[idx];
			ref *= -1;
			seg.update(1, 0, n - 1, idx, ref * 2);
		}
		printf("%d\n", seg.tree[1]);
	}
}