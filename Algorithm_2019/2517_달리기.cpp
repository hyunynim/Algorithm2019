#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n + 1));
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
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	priority_queue<int> q;
	unordered_map<int, int> comp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		q.push(-seq[i]);
	}
	int i = 0;
	while (q.size()) {
		int cur = q.top(); q.pop();
		comp[-cur] = i++;
	}
	Segment s(n);
	s.init(1, 1, n);
	for (int i = 0; i < n; ++i) {
		printf("%lld\n", s.query(1, 1, n, comp[seq[i]], n) + 1);
		s.update(1, 1, n, comp[seq[i]], 1);
	}
}
