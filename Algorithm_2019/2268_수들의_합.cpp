#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		++n;
		seq.resize(n);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
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
		if (s == e) {
			tree[node] = u;
			return;
		}
		update(node * 2, s, (s + e) / 2, i, u);
		update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	Segment s(n);
	s.init(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a)
			s.update(1, 1, n, b, c);
		else {
			if (b > c) swap(b, c);
			printf("%lld\n", s.query(1, 1, n, b, c));
		}
	}
}