#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
struct LazySeg {
	vector<ll> seq;
	vector<ll> tree;
	vector<ll> lazy;
	LazySeg(int n) {
		++n;
		seq.resize(n);
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1)) - 1;
		tree.resize(tree_size);
		lazy.resize(tree_size);
	}
	ll init(int node, int start, int end) {
		if (start == end) {
			return tree[node] = seq[start];
		}
		else {
			return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
		}
	}
	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1)*lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void update_range(int node, int start, int end, int left, int right, ll diff) {
		update_lazy(node, start, end);
		if (left > end || right < start) {
			return;
		}
		if (left <= start && end <= right) {
			tree[node] += (end - start + 1)*diff;
			if (start != end) {
				lazy[node * 2] += diff;
				lazy[node * 2 + 1] += diff;
			}
			return;
		}
		update_range(node * 2, start, (start + end) / 2, left, right, diff);
		update_range(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll sum(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[node];
		}
		return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
};
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	LazySeg seg(n);
	m += k;
	for (int i = 0; i < n; i++) 
		scanf("%lld", &seg.seq[i]);
	
	seg.init(1, 0, n - 1);
	while (m--) {
		int t1, t2, t3;
		scanf("%d", &t1);
		if (t1 == 2) {
			int s, e;
			ll v;
			scanf("%d %d %lld", &s, &e, &v);
			seg.update_range(1, 0, n - 1, s - 1, e - 1, v);
		}
		else if (t1 == 1) {
			int s, e;
			scanf("%d %d", &s, &e);
			printf("%lld\n", seg.sum(1, 0, n - 1, s - 1, e - 1));
		}
	}
	return 0;
}